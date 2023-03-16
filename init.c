/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btinturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:36:54 by btinturi          #+#    #+#             */
/*   Updated: 2023/03/16 15:53:45 by btinturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_stack	*fill_stack(int argc, char **argv)
{
	t_stack		*stack_a;
	long int	nb;
	int			i;

	stack_a = NULL;
	nb = 0;
	i = 1;
	while (i < argc)
	{
		nb = ft_atoi(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			exit_erreur(&stack_a, NULL);
		if (i == 1)
			stack_a = stack_new((int)nb);
		else
			stack_ajout_fin(&stack_a, stack_new((int)nb));
		i++;
	}
	return (stack_a);
}

void	assign_index(t_stack *stack_a, int taille_stack)
{
	t_stack	*ptr;
	t_stack	*plushaut;
	int		val;

	while (--taille_stack > 0)
	{
		ptr = stack_a;
		val = INT_MIN;
		plushaut = NULL;
		while (ptr)
		{
			if (ptr->valeur == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->valeur > val && ptr->index == 0)
			{
				val = ptr->valeur;
				plushaut = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->suivant;
		}
		if (plushaut != NULL)
			plushaut->index = taille_stack;
	}
}
