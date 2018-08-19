/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clementg <clementg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 01:00:45 by clementg          #+#    #+#             */
/*   Updated: 2018/08/18 13:10:23 by clementgirard    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

t_ptr_tab g_ptr[5] =
{
  { '+', &ft_add },
  { '-', &ft_sub },
  { '*', &ft_mul },
  { '/', &ft_div },
  { '%', &ft_mod }
};

int   call_fct(char c, int nb1, int nb2)
{
  int   i;

  i = 0;
  while (i < 5)
  {
    if (c == g_ptr[i].op)
      return (g_ptr[i].f(nb1, nb2));
    i++;
  }
  return (0);
}

int   interpret_rpn(t_pile_calc *lst)
{
  t_pile_calc   *calc;

  calc = lst;
  while (calc)
  {
    if (!calc->bol)
    {
      if (calc->prev && calc->prev->prev)
      {
        calc->prev->prev->nb = call_fct(calc->op, calc->prev->prev->nb, calc->prev->nb);
        ft_del_calcrpn(&calc);
      }
    }
    else
      calc = calc->next;
  }
  return (lst->nb);
}

int    eval_expr(char *calc)
{
  int           i;
  int           ret;
  t_pile_op     *pile_op;
  t_pile_calc   *pile_calc;

  if ((!(pile_op = (t_pile_op*)malloc(sizeof(t_pile_op))))
      || (!(pile_calc = (t_pile_calc*)malloc(sizeof(t_pile_calc)))))
    return (0);
  pile_op = NULL;
  pile_calc = NULL;
  i = 0;
  while (calc[i])
  {
    if (ft_isdigit(calc[i])
      || (calc[i] == '-' && calc[i + 1] && ft_isdigit(calc[i + 1])))
    {
      ft_pushback_calc_nb(&pile_calc, ft_atoi(&calc[i]));
      if (calc[i] == '-')
        i++;
      while (calc[i] && ft_isdigit(calc[i]))
        i++;
    }
    else if (calc[i] == '(')
      ft_pushback_op(&pile_op, calc[i++]);
    else if (ft_isop(calc[i]))
    {
      if (!pile_op)
        ft_pushback_op(&pile_op, calc[i]);
      else if (ft_last_op(pile_op)->op == '(')
        ft_pushback_op(&pile_op, calc[i]);
      else if (ft_isprio(ft_last_op(pile_op)->op, calc[i]))
        ft_pushback_op(&pile_op, calc[i]);
      else
      {
        ft_pushback_calc_op(&pile_calc, ft_last_op(pile_op)->op);
        ft_del_lastop(&pile_op);
        ft_pushback_op(&pile_op, calc[i]);
      }
      i++;
    }
    else if (calc[i] == ')')
    {
      while (ft_last_op(pile_op)->op != '(')
      {
        ft_pushback_calc_op(&pile_calc, ft_last_op(pile_op)->op);
        ft_del_lastop(&pile_op);
      }
      ft_del_lastop(&pile_op);
      i++;
    }
    else
      i++;
  }
  while (pile_op)
  {
    ft_pushback_calc_op(&pile_calc, ft_last_op(pile_op)->op);
    ft_del_lastop(&pile_op);
  }
  ret = interpret_rpn(pile_calc);
  free_pile_calc(pile_calc);
  free_pile_op(pile_op);
  return (ret);
}
