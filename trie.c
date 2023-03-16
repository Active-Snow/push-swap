/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btinturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:36:54 by btinturi          #+#    #+#             */
/*   Updated: 2023/03/16 16:17:23 by btinturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

//push tout a dans b sauf les 3 dernier
// envoi dans l'ordre croissant
static void	pushtout_sauf(t_stack **stack_a, t_stack **stack_b)
{
	int	taille_stack;
	int	pushed;
	int	n;

	taille_stack = get_stack_taille(*stack_a);
	pushed = 0;
	n = 0;
	while (taille_stack > 6 && n < taille_stack && pushed < taille_stack / 2)
	{
		if ((*stack_a)->index <= taille_stack / 2)
		{
			fait_push_b(stack_a, stack_b);
			pushed++;
		}
		else
			fait_rotate_a(stack_a);
		n++;
	}
	while (taille_stack - pushed > 3)
	{
		fait_push_b(stack_a, stack_b);
		pushed++;
	}
}

//mets le plus bas de a en haut
static void	shift_stack(t_stack **stack_a)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = get_stack_taille(*stack_a);
	lowest_pos = get__index_pos_lowest(stack_a);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			fait_reverse_rotate_a(stack_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			fait_rotate_a(stack_a);
			lowest_pos--;
		}
	}
}

void	trie(t_stack **stack_a, t_stack **stack_b)
{
	pushtout_sauf(stack_a, stack_b);
	petit_tri(stack_a);
	while (*stack_b)
	{
		get_target_position(stack_a, stack_b);
		get_cout(stack_a, stack_b);
		faire_mouv_plusleger(stack_a, stack_b);
	}
	if (!est_trie(*stack_a))
		shift_stack(stack_a);
}
