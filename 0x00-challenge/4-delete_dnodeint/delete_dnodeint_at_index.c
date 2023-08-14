#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *saved_head;
    dlistint_t *tmp;
    unsigned int p;

    // Check if the list is empty
    if (*head == NULL)
    {
        return (-1);  // Return -1 on failure (empty list)
    }

    saved_head = *head;  // Save the original head of the list
    p = 0;  // Initialize a variable to keep track of the current position

    // Traverse the list until reaching the desired index or the end
    while (p < index && *head != NULL)
    {
        *head = (*head)->next;  // Move the head pointer
        p++;
    }

    // Check if the desired index was not reached
    if (p != index)
    {
        *head = saved_head;  // Restore the original head
        return (-1);  // Return -1 on failure (invalid index)
    }

    // Check if the node to be deleted is the first one (index = 0)
    if (0 == index)
    {
        tmp = (*head)->next;  // Store the next node
        free(*head);  // Free the node to be deleted
        *head = tmp;  // Update the head to the next node
        if (tmp != NULL)
        {
            tmp->prev = NULL;  // Update the previous pointer of the new head
        }
    }
    else
    {
        // Update the previous and next pointers to skip the node to be deleted
        (*head)->prev->next = (*head)->next;
        if ((*head)->next)
        {
            (*head)->next->prev = (*head)->prev;
        }
        free(*head);  // Free the node to be deleted
        *head = saved_head;  // Restore the original head
    }

    return (1);  // Return 1 on success
}

