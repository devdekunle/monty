#include "monty.h"

int val = -1;
/**
*push_stack - push a node onto the stack
*@stack: pointer to linked list
*@line_number: line number
*/
void push_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	if (val == -1)
	{
		dprintf(2, "L%d: Usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (stack == NULL)
	{
		exit(1);
	}

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		exit(1);
	}

	new_node->n = val;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/*void pop_stack(stack_t **stack, unsigned int line_number)
{

	printf("pop\n");
}*/

/**
*print_stack - prints all element on the stack
*@stack: pointer to linked list
*@line_number: linke number
*/
void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = NULL;

	if (val == -1)
	{
		dprintf(2, "L%d: Usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	ptr = *stack;
	while(ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;

	}

}
