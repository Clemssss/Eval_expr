/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clementg <clementg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 00:55:17 by clementg          #+#    #+#             */
/*   Updated: 2018/08/18 12:51:27 by clementgirard    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVAL_EXPR_H
# define EVAL_EXPR_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

typedef struct  s_ptr_tab
{
  char  op;
  int   (*f)(int nb1, int nb2);
}     t_ptr_tab;

typedef struct  s_pile_calc
{
  int   bol;
  int   nb;
  char  op;
  struct  s_pile_calc *prev;
  struct  s_pile_calc *next;
}     t_pile_calc;

typedef struct  s_pile_op
{
  char  op;
  struct  s_pile_op *prev;
  struct  s_pile_op *next;
}     t_pile_op;

//    calc.c
int     ft_add(int nb1, int nb2);
int     ft_sub(int nb1, int nb2);
int     ft_mul(int nb1, int nb2);
int     ft_div(int nb1, int nb2);
int     ft_mod(int nb1, int nb2);

//    main.c
int     eval_expr(char *calc);

//    functions.c
int     ft_atoi(const char *str);
void    ft_putnbr(int n);
void    ft_putchar(char c);
int     ft_strlen(char *str);
void    ft_putstr(char *str);
int     ft_isdigit(char c);
int     ft_isop(char c);
int     ft_isprio(char pile, char op);

//    pile_calc.c
int     ft_pushback_calc_nb(t_pile_calc **lst, int nb);
int     ft_pushback_calc_op(t_pile_calc **lst, char op);
void    ft_print_calc(t_pile_calc *lst);
void    ft_del_calcrpn(t_pile_calc **calc);
void    free_pile_calc(t_pile_calc *lst);

//    pile_op.c
int     ft_pushback_op(t_pile_op **lst, char op);
void    ft_print_op(t_pile_op *lst);
t_pile_op   *ft_last_op(t_pile_op *lst);
void    ft_del_lastop(t_pile_op **lst);
void    free_pile_op(t_pile_op *lst);

#endif
