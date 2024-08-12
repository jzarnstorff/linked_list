#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    Node *list_1 = NULL;
    Node *list_2 = NULL;

    for (int i = 0; i < 5; ++i) {
        insert_tail_node(&list_1, i);
        insert_tail_node(&list_2, i);
    }

    insert_head_node(&list_1, 0);
    insert_head_node(&list_1, 42);
    insert_tail_node(&list_1, 42);
    print_linked_list(list_1);

    printf("Delete head node\n");
    delete_head_node(&list_1);
    print_linked_list(list_1);

    printf("Delete tail node\n");
    delete_tail_node(&list_1);
    print_linked_list(list_1);

    int value = 2;
    printf("Delete first matching node with value: %d\n", value);
    delete_first_match(&list_1, value);
    print_linked_list(list_1);

    value = 0;
    printf("Delete first matching node with value: %d\n", value);
    delete_first_match(&list_1, value);
    print_linked_list(list_1);

    value = 4;
    printf("Delete first matching node with value: %d\n", value);
    delete_first_match(&list_1, value);
    print_linked_list(list_1);

    value = 42;
    printf("Attempt to delete first matching node with value: %d\n", value);
    delete_first_match(&list_1, value);
    print_linked_list(list_1);

    printf("Insert node with value: %d after node with value: 3\n", value);
    insert_after_node(&list_1, value, 3);
    print_linked_list(list_1);

    printf("Insert node with value: %d after node with value: 99\n", value);
    insert_after_node(&list_1, value, 99);
    print_linked_list(list_1);

    printf("Insert node with value: %d in various places\n", value);
    insert_head_node(&list_1, 42);
    insert_after_node(&list_1, 42, 0);
    insert_after_node(&list_1, 42, 0);
    insert_tail_node(&list_1, 42);
    print_linked_list(list_1);

    printf("Length of list_1: %zu\n", length_linked_list(list_1));
    printf("Number of occurrences of nodes with value: %d = %zu\n", value,
           num_occurrences(list_1, value));

    printf("Delete all matching nodes with value: %d\n", value);
    delete_all_matches(&list_1, value);
    print_linked_list(list_1);

    printf("Swap node values with indexes: 2 and 0\n");
    swap_node_values_by_index(list_1, 2, 0);
    print_linked_list(list_1);

    printf("Rebuild linked list\n");
    delete_linked_list(&list_1);
    list_1 = NULL;
    for (int i = 0; i < 5; ++i)
        insert_tail_node(&list_1, i);

    print_linked_list(list_1);

    printf("Reverse list_1\n");
    reverse_linked_list(&list_1);
    print_linked_list(list_1);

    printf("Append list_2 to list_1\n");
    append_linked_list(&list_1, list_2);
    print_linked_list(list_1);

    delete_linked_list(&list_1);

    return 0;
}
