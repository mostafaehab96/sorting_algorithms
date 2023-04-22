#include "sort.h"


/**
 * insertion_sort_list - sorts the doubly linked list by insertion sort
 * @list: a pointer the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *p, *q, *t;
	int n;

	if (!list && !*list && !(*list)->next)
		return;

	t = (*list)->next;

	while (t)
	{
		p = t;
		q = p->prev;
		n = p->n;
		t = t->next;
		while (q && n < q->n)
		{
			q->next = p->next;
			p->next = q;
			p->prev = q->prev;
			q->prev = p;
			if (q->next)
				(q->next)->prev = q;
			if (!p->prev)
				*list = p;
			else
				(p->prev)->next = p;
			q = p->prev;
			print_list(*list);
		}
	}

}

