#ifndef lcthw_List_algos_h
#define lcthw_List_algos_h

#include "list.h"

typedef int (*List_compare)(const void *a, const void *b);

static inline void ListNode_swap(ListNode *a, ListNode *b)
{
    void *temp = a->value;
    a->value = b->value;
    b->value = temp;
}

int List_bubble_sort(List *list, List_compare cmp);

List *List_merge_sort(List *list, List_compare cmp);
List *List_split_mid(List *list);
void List_insert_sorted(List *list, void *value, List_compare cmp);

#endif