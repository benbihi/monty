#include "monty.h"

/**
 * mul - Adds the top two elements of the stack.
 * @s: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void _mul(stack_t **s, unsigned int ln)
{
	int sum;

	if (s == NULL || *s == NULL || (*s)->next == NULL)
		err2(8, ln, "mul");

	(*s) = (*s)->next;
	sum = (*s)->n * (*s)->prev->n;
	(*s)->n = sum;
	free((*s)->prev);
	(*s)->prev = NULL;
}


/**
 * mod - Adds the top two elements of the stack.
 * @s: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void _mod(stack_t **s, unsigned int ln)
{
	int sum;

	if (s == NULL || *s == NULL || (*s)->next == NULL)

		err2(8, ln, "mod");


	if ((*s)->n == 0)
		err2(9, ln);
	(*s) = (*s)->next;
	sum = (*s)->n % (*s)->prev->n;
	(*s)->n = sum;
	free((*s)->prev);
	(*s)->prev = NULL;
}
