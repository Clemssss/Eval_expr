/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clementg <clementg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 01:06:17 by clementg          #+#    #+#             */
/*   Updated: 2018/08/18 01:07:47 by clementgirard    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

int   ft_add(int nb1, int nb2)
{
  return (nb1 + nb2);
}

int   ft_sub(int nb1, int nb2)
{
  return (nb1 - nb2);
}

int   ft_mul(int nb1, int nb2)
{
  return (nb1 * nb2);
}

int   ft_div(int nb1, int nb2)
{
  return (nb1 / nb2);
}

int   ft_mod(int nb1, int nb2)
{
  return (nb1 % nb2);
}
