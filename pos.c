/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btinturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:36:54 by btinturi          #+#    #+#             */
/*   Updated: 2023/03/16 16:08:19 by btinturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

//assignement de la position des elemenbt de la stack
//utile pour le calcul du cout
static void	get_position(t_stack **stack)
{
	t_stack	*tmp;
	int		n;

	tmp = *stack;
	n = 0;
	while (tmp)
	{
		tmp->position = n;
		tmp = tmp->suivant;
		n++;
	}
}

int	get__index_pos_lowest(t_stack **stack)
{
	t_stack	*tmp;
	int		lowest_position;
	int		lowest_index;

	tmp = *stack;
	lowest_index = INT_MAX;
	get_position(stack);
	lowest_position = tmp->position;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_position = tmp->position;
		}
		tmp = tmp->suivant;
	}
	return (lowest_position);
}

//chope meilleure position dans la stack pour
// l'index donné d'un element de b
static int	get_target(t_stack **stack_a, int index_b,
						int index_t, int position_target)
{
	t_stack	*tmp_a;

	tmp_a = *stack_a;
	while (tmp_a)
	{
		if (tmp_a->index > index_b && tmp_a->index < index_t)
		{
			index_t = tmp_a->index;
			position_target = tmp_a->position;
		}
		tmp_a = tmp_a->suivant;
	}
	if (index_t != INT_MAX)
		return (position_target);
	tmp_a = *stack_a;
	while (tmp_a)
	{
		if (tmp_a->index < index_t)
		{
			index_t = tmp_a->index;
			position_target = tmp_a->position;
		}
		tmp_a = tmp_a->suivant;
	}
	return (position_target);
}

// assignement une position  dans la stack a à
// chaque element de la stack a
void	get_target_position(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_b;
	int		pos_target;

	tmp_b = *stack_b;
	get_position(stack_a);
	get_position(stack_b);
	pos_target = 0;
	while (tmp_b)
	{
		pos_target = get_target(stack_a, tmp_b->index, INT_MAX, pos_target);
		tmp_b->position_cible = pos_target;
		tmp_b = tmp_b->suivant;
	}
}
