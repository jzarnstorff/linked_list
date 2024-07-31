/**
 * Linked List Library
 *
 * @file linked_list.h
 * @author Jacob Zarnstorff
 *
 */

#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <stdbool.h>
#include <stddef.h>

/**
 * Linked lists are made up of nodes that point to one another in a chain,
 * beginning with a head node and ending with a tail node. Each node only
 * points to one other node, and the tail node points to NULL. Empty lists
 * are also represented with NULL. For more on linked lists see:
 * https://en.wikipedia.org/wiki/Linked_list
 *
 * @brief A node in a linked list
 *
 */
typedef struct node {
    int value;         /**< the value stored in the node */
    struct node *next; /**< pointer to the next node in the linked list */
} Node;

void insert_head_node(Node **head, int value);
void insert_tail_node(Node **head, int value);
void insert_after_node(Node **head, int new_node_value, int after_node_value);

void print_linked_list(const Node *head);
size_t length_linked_list(const Node *head);
bool has_value(const Node *head, int value);
size_t num_occurrences(const Node *head, int value);

void delete_head_node(Node **head);
void delete_tail_node(Node **head);
void delete_linked_list(Node **head);

Node *get_node_by_value(Node *head, int value);
Node *get_node_by_index(Node *head, size_t index);
void replace_first_match(Node *head, int search_value, int replace_value);
void replace_all_matches(Node *head, int search_value, int replace_value);

#endif // __LINKED_LIST_H__
