/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btinturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:36:54 by btinturi          #+#    #+#             */
/*   Updated: 2023/03/16 16:14:29 by btinturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_stack	*get_stack_fin(t_stack *stack)
{
	while (stack && stack->suivant != NULL)
		stack = stack->suivant;
	return (stack);
}

t_stack	*get_stack_avant_fin(t_stack *stack)
{
	while (stack && stack->suivant && stack->suivant->suivant != NULL)
		stack = stack->suivant;
	return (stack);
}

t_stack	*stack_new(int value)
{
	t_stack	*new;

	new = malloc(sizeof * new);
	if (!new)
		return (NULL);
	new->valeur = value;
	new->index = 0;
	new->position = -1;
	new->position_cible = -1;
	new->cout_a = -1;
	new->cout_b = -1;
	new->suivant = NULL;
	return (new);
}

void	stack_ajout_fin(t_stack **stack, t_stack *new)
{
	t_stack	*tail;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tail = get_stack_fin(*stack);
	tail->suivant = new;
}

int	get_stack_taille(t_stack *stack)
{
	int	taille;

	taille = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->suivant;
		taille++;
	}
	return (taille);
}
