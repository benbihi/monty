#include "monty.h"

/**
 * add_to_stack - Adds a node to the stack.
 * @newNode: Pointer to the new node.
 * @ln: Interger representing the line number of of the opcode.
 */
void add_to_stack(stack_t **newNode, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (newNode == NULL || *newNode == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *newNode;
		return;
	}
	tmp = head;
	head = *newNode;
	head->next = tmp;
	tmp->prev = head;
}


/**
 * print_stack - Adds a node to the stack.
 * @s: Pointer to a pointer pointing to top node of the stack.
 * @ln: line number of  the opcode.
 */
void print_stack(stack_t **s, unsigned int ln)
{
	stack_t *tmp;

	(void) ln;
	if (s == NULL)
		exit(EXIT_FAILURE);
	tmp = *s;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pop - Adds a node to the stack.
 * @s: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void _pop(stack_t **s, unsigned int line_number)
{
	stack_t *tmp;

	if (s == NULL || *s == NULL)
		err2(7, line_number);

	tmp = *s;
	*s = tmp->next;
	if (*s != NULL)
		(*s)->prev = NULL;
	free(tmp);
}

/**
 * top - Prints the top node of the stack.
 * @s: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void _top(stack_t **s, unsigned int line_number)
{
	if (s == NULL || *s == NULL)
		err2(6, line_number);
	printf("%d\n", (*s)->n);
}
