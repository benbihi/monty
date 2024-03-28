#include "monty.h"

/**
 * nop - Does nothing.
 * @s: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void nop(stack_t **s, unsigned int ln)
{
	(void)s;
	(void)ln;
}


/**
 * swap_nodes - Swaps the top two elements of the stack.
 * @s: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void swap_nodes(stack_t **s, unsigned int ln)
{
	stack_t *tmp;

	if (s == NULL || *s == NULL || (*s)->next == NULL)
		err2(8, ln, "swap");
	tmp = (*s)->next;
	(*s)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *s;
	tmp->next = *s;
	(*s)->prev = tmp;
	tmp->prev = NULL;
	*s = tmp;
}

/**
 * add - Adds the top two elements of the stack.
 * @s: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void _add(stack_t **s, unsigned int ln)
{
	int sum;

	if (s == NULL || *s == NULL || (*s)->next == NULL)
		err2(8, ln, "add");

	(*s) = (*s)->next;
	sum = (*s)->n + (*s)->prev->n;
	(*s)->n = sum;
	free((*s)->prev);
	(*s)->prev = NULL;
}


/**
 * sub - Adds the top two elements of the stack.
 * @s: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void _sub(stack_t **s, unsigned int ln)
{
	int sum;

	if (s == NULL || *s == NULL || (*s)->next == NULL)

		err2(8, ln, "sub");


	(*s) = (*s)->next;
	sum = (*s)->n - (*s)->prev->n;
	(*s)->n = sum;
	free((*s)->prev);
	(*s)->prev = NULL;
}


/**
 * div - Adds the top two elements of the stack.
 * @s: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void _div(stack_t **s, unsigned int ln)
{
	int sum;

	if (s == NULL || *s == NULL || (*s)->next == NULL)
		err2(8, ln, "div");

	if ((*s)->n == 0)
		err2(9, ln);
	(*s) = (*s)->next;
	sum = (*s)->n / (*s)->prev->n;
	(*s)->n = sum;
	free((*s)->prev);
	(*s)->prev = NULL;
}
