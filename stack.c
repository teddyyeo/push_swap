/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:20:01 by tayeo             #+#    #+#             */
/*   Updated: 2022/11/04 15:47:00 by tayeo            ###   ########.fr       */
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

void print_stack(stack a, stack b)
{
	int i = 0;
	while (i < a.top)
	{
		ft_printf("%d       %d\n", a.stk[i], b.stk[i]);
		i++;
	}
	ft_printf("__      __\n");
	ft_printf("a       b\n");
}

int main(int argc, char **argv)
{
	stack	a;
	stack	b;

	if (argc < 2 || input_checker(argc, argv) == 0)
	{
		ft_printf("Argument Error\n");
		return (0);
	}
	ft_printf("Argc: %d\n", argc);
	a.stk = malloc(sizeof(int) * (argc - 1));
	b.stk = malloc(sizeof(int) * (argc - 1));
	//NULL GUARD
	a.top = argc - 1;
	b.top = argc - 1;
	while (argc > 0)
	{
		a.stk[argc - 2] = ft_atoi(argv[argc - 1]);
		argc--;
	}

	print_stack(a, b);

	return (0);
}
