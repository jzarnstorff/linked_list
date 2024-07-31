/**
 * Linked List Library
 *
 * @file linked_list.c
 * @author Jacob Zarnstorff
 *
 */

#include "linked_list.h"
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
