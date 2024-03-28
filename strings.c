#include "monty.h"

/**
 * print_char - Prints the Ascii value.
 * @s: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void print_char(stack_t **s, unsigned int line_number)
{
	int code;

	if (s == NULL || *s == NULL)
		string_err(11, line_number);

	code = (*s)->n;
	if (code < 0 || code > 127)
		string_err(10, line_number);
	printf("%c\n", code);
}

/**
 * print_str - Prints a string.
 * @s: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void print_str(stack_t **s, __attribute__((unused))unsigned int ln)
{
	int code;
	stack_t *tmp;

	if (s == NULL || *s == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *s;
	while (tmp != NULL)
	{
		code = tmp->n;
		if (code <= 0 || code > 127)
			break;
		printf("%c", code);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rotl - Rotates the first node of the stack to the bottom.
 * @s: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void rotl(stack_t **s, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (s == NULL || *s == NULL || (*s)->next == NULL)
		return;

	tmp = *s;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *s;
	(*s)->prev = tmp;
	*s = (*s)->next;
	(*s)->prev->next = NULL;
	(*s)->prev = NULL;
}


/**
 * rotr - Rotates the last node of the stack to the top.
 * @s: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void rotr(stack_t **s, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (s == NULL || *s == NULL || (*s)->next == NULL)
		return;

	tmp = *s;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *s;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*s)->prev = tmp;
	(*s) = tmp;
}
