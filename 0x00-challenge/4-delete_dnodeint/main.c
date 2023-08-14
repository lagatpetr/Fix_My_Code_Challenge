#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    dlistint_t *head = NULL;
    int nums[] = {0, 1, 2, 3, 4, 98, 402, 1024};
    size_t num_elements = sizeof(nums) / sizeof(nums[0]);

    for (size_t i = 0; i < num_elements; i++)
    {
        add_dnodeint_end(&head, nums[i]);
    }

    printf("Original List:\n");
    print_dlistint(head);
    printf("-----------------\n");

    printf("Deleting node at index 5:\n");
    delete_dnodeint_at_index(&head, 5);
    print_dlistint(head);
    printf("-----------------\n");

    printf("Deleting first node:\n");
    delete_dnodeint_at_index(&head, 0);
    print_dlistint(head);
    printf("-----------------\n");

    printf("Deleting first node again:\n");
    delete_dnodeint_at_index(&head, 0);
    print_dlistint(head);
    printf("-----------------\n");

    // Continue deleting first node until the list is empty
    while (head)
    {
        delete_dnodeint_at_index(&head, 0);
        print_dlistint(head);
        printf("-----------------\n");
    }

    free_dlistint(head);

    return (0);
}

