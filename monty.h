#ifndef MONTYH
#define MONTYH

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_function)(stack_t **, unsigned int);

/* file functions */
void open_file(char *f);
void read_file(FILE *fd);
int parse_l(char *buf, int ln, int fromat);
int len_chars(FILE *);

/* stack functions */
stack_t *create_node(int n);
void free_nodes(void);
void print_stack(stack_t **, unsigned int);
void add_to_stack(stack_t **newNode, unsigned int);
void add_to_queue(stack_t **newNode, unsigned int);

void find_function(char *opcode, char *value, int ln, int format);
void call_function(op_function func, char *op, char *val, int ln, int format);

void _top(stack_t **s, unsigned int);
void _pop(stack_t **s, unsigned int);
void nop(stack_t **s, unsigned int);
void swap_nodes(stack_t **s, unsigned int);

/* MATH functions on stack nodes */
void _add(stack_t **s, unsigned int);
void _sub(stack_t **s, unsigned int);
void _div(stack_t **s, unsigned int);
void _mul(stack_t **s, unsigned int);
void _mod(stack_t **s, unsigned int);

/* string functions */
void print_char(stack_t **s, unsigned int);
void print_str(stack_t **s, unsigned int);
void rotl(stack_t **s, unsigned int);

/*Error hanlding*/
void err(int error_code, ...);
void err2(int error_code, ...);
void string_err(int error_code, ...);
void rotr(stack_t **s, unsigned int);

#endif
