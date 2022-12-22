/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 20:30:08 by aait-mal          #+#    #+#             */
/*   Updated: 2022/12/22 22:04:31 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	main(int ac, char **av)
{
	int	*stack_a;
	int	*stack_b;
	int	stack_size;

	stack_size = check_valid_stack(ac, av, &stack_a);
	stack_b = ft_calloc(stack_size, sizeof(int));
	if (ac < 2 || !stack_size)
		ft_printf("Please include a valid stack !");
	else
	{
		sa(&stack_a, stack_size);
		display_stack(stack_a, stack_size);
	}
	return (0);
}
