/**
 * Linked List Library
 *
 * @file linked_list.c
 * @author Jacob Zarnstorff
 *
 */

#include "linked_list.h"
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
