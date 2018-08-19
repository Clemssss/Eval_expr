/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clementg <clementg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 01:50:24 by clementg          #+#    #+#             */
/*   Updated: 2018/08/18 12:45:24 by clementgirard    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

static  t_pile_op   *create_elem(char op)
{
  t_pile_op   *new;

  if (!(new = (t_pile_op*)malloc(sizeof(t_pile_op))))
    return (NULL);
  new->op = op;
  new->next = NULL;
  new->prev = NULL;
  return (new);
}

int      ft_pushback_op(t_pile_op **lst, char op)
{
  t_pile_op   *new;
  t_pile_op   *tmp;

  if (!(new = create_elem(op)))
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

t_pile_op   *ft_last_op(t_pile_op *lst)
{
  t_pile_op   *tmp;

  tmp = lst;
  while (tmp && tmp->next)
    tmp = tmp->next;
  return (tmp);
}

void    ft_del_lastop(t_pile_op **lst)
{
  t_pile_op   *tmp;

  if (!lst)
    return ;
  tmp = *lst;
  while (tmp && tmp->next)
    tmp = tmp->next;
  tmp->op = 0;
  if (tmp->prev)
  {
    tmp->prev->next = NULL;
    tmp->prev = NULL;
    free(tmp);
  }
  else
  {
    free(*lst);
    *lst = NULL;
  }
}

void    ft_print_op(t_pile_op *lst)
{
  t_pile_op   *tmp;
  int         i;

  if (!lst)
    return ;
  tmp = lst;
  i = 0;
  while (tmp)
  {
    printf("%d : op = %c\n", i, tmp->op);
    tmp = tmp->next;
    i++;
  }
}

void      free_pile_op(t_pile_op *lst)
{
  while (lst)
  {
    free(lst);
    lst = lst->next;
  }
}
