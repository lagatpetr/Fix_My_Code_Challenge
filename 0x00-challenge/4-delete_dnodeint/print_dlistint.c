#include <stdio.h>
#include "lists.h"

/**
 * print_dlistint - Prints a doubly linked list of integers
 *
 * @h: A pointer to the first element of a list
 *
 * Return: The number of elements printed
 */
size_t print_dlistint(const dlistint_t *h)
{
    size_t n; // Counter for the number of elements printed

    n = 0; // Initialize the counter
    while (h)
    {
        printf("%d\n", h->n); // Print the value of the current node
        h = h->next; // Move to the next node
        n++; // Increment the counter
    }
    return (n); // Return the total number of elements printed
}

