#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// #define MAX_DATA 512
// #define MAX_ROWS 100

struct Address
{
    int id;
    int set;
    char *name;
    char *email;
};

struct Database
{
    int MAX_DATA;
    int MAX_ROWS;
    struct Address *rows;
};

struct Connection
{
    FILE *file;
    struct Database *db;
};

void die(const char *message, struct Connection *conn)
{
    if (errno)
    {
        perror(message);
    }
    else
    {
        printf("ERROR: %s\n", message);
    }

    if (conn)
    {
        Database_close(conn); // 清理内存
    }

    exit(1);
}

void Address_print(struct Address *addr)
{
    printf("%d %s %s\n",
           addr->id, addr->name, addr->email);
}

void Database_load(struct Connection *conn)
{
    int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
    if (rc != 1)
        die("Failed to load database.", conn);
}

struct Connection *Database_open(const char *filename, char mode, int MAX_DATA, int MAX_ROWS)
{
    struct Connection *conn = malloc(sizeof(struct Connection));
    if (!conn)
        die("Memory error", conn);

    conn->db = malloc(sizeof(struct Database));
    if (!conn->db)
        die("Memory error", conn);

    conn->db->MAX_DATA = MAX_DATA;
    conn->db->MAX_ROWS = MAX_ROWS;
    conn->db->rows = malloc(sizeof(struct Address) * MAX_ROWS);
    for (int i = 0; i < MAX_ROWS; i++)
    {
        conn->db->rows[i].name = malloc(MAX_DATA);
        conn->db->rows[i].email = malloc(MAX_DATA);
    }

    if (mode == 'c')
    {
        conn->file = fopen(filename, "w");
    }
    else
    {
        conn->file = fopen(filename, "r+");

        if (conn->file)
        {
            Database_load(conn);
        }
    }

    if (!conn->file)
        die("Failed to open the file", conn);

    return conn;
}

void Database_close(struct Connection *conn)
{
    if (conn)
    {
        if (conn->file)
            fclose(conn->file);
        if (conn->db)
            free(conn->db);
        free(conn);
    }
}

void Database_write(struct Connection *conn)
{
    rewind(conn->file);

    int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
    if (rc != 1)
        die("Failed to write database.", conn);

    rc = fflush(conn->file);
    if (rc == -1)
        die("Cannot flush database.", conn);
}

void Database_create(struct Connection *conn)
{
    for (int i = 0; i < conn->db->MAX_ROWS; i++)
    {
        // make a prototype to initialize it
        struct Address addr = {.id = i, .set = 0};
        // then just assign it
        conn->db->rows[i] = addr;
    }
}

void Database_set(struct Connection *conn, int id, const char *name, const char *email)
{
    struct Address *addr = &conn->db->rows[id];
    if (addr->set)
        die("Already set, delete it first", conn);

    addr->set = 1;
    // WARNING: bug, read the "How To Break It" and fix this
    char *res = strncpy(addr->name, name, conn->db->MAX_DATA - 1);
    addr->name[conn->db->MAX_DATA - 1] = '\0';
    // demonstrate the strncpy bug
    if (!res)
        die("Name copy failed", conn);

    res = strncpy(addr->email, email, conn->db->MAX_DATA - 1);
    addr->email[conn->db->MAX_DATA - 1] = '\0';
    if (!res)
        die("Email copy failed", conn);
}

void Database_get(struct Connection *conn, int id)
{
    struct Address *addr = &conn->db->rows[id];

    if (addr->set)
    {
        Address_print(addr);
    }
    else
    {
        die("ID is not set", conn);
    }
}

void Database_delete(struct Connection *conn, int id)
{
    struct Address addr = {.id = id, .set = 0};
    conn->db->rows[id] = addr;
}

void Database_list(struct Connection *conn)
{
    int i = 0;
    struct Database *db = conn->db;

    for (i = 0; i < conn->db->MAX_ROWS; i++)
    {
        struct Address *cur = &db->rows[i];

        if (cur->set)
        {
            Address_print(cur);
        }
    }
}

void Database_find(struct Connection *conn, const char *search_term)
{
    for (int i = 0; i < conn->db->MAX_ROWS; i++)
    {
        struct Address *cur = &conn->db->rows[i];
        if ((cur->set) && (strcmp(cur->name, search_term) == 0 || strcmp(cur->email, search_term) == 0))
        {
            Address_print(cur);
            return;
        }
    }
    printf("Search term not found.\n");
}

int main(int argc, char *argv[])
{
    // 至少需要文件名和操作类型
    if (argc < 3)
        die("USAGE: ex17 <dbfile> <action> [action params]", NULL);

    char *filename = argv[1];
    char action = argv[2][0];
    struct Connection *conn = NULL;

    // 如果是创建操作，确保有足够的参数
    if (action == 'c')
    {
        if (argc != 5)
            die("USAGE: ex17 <dbfile> c <MAX_DATA> <MAX_ROWS>", NULL);

        int _MAX_DATA = atoi(argv[3]);
        int _MAX_ROWS = atoi(argv[4]);
        conn = Database_open(filename, action, _MAX_DATA, _MAX_ROWS);
        Database_create(conn);
        Database_write(conn);
    }
    else
    {
        // 对于其他操作，不需要MAX_DATA和MAX_ROWS，但需要检查数据库文件是否存在
        conn = Database_open(filename, action, 0, 0); // 0s表示这些值将被忽略
        if (!conn)
            die("Database not found. Use 'c' option to create one.", NULL);
    }

    if (argc > 3 && action != 'c')
    {
        int id = atoi(argv[3]);
        if (id >= conn->db->MAX_ROWS)
            die("There's not that many records.", conn);

        switch (action)
        {
        case 'f':
            if (argc != 4)
                die("Need a search term to find", conn);
            Database_find(conn, argv[3]);
            break;

        case 'g':
            if (argc != 4)
                die("Need an id to get", conn);

            Database_get(conn, id);
            break;

        case 's':
            if (argc != 6)
                die("Need id, name, email to set", conn);

            Database_set(conn, id, argv[4], argv[5]);
            Database_write(conn);
            break;

        case 'd':
            if (argc != 4)
                die("Need id to delete", conn);

            Database_delete(conn, id);
            Database_write(conn);
            break;

        case 'l':
            Database_list(conn);
            break;
        default:
            die("Invalid action, only: c=create, g=get, s=set, d=del, l=list", conn);
        }

        Database_close(conn);

        return 0;
    }
