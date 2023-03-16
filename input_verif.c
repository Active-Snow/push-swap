/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_verif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btinturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:36:54 by btinturi          #+#    #+#             */
/*   Updated: 2023/03/16 15:57:30 by btinturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	arg_is_number(char *argv)
{
	int	i;

	i = 0;
	if (is_sign(argv[i]) && argv[i + 1] != '\0')
		i++;
	while (argv[i] && is_digit(argv[i]))
		i++;
	if (argv[i] != '\0' && !is_digit(argv[i]))
		return (0);
	return (1);
}

static int	have_dup(char **argv)
{
	int	n;
	int	i;

	n = 1;
	while (argv[n])
	{
		i = 1;
		while (argv[i])
		{
			if (i != n && nbstr_cmp(argv[n], argv[i]) == 0)
				return (1);
			i++;
		}
		n++;
	}
	return (0);
}

// if 0 ou pareil contenu = retour 1 sinon 0
static int	arg_is_zero(char *argv)
{
	int	n;

	n = 0;
	if (is_sign(argv[n]))
		n++;
	while (argv[n] && argv[n] == '0')
		n++;
	if (argv[n] != '\0')
		return (0);
	return (1);
}

//verifie linput 1 si valide 0 si non
int	input_correct(char **argv)
{
	int	n;
	int	nb_zero;

	nb_zero = 0;
	n = 1;
	while (argv[n])
	{
		if (!arg_is_number(argv[n]))
			return (0);
		nb_zero += arg_is_zero(argv[n]);
		n++;
	}
	if (nb_zero > 1)
		return (0);
	if (have_dup(argv))
		return (0);
	return (1);
}
