/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:20:01 by tayeo             #+#    #+#             */
/*   Updated: 2022/11/05 17:33:51 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	input_checker(int argc, char **argv)
{
	int	idx;

	while (argc > 1)
	{
		idx = 0;
		while (argv[argc - 1][idx])
		{
			if (!ft_isdigit(argv[argc -1][idx]) || ft_strlen(argv[argc - 1]) > 10)
				return (0);
			idx++;
		}
		argc--;
	}
	return (1);
}

void print_stack(t_stack a, t_stack b)
{
	int i = 0;
	while (i < a.size || i < b.size)
	{
		if (i < a.size && i < b.size)
			ft_printf("%d       %d\n", a.stk[i], b.stk[i]);
		else if (i < a.size)
			ft_printf("%d\n", a.stk[i]);
		else if (i < b.size)
			ft_printf("        %d\n", b.stk[i]);
		i++;
	}
	ft_printf("--      --\n");
	ft_printf("a       b\n\n");
}

int main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2 || input_checker(argc, argv) == 0)
	{
		ft_printf("Argument Error\n");
		return (0);
	}
	ft_printf("Argc: %d\n", argc);
	a.stk = malloc(sizeof(int) * (argc - 1));
	b.stk = malloc(sizeof(int) * (argc - 1));
	if (a.stk == NULL || b.stk == NULL)
		return (1);
	a.size = argc - 1;
	b.size = 0;
	while (argc > 0)
	{
		a.stk[argc - 2] = ft_atoi(argv[argc - 1]);
		argc--;
	}
	print_stack(a, b);
	for (int i = 0; i < 20; i++)
	{
		sort(&a, &b);
		print_stack(a, b);
	}
	print_stack(a, b);

	return (0);
}
