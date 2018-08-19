/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clementg <clementg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 01:36:22 by clementg          #+#    #+#             */
/*   Updated: 2018/08/18 12:45:10 by clementgirard    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

static  t_pile_calc   *create_elem(int bol, int nb, char op)
{
  t_pile_calc   *new;

  if (!(new = (t_pile_calc*)malloc(sizeof(t_pile_calc))))
    return (NULL);
  new->bol = bol;
  new->nb = 0;
  new->op = 0;
  if (bol)
    new->nb = nb;
  else
    new->op = op;
  new->prev = NULL;
  new->next = NULL;
  return (new);
}

int    ft_pushback_calc_nb(t_pile_calc **lst, int nb)
{
  t_pile_calc *new;
  t_pile_calc *tmp;

  if (!(new = create_elem(1, nb, 0)))
    return (0);
  if (!*lst)
    *lst = new;
  else
  {
    tmp = *lst;
    while (tmp->next)
      tmp = tmp->next;
    tmp->next = new;
    new->prev = tmp;
  }
  return (1);
}

int    ft_pushback_calc_op(t_pile_calc **lst, char op)
{
  t_pile_calc *new;
  t_pile_calc *tmp;

  if (op == '(' || op == ')')
    return (1);
  if (!(new = create_elem(0, 0, op)))
    return (0);
  if (!*lst)
    *lst = new;
  else
  {
    tmp = *lst;
    while (tmp->next)
      tmp = tmp->next;
    tmp->next = new;
    new->prev = tmp;
  }
  return (1);
}

void     ft_print_calc(t_pile_calc *pile_calc)
{
  t_pile_calc   *tmp;
  int           i;

  if (!pile_calc)
    return ;
  tmp = pile_calc;
  i = 0;
  while (tmp)
  {
    if (tmp->bol)
      printf("%d : nb = %d\n", i, tmp->nb);
    else
      printf("%d : op = %c\n", i, tmp->op);
    tmp = tmp->next;
    i++;
  }
}

void      ft_del_calcrpn(t_pile_calc **calc)
{
  t_pile_calc   *tmp;

  tmp = (*calc)->prev->prev;
  (*calc)->prev->prev->next = (*calc)->next;
  if ((*calc)->next)
    (*calc)->next->prev = (*calc)->prev->prev;
  free((*calc)->prev);
  free((*calc));
  *calc = NULL;
  *calc = tmp;
}

void      free_pile_calc(t_pile_calc *lst)
{
  while (lst)
  {
    free(lst);
    lst = lst->next;
  }
}
