/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btinturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:36:54 by btinturi          #+#    #+#             */
/*   Updated: 2023/03/16 16:15:55 by btinturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	swap(t_stack *stack)
{
	int	tmp;

	if (stack == NULL || stack->suivant == NULL)
		return ;
	tmp = stack->valeur;
	stack->valeur = stack->suivant->valeur;
	stack->suivant->valeur = tmp;
	tmp = stack->index;
	stack->index = stack->suivant->index;
	stack->suivant->index = tmp;
}

void	fait_swap_a(t_stack **stack_a)
{
	swap(*stack_a);
	write(1, "sa\n", 3);
}

void	fait_swap_b(t_stack **stack_b)
{
	swap(*stack_b);
	write(1, "sb\n", 3);
}

void	fait_swap_a_b(t_stack **stack_a, t_stack **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	write(1, "ss\n", 3);
}
