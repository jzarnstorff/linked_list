/**
 * Linked List Library
 *
 * @file linked_list.c
 * @author Jacob Zarnstorff
 *
 */

#include "linked_list.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

static inline Node *create_new_node(int value) {
    Node *node = calloc(1, sizeof(Node));
    node->value = value;
    return node;
}

/**
 * @brief Insert a new node at the head of a linked list
 *
 * @param head address of a pointer to the head of a linked list
 * @param value value to store in a new node
 * @return nothing
 */
void insert_head_node(Node **head, int value) {
    Node *node = create_new_node(value);
    node->next = *head;
    *head = node;
}

/**
 * @brief Insert a new node at the tail of a linked list
 *
 * @param head address of a pointer to the head of a linked list
 * @param value value to store in a new node
 * @return nothing
 */
void insert_tail_node(Node **head, int value) {
    Node *node = create_new_node(value);

    if (*head == NULL)
        *head = node;

    else {
        Node *current = *head;
        while (current->next != NULL)
            current = current->next;

        current->next = node;
    }
}

/**
 * Inserts a new node in a linked list after the first occurrence of a node
 * with a given value. If no node with that given value occurs in the list,
 * the new node is inserted at the tail of the linked list.
 *
 * @brief Inserts a new node in a linked list after a given value
 *
 * @param head address of a pointer to the head of a linked list
 * @param new_node_value value to store in a new node in the linked list
 * @param after_node_value value of a node after which to insert the new node
 * @return nothing
 */
void insert_after_node(Node **head, int new_node_value, int after_node_value) {
    if (*head == NULL) // list is empty; insert as the head of a new list
        return insert_head_node(head, new_node_value);

    else {
        Node *current = *head;
        // traverse to the end of the list
        while (current->next != NULL) {
            if (current->value == after_node_value)
                break;

            current = current->next;
        }

        // we've either found the node with the given value, or we've
        // reached the end of the list. insert new node after the current
        // node regardless.
        Node *new_node = create_new_node(new_node_value);
        new_node->next = current->next;
        current->next = new_node;
    }
}

/**
 * @brief Print out a linked list
 *
 * @param head pointer to the head of a linked list
 * @return nothing
 */
void print_linked_list(const Node *head) {
    size_t index = 0;
    const Node *current = head;

    while (current != NULL) {
        printf("Node[%zu]: %d -> ", index++, current->value);
        current = current->next;
    }
    printf("NULL\n");
}

/**
 * @brief Recursively traverse the list to count the number of nodes
 *
 * @param head pointer to the head of a linked list
 * @return length of the linked list
 */
size_t length_linked_list(const Node *head) {
    if (head == NULL)
        return 0;

    else
        return 1 + length_linked_list(head->next);
}

/**
 * @brief Recursively traverse the list for the presence of a value in the list
 *
 * @param head pointer to the head of a linked list
 * @param value value of the node to search for
 * @return true/false
 */
bool has_value(const Node *head, int value) {
    if (head == NULL)
        return false;

    else if (head->value == value)
        return true;

    else
        return has_value(head->next, value);
}

/**
 * @brief Recursively traverse the list to count the number of nodes with a
 * given value
 *
 * @param head pointer to the head of a linked list
 * @param value value of the node to search for
 * @return number of nodes with given value
 */
size_t num_occurrences(const Node *head, int value) {
    if (head == NULL)
        return 0;

    else if (head->value == value)
        return 1 + num_occurrences(head->next, value);

    else
        return num_occurrences(head->next, value);
}

/**
 * @brief Swap the values between two nodes
 *
 * @param node_1 pointer to first node whose value should be swapped with the
 * second node
 * @param node_1 pointer to second node whose value should be swapped with the
 * first node
 * @return nothing
 */
void swap_node_values(Node *node_1, Node *node_2) {
    if ((node_1 == NULL) || node_2 == NULL)
        return;

    int temp_value = node_1->value;
    node_1->value = node_2->value;
    node_2->value = temp_value;
}

