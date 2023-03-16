/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btinturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:36:54 by btinturi          #+#    #+#             */
/*   Updated: 2023/03/16 16:35:20 by btinturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				valeur;
	int				index;
	int				position;
	int				position_cible;
	int				cout_a;
	int				cout_b;
	struct s_stack	*suivant;
}	t_stack;

//push
void		fait_push_a(t_stack **stack_a, t_stack **stack_b);
void		fait_push_b(t_stack **stack_a, t_stack **stack_b);

//gestion stack
t_stack		*get_stack_fin(t_stack *stack);
t_stack		*get_stack_avant_fin(t_stack *stack);
t_stack		*stack_new(int value);
void		stack_ajout_fin(t_stack **stack, t_stack *nouv);
int			get_stack_taille(t_stack *stack);

//reverse rotate
void		fait_reverse_rotate_a(t_stack **stack_a);
void		fait_reverse_rotate_b(t_stack **stack_b);
void		fait_reverse_rotate_tout(t_stack **stack_a, t_stack **stack_b);

//rotate
void		fait_rotate_a(t_stack **stack_a);
void		fait_rotate_b(t_stack **stack_b);
void		fait_rotate_tout(t_stack **stack_a, t_stack **stack_b);

//swap
void		fait_swap_a(t_stack **stack_a);
void		fait_swap_b(t_stack **stack_b);
void		fait_swap_a_b(t_stack **stack_a, t_stack **stack_b);

//cout
void		get_cout(t_stack **stack_a, t_stack **stack_b);
void		faire_mouv_plusleger(t_stack **stack_a, t_stack **stack_b);

//utils
void		free_stack(t_stack **stack);
void		exit_erreur(t_stack **stack_a, t_stack **stack_b);
long int	ft_atoi(const char *str);
int			nb_abs(int nb);

//input utils
int			is_digit(char c);
int			is_sign(char c);
int			nbstr_cmp(const char *s1, const char *s2);

//faire move
void		faire_move(t_stack **st_a, t_stack **st_b, int ct_a, int ct_b);

//init
t_stack		*fill_stack(int argc, char **argv);
void		assign_index(t_stack *stack_a, int taille_stack);

//input_verif
int			input_correct(char **argv);

//position
int			get__index_pos_lowest(t_stack **stack);
void		get_target_position(t_stack **stack_a, t_stack **stack_b);

//main
int			est_trie(t_stack *stack);

//petit trie
void		petit_tri(t_stack **stack);

//trie
void		trie(t_stack **stack_a, t_stack **stack_b);
#endif
