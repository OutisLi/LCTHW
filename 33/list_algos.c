#include "list_algos.h"
#include "dbg.h"

int List_bubble_sort(List *list, List_compare cmp)
{
    int sorted = 1;

    if (List_count(list) <= 1)
    {
        return 0; // already sorted
    }

    do
    {
        sorted = 1;
        LIST_FOREACH(list, first, next, cur)
        {
            if (cur->next)
            {
                if (cmp(cur->value, cur->next->value) > 0)
                {
                    ListNode_swap(cur, cur->next);
                    sorted = 0;
                }
            }
        }
    } while (!sorted);

    return 0;
}

List *List_merge(List *left, List *right, List_compare cmp)
{
    List *result = List_create();

    while (left->first && right->first)
    {
        if (cmp(left->first->value, right->first->value) <= 0)
        {
            List_push(result, List_shift(left));
        }
        else
        {
            List_push(result, List_shift(right));
        }
    }
    while (left->first)
    {
        List_push(result, List_shift(left));
    }
    while (right->first)
    {
        List_push(result, List_shift(right));
    }

    return result;
}

List *List_merge_sort(List *list, List_compare cmp)
{
    if (List_count(list) <= 1)
    {
        return list;
    }

    List *secondHalf = List_split_mid(list);

    List *sort_left = List_merge_sort(list, cmp);
    List *sort_right = List_merge_sort(secondHalf, cmp);

    if (sort_left != list)
        List_destroy(list);
    if (sort_right != secondHalf)
        List_destroy(secondHalf);

    return List_merge(sort_left, sort_right, cmp);
}

List *List_split_mid(List *list)
{
    if (!list || !list->first || !list->first->next)
    {
        return NULL;
    }

    int cnt = List_count(list);
    int c1 = 1, c2 = 0;
    ListNode *slow = list->first;
    ListNode *fast = list->first->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        c1++;
    }
    c2 = cnt - c1;

    List *listsecond = List_create();
    listsecond->first = slow->next;
    listsecond->first->prev = NULL;
    listsecond->last = list->last;
    listsecond->count = c2;
    list->last = slow;
    slow->next = NULL;
    list->count = c1;

    return listsecond;
}

void List_insert_sorted(List *list, void *value, List_compare cmp){
    ListNode *node = malloc(sizeof(ListNode));
    node->value = value;
    node->next = NULL;

    if(list->first == NULL || cmp(value, list->first->value) < 0) {
        // 插入到链表头部
        node->next = list->first;
        list->first = node;
        if(list->last == NULL) {
            list->last = node;
        }
    } else {
        // 在链表中找到正确的插入位置
        ListNode *current = list->first;
        while(current->next != NULL && cmp(value, current->next->value) > 0) {
            current = current->next;
        }
        // 插入到current节点之后
        node->next = current->next;
        current->next = node;
        if(current->next == NULL) {
            list->last = node;
        }
    }
    list->count++;
}
