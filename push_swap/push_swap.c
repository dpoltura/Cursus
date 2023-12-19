#include "push_swap.h"

int	*init_sa(int *stack_a, int argc, char **argv)
{
	int	i;

	i = 0;
	stack_a = malloc(sizeof(int) * (argc - 1));
	if (!stack_a)
		return (NULL);
	while (argv[i + 1])
	{
		stack_a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (stack_a);
}

int	main(int argc, char **argv)
{
	int	*stack_a;
	//int	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = init_sa(stack_a, argc, argv);
	printf("%d\n", stack_a[0]);
	free(stack_a);
	return (0);
}
