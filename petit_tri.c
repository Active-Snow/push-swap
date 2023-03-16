/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   petit_tri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btinturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:36:54 by btinturi          #+#    #+#             */
/*   Updated: 2023/03/16 16:00:22 by btinturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

//trouve l'index le plus haut dans une stack
static int	trouve_index_plushaut(t_stack *stack)
{
	int	index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->suivant;
	}
	return (index);
}

void	petit_tri(t_stack **stack)
{
	int	haut;

	if (est_trie(*stack))
		return ;
	haut = trouve_index_plushaut(*stack);
	if ((*stack)->index == haut)
		fait_rotate_a(stack);
	else if ((*stack)->suivant->index == haut)
		fait_reverse_rotate_a(stack);
	if ((*stack)->index > (*stack)->suivant->index)
		fait_swap_a(stack);
}
