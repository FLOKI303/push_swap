/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:49:26 by adnane            #+#    #+#             */
/*   Updated: 2023/02/12 15:40:34 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	divide_chunks(t_list *stack)
{
	int	chunk;
	int	size;

	size = ft_lstsize(stack);
	if (size <= 20)
		chunk = size;
	else if (size <= 200)
		chunk = size / 5;
	else if (size <= 500)
		chunk = size / 8;
	else
		chunk = size / 12;
	return (chunk);
}

void	sort_three(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	if (is_sorted(*stack))
		return ;
	if (tmp->index > tmp->next->index && tmp->index < tmp->next->next->index)
		sa(stack);
	else if (tmp->index > tmp->next->index
		&& tmp->next->index > tmp->next->next->index)
	{
		sa(stack);
		rra(stack);
	}
	else if (tmp->index > tmp->next->index
		&& tmp->index > tmp->next->next->index
		&& tmp->next->index < tmp->next->next->index)
		ra(stack);
	else if (tmp->index < tmp->next->index
		&& tmp->index < tmp->next->next->index)
	{
		sa(stack);
		ra(stack);
	}
	else
		rra(stack);
}

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	rotate_min(stack_a);
	if (is_sorted(*stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	rotate_min(stack_a);
	if (is_sorted(*stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_four(stack_a, stack_b);
	pa(stack_a, stack_b);
	return ;
}
