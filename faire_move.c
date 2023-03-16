/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   faire_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btinturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:36:54 by btinturi          #+#    #+#             */
/*   Updated: 2023/03/16 16:35:05 by btinturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	do_rev_rotate_tout(t_stack **stack_a, t_stack **stack_b,
								int *cout_a, int *cout_b)
{
	while (*cout_a < 0 && *cout_b < 0)
	{
		(*cout_a)++;
		(*cout_b)++;
		fait_reverse_rotate_tout(stack_a, stack_b);
	}
}

static void	do_rotate_tout(t_stack **stack_a, t_stack **stack_b,
							int *cout_a, int *cout_b)
{
	while (*cout_a > 0 && *cout_b > 0)
	{
		(*cout_a)--;
		(*cout_b)--;
		fait_rotate_tout(stack_a, stack_b);
	}
}

static void	do_rotate_a(t_stack **stack_a, int *cout)
{
	while (*cout)
	{
		if (*cout > 0)
		{
			fait_rotate_a(stack_a);
			(*cout)--;
		}
		else if (*cout < 0)
		{
			fait_reverse_rotate_a(stack_a);
			(*cout)++;
		}
	}
}

static void	do_rotate_b(t_stack **stack_b, int *cout)
{
	while (*cout)
	{
		if (*cout > 0)
		{
			fait_rotate_b(stack_b);
			(*cout)--;
		}
		else if (*cout < 0)
		{
			fait_reverse_rotate_b(stack_b);
			(*cout)++;
		}
	}
}

void	faire_move(t_stack **st_a, t_stack **st_b, int ct_a, int ct_b)
{
	if (ct_a < 0 && ct_b < 0)
		do_rev_rotate_tout(st_a, st_b, &ct_a, &ct_b);
	else if (ct_a > 0 && ct_b > 0)
		do_rotate_tout(st_a, st_b, &ct_a, &ct_b);
	do_rotate_a(st_a, &ct_a);
	do_rotate_b(st_b, &ct_b);
	fait_push_a(st_a, st_b);
}
