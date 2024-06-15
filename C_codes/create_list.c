#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;

void free_list(listint_t *);


listint_t *create_list(int arr[], size_t size)
{
	listint_t *head, *curr;
	size_t k;

	if (size == 0)
		return (NULL);

	head = malloc(sizeof(listint_t));
	if (!head)
		return NULL;

	head->n = arr[0];
	head->next = NULL;

	curr = head;
	k = 1;
	while (k < size)
	{
		listint_t *new;

		new = malloc(sizeof(listint_t));
		if (!new)
		{
			free_list(head);
			return (NULL);
		}

		new->n = arr[k];
		new->next = NULL;
		curr->next = new;
		curr = new;
		k++;
	}
	return (head);
}

void swap_list(listint_t **head, listint_t *n1, listint_t *n2)
{
	listint_t *curr, *prev1 = NULL, *prev2 = NULL;

	curr = *head;
	while (curr && curr->next)
	{
		if (curr->next == n1)
			prev1 = curr;
		if (curr->next == n2)
			prev2 = curr;
		curr = curr->next;
	}

	if (!prev1 && *head != n1 ||  !prev2 && *head != n2)
		return;

	if (*head == n1 || *head == n2)
	{
		listint_t *temp;

		temp = n1->next;
		n1->next = n2->next;
		n2->next = temp;

		if (*head == n1)
		{
			*head = n2;
			prev2->next = n1;
		}
		else
		{
			*head = n1;
			prev1->next = n2;
		}
	}
	else
	{
		listint_t *temp;

		temp = n1->next;
		n1->next = n2->next;
		n2->next = temp;
		prev1->next = n2;
		prev2->next = n1;
	}
}

void free_list(listint_t *head)
{
	listint_t *curr, *next;

	curr = head;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
}

void print_list(listint_t *head)
{
	bool not_first = true;

	printf("The linked list created from array:\n");

	while (head)
	{
		if (!not_first)
			printf("->");
		printf("%d", head->n);
		not_first = false;
		head = head->next;
	}
	printf("\n");
}


int main(void)
{
	int arr[] = {1, 2, 5, 67, 35, 9, 88, 79};
	size_t size = sizeof(arr) / sizeof(arr[0]);
	listint_t *list, *n1, *n2;

	list = create_list(arr, size);
	print_list(list);

	n1 = list->next->next;
	n2 = list->next->next->next->next->next;
	swap_list(&list, n1, n2);
	print_list(list);
	free_list(list);
	return (0);
}
