#include "push_swap.h"

void	init(int **stack_first, int **stack_second, int argc, char **argv)
{
	int	i;

	i = 0;
	*stack_first = malloc(sizeof(int) * argc);
	*stack_second = malloc(sizeof(int) * argc);
	if (!stack_first || !stack_second)
		return ;
	while (argv[i + 1])
	{
		(*stack_first)[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	(*stack_first)[i] = '\0';
	i = 0;
	while (argv[i + 1])
        {
                (*stack_second)[i] = 0;
                i++;
        }
	(*stack_second)[i] = '\0';
}

int	swap(int *stack_first, int *stack_second)
{
	int	tmp;

	if (!stack_first || !stack_second)
		return (0);
	tmp = *stack_first;
	*stack_first = *stack_second;
	*stack_second = tmp;
	return (1);
}

void	swap_all(int *stack_a, int *stack_b)
{
	swap(&stack_a[0], &stack_a[1]);
	swap(&stack_b[0], &stack_b[1]);
}

int     count(int *stack)
{
        int     i;

        i = 0;
        while (stack[i])
                i++;
        return (i);
}

void	go_down(int **stack)
{
	int	i;
	int	*t_tmp;

	i = 0;
	t_tmp = malloc(sizeof(int) * (count(*stack) + 1));
	if (!t_tmp)
		return ;
	while ((*stack)[i])
	{
		t_tmp[i + 1] = (*stack)[i];
		i++;
		if (!(*stack)[i])
			t_tmp[i + 1] = (*stack)[i];
	}
	free(*stack);
	*stack = t_tmp;
}

void	go_up(int **stack)
{
	int	i;
	int	*t_tmp;

	i = 0;
	t_tmp = malloc(sizeof(int) * count(*stack));
	if (!t_tmp)
		return ;
	while ((*stack)[i + 1])
	{
		t_tmp[i] = (*stack)[i + 1];
		i++;
		if (!(*stack)[i + 1])
			t_tmp[i] = (*stack)[i + 1];
	}
	//free(*stack);
	*stack = t_tmp;
}

void	push(int **stack_first, int **stack_second)
{
	if (stack_second)
		go_down(stack_second);
	swap(stack_first[0], stack_second[0]);
	go_up(stack_first);
}

void    rotate(int **stack)
{
        int     i;
	int	tmp;
        int     *t_tmp;

        i = 0;
	tmp = (*stack)[0];
        t_tmp = malloc(sizeof(int) * count(*stack));
        if (!t_tmp)
                return ;
        while ((*stack)[i + 1])
        {
                t_tmp[i] = (*stack)[i + 1];
                i++;
                if (!(*stack)[i + 1])
		{
                        t_tmp[i] = tmp;
			t_tmp[i + 1] = (*stack)[i + 1];
		}
        }
        free(*stack);
        *stack = t_tmp;
}

void	rotate_all(int **stack_a, int **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}

void    reverse_rotate(int **stack)
{
        int     i;
        int     tmp;
        int     *t_tmp;

        i = count(*stack);
        tmp = (*stack)[i - 1];
        t_tmp = malloc(sizeof(int) * count(*stack));
        if (!t_tmp)
                return ;
	t_tmp[i] = 0;
	i--;
        while (i > 0)
        {
                t_tmp[i] = (*stack)[i - 1];
                i--;
                if (!i)
                        t_tmp[i] = tmp;
        }
        free(*stack);
        *stack = t_tmp;
}

void	reverse_rotate_all(int **stack_a, int **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}

#include <stdio.h>

void	print(int *stack_a, int *stack_b)
{
	int	i;

	i = 0;
	while (i < count(stack_a))
	{
		printf("%d | %d\n", stack_a[i], stack_b[i]);
		i++;
	}
	printf("\n\n\n");
}

int	main(int argc, char **argv)
{
	int	*stack_a;
	int	*stack_b;

	if (argc < 2)
		return (0);
	init(&stack_a, &stack_b, argc, argv);
	print(stack_a, stack_b);
	swap(&stack_a[0], &stack_a[1]);
	print(stack_a, stack_b);
	push(&stack_a, &stack_b);
        push(&stack_a, &stack_b);
        push(&stack_a, &stack_b);
	print(stack_a, stack_b);
	rotate(&stack_a);
	rotate(&stack_b);
	print(stack_a, stack_b);
	reverse_rotate(&stack_a);
	reverse_rotate(&stack_b);
	print(stack_a, stack_b);
	swap(&stack_a[0], &stack_a[1]);
	print(stack_a, stack_b);
        push(&stack_b, &stack_a);
        push(&stack_b, &stack_a);
        push(&stack_b, &stack_a);
	print(stack_a, stack_b);
	free(stack_a);
	free(stack_b);
	return (0);
}
