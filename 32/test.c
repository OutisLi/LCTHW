#include "list.h"
#include <assert.h>
#include "minunit.h"

static List *list = NULL;
static List *list_copy = NULL;
static List *list_second = NULL;
static List *list_split = NULL;

char *test1;
char *test2;
char *test3;
char *test_create()
{
    list = List_create();
    mu_assert(list != NULL, "Failed to create list.");

    return NULL;
}

char *test_destroy()
{
    List_clear_destroy(list);

    return NULL;
}

char *test_push_pop()
{
    List_push(list, test1);
    mu_assert(List_last(list) == test1, "Wrong last value.");

    List_push(list, test2);
    mu_assert(List_last(list) == test2, "Wrong last value");

    List_push(list, test3);
    mu_assert(List_last(list) == test3, "Wrong last value.");
    mu_assert(List_count(list) == 3, "Wrong count on push.");

    char *val = List_pop(list);
    mu_assert(val == test3, "Wrong value on pop.");

    val = List_pop(list);
    mu_assert(val == test2, "Wrong value on pop.");

    val = List_pop(list);
    mu_assert(val == test1, "Wrong value on pop.");
    mu_assert(List_count(list) == 0, "Wrong count after pop.");

    return NULL;
}

char *test_unshift()
{
    List_unshift(list, test1);
    mu_assert(List_first(list) == test1, "Wrong first value.");

    List_unshift(list, test2);
    mu_assert(List_first(list) == test2, "Wrong first value");

    List_unshift(list, test3);
    mu_assert(List_first(list) == test3, "Wrong last value.");
    mu_assert(List_count(list) == 3, "Wrong count on unshift.");

    return NULL;
}

char *test_remove()
{
    // we only need to test the middle remove case since push/shift
    // already tests the other cases

    char *val = List_remove(list, list->first->next);
    mu_assert(val == test2, "Wrong removed element.");
    mu_assert(List_count(list) == 2, "Wrong count after remove.");
    mu_assert(List_first(list) == test3, "Wrong first after remove.");
    mu_assert(List_last(list) == test1, "Wrong last after remove.");

    return NULL;
}

char *test_shift()
{
    mu_assert(List_count(list) != 0, "Wrong count before shift.");

    char *val = List_shift(list);
    mu_assert(val == test3, "Wrong value on shift.");

    val = List_shift(list);
    mu_assert(val == test1, "Wrong value on shift.");
    mu_assert(List_count(list) == 0, "Wrong count after shift.");

    return NULL;
}

char *test_copy()
{
    List_push(list, test1);
    List_push(list, test2);
    List_push(list, test3);
    list_copy = List_copy(list);
    mu_assert(list_copy != NULL, "Failed to copy list.");
    mu_assert(List_count(list_copy) == List_count(list), "Copy list has wrong count.");

    List_clear_destroy(list_copy);

    return NULL;
}

char *test_join()
{
    list_second = List_create();
    List_push(list_second, test3);
    int count1 = List_count(list);

    List_join(list, list_second);
    int count2 = List_count(list_second);

    mu_assert(List_count(list) == (count1 + count2), "Join list has wrong count.");
    mu_assert(List_last(list) == test3, "Joined list has wrong last element.");

    return NULL;
}

char *test_split()
{
    ListNode *node = list->first->next; // test2
    int count1 = List_count(list);
    list_split = List_split(list, node);
    mu_assert(List_count(list) == 1, "Original list has wrong count after split.");
    mu_assert(List_count(list_split) == count1 - 1, "New list has wrong count after split.");
    mu_assert(List_first(list_split) == test2, "Split list has wrong first element.");

    return NULL;
}

char *all_tests()
{
    mu_suite_start();

    test1 = strdup("test1 data");
    test2 = strdup("test2 data");
    test3 = strdup("test3 data");

    mu_run_test(test_create);
    mu_run_test(test_push_pop);
    mu_run_test(test_unshift);
    mu_run_test(test_remove);
    mu_run_test(test_shift);
    mu_run_test(test_copy);
    mu_run_test(test_join);
    mu_run_test(test_split);
    mu_run_test(test_destroy);

    return NULL;
}

RUN_TESTS(all_tests);
