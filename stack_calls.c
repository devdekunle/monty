#include "monty.h"
global global_t;


void push_stack(stack_t **stack, unsigned int line_number)
{
	if ((global_t.ag == 0 || global_t.val == 0) && (strcmp(global_t.arg, "-0") != 0))
	{
		dprintf(2, "L%u: usage: push integer\n", line_number);
		free_list(*stack);
		free(global_t.ptr_line);
		exit(EXIT_FAILURE);
	}
	add_dnodeint(stack, global_t.val);
}

void pop_stack(stack_t **stack, unsigned int line_number)
{
	if (len_dlistint(*stack) == 0)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", line_number);
		free_list(*stack);
		free(global_t.ptr_line);
		exit(EXIT_FAILURE);
	}
	pop_dnodeint(stack);
}

void print_stack(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (len_dlistint(*stack) == 0)
		dprintf(1,"0\n");
	print_dlistint(*stack);
}


void print_stack_head(stack_t **stack, unsigned int line_number)
{
	int k = 0;

	if (len_dlistint(*stack) == 0)
	{
		dprintf(2, "L%u: can't pint, stack empty\n", line_number);
		free_list(*stack);
		free(global_t.ptr_line);
		exit(EXIT_FAILURE);
	}
	print_top_node(*stack);
	if (global_t.ag == 0)
	{
		dprintf(1, "%d\n", k);
		return;
	}
}
