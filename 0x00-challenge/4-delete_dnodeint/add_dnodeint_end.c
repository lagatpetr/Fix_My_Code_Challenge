#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
 * add_dnodeint_end - Add a node at the end of a list
 *
 * @head: The address of the pointer to the first element of the list
 * @n: The number to store in the new element
 *
 * Return: A pointer to the new element
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
    dlistint_t *new;
    dlistint_t *l;

    // Allocate memory for the new node
    new = malloc(sizeof(dlistint_t));
    if (new == NULL)
    {
        return (NULL);  // Return NULL if memory allocation fails
    }
    new->n = n;  // Set the value of the new node
    new->next = NULL;  // Set the next pointer to NULL

    // If the list is empty, set the new node as the head
    if (*head == NULL)
    {
        *head = new;
        new->prev = NULL;
        return (new);
    }

    l = *head;  // Initialize a pointer to traverse the list
    // Traverse to the end of the list
    while (l->next != NULL)
    {
        l = l->next;
    }

    l->next = new;  // Set the next pointer of the last node to the new node
    new->prev = l;  // Set the previous pointer of the new node to the last node
    return (new);  // Return the pointer to the new node
}