/**
 * @brief Delete the node at the head of a linked list
 *
 * @param head address of a pointer to the head of a linked list
 * @return nothing
 */
void delete_head_node(Node **head) {
    if (*head == NULL)
        return;

    Node *next_node = (*head)->next;
    free(*head);
    *head = next_node;
}

/**
 * @brief Delete the node at the tail of a linked list
 *
 * @param head address of a pointer to the head of a linked list
 * @return nothing
 */
void delete_tail_node(Node **head) {
    if (*head == NULL)
        return;

    else if ((*head)->next == NULL)
        return delete_head_node(head);

    else {
        Node *node = *head;
        // traverse to the second to last node in the list
        while (node->next->next != NULL)
            node = node->next;

        free(node->next);
        node->next = NULL;
    }
}

/**
 * @brief Delete all nodes in a linked list
 *
 * @param head address of a pointer to the head of a linked list
 * @return nothing
 */
void delete_linked_list(Node **head) {
    Node *next, *current = *head;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}

/**
 * @brief Reverse all nodes in a linked list
 *
 * @param head address of a pointer to the head of a linked list
 * @return nothing
 */
void reverse_linked_list(Node **head) {
    if ((*head == NULL) || ((*head)->next == NULL))
        return;

    Node *previous = NULL;
    Node *current = *head;
    Node *next;
    while (current != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    // current is now pointing to NULL and previous is pointing what used to be
    // the last node in the linked list; assign it as the new head of the list
    *head = previous;
}

/**
 * @brief Appends the list beginning with head_2 to the tail of the list
 * beginning with head_1
 *
 * @param head_1 address of a pointer to the head of the first linked list
 * @param head_2 pointer to the head of the list to append to the first linked
 * list
 * @return nothing
 */
void append_linked_list(Node **head_1, Node *head_2) {
    if (head_2 == NULL)
        return;

    if (*head_1 == NULL) {
        // head_2 doesn't point to NULL, but the head_1
        // pointer does; head_2 is now the head of the list
        *head_1 = head_2;
        return;
    }

    Node *current = *head_1;
    // traverse to the last node in the linked list
    // to change its next pointer to point to head_2
    while (current->next != NULL)
        current = current->next;

    current->next = head_2;
}

/**
 * @brief Find a node in a linked list by value
 *
 * @param head pointer to the head of a linked list
 * @param value value to of node in a linked list for which to search
 * @return pointer to a node or NULL
 */
Node *get_node_by_value(Node *head, int value) {
    if (head == NULL)
        return NULL;

    Node *current = head;
    while (current != NULL) {
        if (current->value == value)
            break;

        current = current->next;
    }

    return current;
}

/**
 * Find a node in a linked list by its index. If the list is empty (NULL),
 * a NULL pointer is returned. A NULL pointer will also be returned if the
 * desired node's index is greater than the length of the linked list.
 *
 * @brief Find a node in a linked list by index
 *
 * @param head pointer to the head of a linked list
 * @param index the desired node's index in the list
 * @return pointer to a node or NULL
 */
Node *get_node_by_index(Node *head, size_t index) {
    Node *current = head;
    size_t current_index = 0;

    // if linked list is empty (NULL), we won't even
    // enter this loop and we will return a NULL pointer.
    while (current != NULL) {
        if (current_index == index)
            break;

        current = current->next;
        ++current_index;
    }

    return current;
}

/**
 * @brief Find the first node in a linked list by value and replace the value
 * the matching nodes, if any
 *
 * @param head pointer to the head of a linked list
 * @param search_value value of first node in the linked list to replace
 * @param replace_value the replacement value
 * @return nothing
 */
void replace_first_match(Node *head, int search_value, int replace_value) {
    Node *node = get_node_by_value(head, search_value);
    if (node != NULL)
        node->value = replace_value;
}

/**
 * @brief Find the all nodes in a linked list by value and replace the values of
 * any matching nodes
 *
 * @param head pointer to the head of a linked list
 * @param search_value value of node in the linked list to replace
 * @param replace_value the replacement value
 * @return nothing
 */
void replace_all_matches(Node *head, int search_value, int replace_value) {
    if (head == NULL)
        return;

    Node *current = head;
    while (current != NULL) {
        if (current->value == search_value)
            current->value = replace_value;

        current = current->next;
    }
}

/**
 * @brief Find the first node in a linked list by value and delete it, if any
 *
 * @param head address of a pointer to the head of a linked list
 * @param value value of first node in the linked list to find and delete
 * @return nothing
 */
void delete_first_match(Node **head, int value) {
    if (*head == NULL)
        return;

    if ((*head)->value == value)
        return delete_head_node(head);

    // the value at the head of the list
    // does not match the target value
    Node *previous = *head;
    Node *current = (*head)->next;
    while (current != NULL) {
        if (current->value == value) {
            previous->next = current->next;
            free(current);
            break;
        }

        previous = current;
        current = current->next;
    }
}

/**
 * @brief Find the all nodes in a linked list by value and delete them, if any
 *
 * @param head address of a pointer to the head of a linked list
 * @param value value of nodes in the linked list to find and delete
 * @return nothing
 */
void delete_all_matches(Node **head, int value) {
    if (*head == NULL)
        return;

    Node *current, *match;
    current = *head;

    // handle multiple subsequent matches
    // starting from the head of the list
    while (current->value == value) {
        match = current;
        current = current->next;
        free(match);
    }

    // current is now guaranteed to be pointing to
    // the first non-matching node in the list
    *head = current;
    while (current->next != NULL) {
        // check for matches and possible
        // multiple subsequent matches to
        // free and update next pointer
        if (current->next->value == value) {
            match = current->next;
            current->next = current->next->next;
            free(match);
        }

        else
            current = current->next;
    }
}

/**
 * Find and delete a node in a linked list by its index. If the list is empty
 * (NULL), or if the desired node's index is greater than the length of the
 * linked list, the list will remain unchanged.
 *
 * @brief Find a node in a linked list by index and remove it
 *
 * @param head address of a pointer to the head of a linked list
 * @param index the desired node's index in the list to delete
 * @return nothing
 */
void delete_node_by_index(Node **head, size_t index) {
    if (*head == NULL)
        return;

    if (index == 0)
        return delete_head_node(head);

    // find the previous node of the desired node
    Node *previous = get_node_by_index(*head, index - 1);

    // first evaluate if the previous node is NULL meaning even the previous
    // node's index is greater than the length of the linked list or if the
    // previous node's index is the tail of the linked list
    if ((previous == NULL) || (previous->next == NULL))
        return;

    Node *match = previous->next;
    previous->next = match->next;
    free(match);
}

/**
 * Find and two node in a linked list by their indexes. If the list is empty
 * (NULL), or if any the desired node's indexes are greater than the length
 * of the linked list, the list will remain unchanged.
 *
 * @brief Find two nodes in a linked list by their indexes and swap their values
 *
 * @param head pointer to the head of a linked list
 * @param index_1 the index of a node in the list to whose value should be
 * swapped with index_2
 * @param index_2 the index of a node in the list to whose value should be
 * swapped with index_1
 * @return nothing
 */
void swap_node_values_by_index(Node *head, size_t index_1, size_t index_2) {
    if ((head == NULL) || (index_1 == index_2))
        return;

    // first evaluate which index is the minimum value and maximum value
    size_t min_index = index_1, max_index = index_2;
    if (index_1 > index_2) {
        min_index = index_2;
        max_index = index_1;
    }

    // get the respective nodes by their indexes. first get the node with
    // minimum index starting from the head of the linked list. next get the
    // node with the larger index starting from the minimum index node so we
    // don't traverse from the head of the list again.
    Node *node_1 = get_node_by_index(head, min_index);
    Node *node_2 = get_node_by_index(node_1, max_index - min_index);

    if ((node_1 == NULL) || (node_2 == NULL))
        return;

    swap_node_values(node_1, node_2);
}
