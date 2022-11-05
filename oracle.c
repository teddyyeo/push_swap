/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oracle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 16:25:40 by tayeo             #+#    #+#             */
/*   Updated: 2022/11/05 17:43:31 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		min3(int a, int b, int c)
{
	if (a < b && a < c)
		return (a);
	else if (b < c)
		return (b);
	else
		return (c);
}

int		max3(int a, int b, int c)
{
	if (a > b && a > c)
		return (a);
	else if (b > c)
		return (b);
	else
		return (c);
}

int		mid3(int a, int b, int c)
{
	if (min3(a, b, c) != a && max3(a, b, c) != a)
		return (a);
	else if (min3(a, b, c) != b && max3(a, b, c) != b)
		return (b);
	else
		return (c);
}

int	sorted(t_stack a)
{
	int	idx;

	idx = 0;
	while (idx < a.size)
	{
		if (a.stk[idx] > a.stk[idx + 1])
			return (0);
	}
	return (1);
}

void	sort(t_stack *a1, t_stack *b1)
{
	int *a = a1->stk;
	int s = a1->size - 1;
	int	min;

	if (s == -1)
	{
		while (b1->size > 0)
			push_a(a1, b1);
		return ;
	}
	min = min3(a[0], a[1], a[s]);
	if (min < b1->stk[0])
		min = mid3(a[0], a[1], a[s]);
	if (min < b1->stk[0])
		min = max3(a[0], a[1], a[s]);
	if (b1->size == 0 || min > b1->stk[0])
	{
		if (min == a[0])
			push_b(a1, b1);
		else if (min == a[1])
		{
			rot_a(a1);
			push_b(a1, b1);
		}
		else
		{
			rev_rot_a(a1);
			push_b(a1, b1);
		}
	}
}
