/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:05:57 by tayeo             #+#    #+#             */
/*   Updated: 2022/11/05 16:51:06 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int	size;
	int	*stk;
}	t_stack;

void print_stack(t_stack a, t_stack b);

void	swap_a(t_stack *a);
void	swap_b(t_stack *b);
void	swap_swap(t_stack *a, t_stack *b);

void	push_a(t_stack *a, t_stack *b);
void	push_b(t_stack *a, t_stack *b);

void	rot_a(t_stack *a);
void	rot_b(t_stack *b);
void	rev_rot_a(t_stack *a);
void	rev_rot_b(t_stack *b);
void	rr(t_stack *a, t_stack *b);

void	sort(t_stack *a1, t_stack *b1);
#endif
