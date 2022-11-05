/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:05:42 by tayeo             #+#    #+#             */
/*   Updated: 2022/11/05 16:49:27 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *a)
{
	int	temp;

	if (a->size < 2)
		return ;
	temp = a->stk[0];
	a->stk[0] = a->stk[1];
	a->stk[1] = temp;
	ft_printf("sa\n");
}

void	swap_b(t_stack *b)
{
	int	temp;

	if (b->size < 2)
		return ;
	temp = b->stk[0];
	b->stk[0] = b->stk[1];
	b->stk[1] = temp;
	ft_printf("sb\n");
}

void	swap_swap(t_stack *a, t_stack *b)
{
	swap_a(a);
	swap_b(b);
}

void	push_a(t_stack *a, t_stack *b)
{
	int	temp;
	int	idx;

	if (b->size == 0)
		return ;
	temp = b->stk[0];
	idx = a->size - 1;
	while (idx >= 0)
	{
		a->stk[idx + 1] = a->stk[idx];
		idx--;
	}
	a->stk[0] = temp;
	a->size++;
	idx = 0;
	while (idx < b->size - 1)
	{
		b->stk[idx] = b->stk[idx + 1];
		idx++;
	}
	b->size--;
	ft_printf("pa\n");
	//print_stack(*a, *b);
}

void	push_b(t_stack *a, t_stack *b)
{
	int	temp;
	int	idx;

	if (a->size == 0)
		return ;
	temp = a->stk[0];
	idx = b->size - 1;
	while (idx >= 0)
	{
		b->stk[idx + 1] = b->stk[idx];
		idx--;
	}
	b->stk[0] = temp;
	b->size++;
	idx = 0;
	while (idx < a->size - 1)
	{
		a->stk[idx] = a->stk[idx + 1];
		idx++;
	}
	a->size--;
	ft_printf("pb\n");
	//print_stack(*a, *b);
}
