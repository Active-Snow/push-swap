/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btinturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:36:54 by btinturi          #+#    #+#             */
/*   Updated: 2023/03/16 15:58:19 by btinturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	est_trie(t_stack *stack)
{
	while (stack->suivant != NULL)
	{
		if (stack->valeur > stack->suivant->valeur)
			return (0);
		stack = stack->suivant;
	}
	return (1);
}

static void	push_swap(t_stack **stack_a, t_stack **stack_b, int taille_stack)
{
	if (taille_stack == 2 && !est_trie(*stack_a))
		fait_swap_a(stack_a);
	else if (taille_stack == 3)
		petit_tri(stack_a);
	else if (taille_stack > 3 && !est_trie(*stack_a))
		trie(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	if (argc < 2)
		return (0);
	if (!input_correct(argv))
		exit_erreur(NULL, NULL);
	stack_b = NULL;
	stack_a = fill_stack(argc, argv);
	stack_size = get_stack_taille(stack_a);
	assign_index(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
