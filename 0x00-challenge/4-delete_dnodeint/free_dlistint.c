#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
 * free_dlistint - Free a list
 *
 * @head: A pointer to the first element of the list
 */
void free_dlistint(dlistint_t *head)
{
    dlistint_t *node;

    // Traverse the list and free each node
    while (head)
    {
        node = head;     // Store the current node
        head = head->next;  // Move the head pointer to the next node
        free(node);      // Free the current node
    }
}

