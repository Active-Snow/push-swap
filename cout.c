/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cout.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btinturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:36:54 by btinturi          #+#    #+#             */
/*   Updated: 2023/03/16 15:44:46 by btinturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

// cout_a = cout pour mettre dans la bonne pos dans la stack a
// cost_b = cout pour mettre en haut de stack_b
// si cout neg => element dans la moitié du bas
// si cout pos => element dans la moitié du haut
void	get_cout(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		taille_a;
	int		taille_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	taille_a = get_stack_taille(tmp_a);
	taille_b = get_stack_taille(tmp_b);
	while (tmp_b)
	{
		tmp_b->cout_b = tmp_b->position;
		if (tmp_b-> position > taille_b / 2)
			tmp_b->cout_b = (taille_b - tmp_b->position) * -1;
		tmp_b->cout_a = tmp_b->position_cible;
		if (tmp_b->position_cible > taille_a / 2)
			tmp_b->cout_a = (taille_a - tmp_b->position_cible) * -1;
		tmp_b = tmp_b->suivant;
	}
}

void	faire_mouv_plusleger(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		moinscher;
	int		cout_a;
	int		cout_b;

	tmp = *stack_b;
	moinscher = INT_MAX;
	while (tmp)
	{
		if (nb_abs(tmp->cout_a) + nb_abs(tmp->cout_b) < nb_abs(moinscher))
		{
			moinscher = nb_abs(tmp->cout_b) + nb_abs(tmp->cout_a);
			cout_a = tmp->cout_a;
			cout_b = tmp->cout_b;
		}
		tmp = tmp->suivant;
	}
	faire_move(stack_a, stack_b, cout_a, cout_b);
}
