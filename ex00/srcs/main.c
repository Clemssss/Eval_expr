/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clementg <clementg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 00:53:22 by clementg          #+#    #+#             */
/*   Updated: 2018/08/18 13:11:18 by clementgirard    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

int   main(int ac, char **av)
{
  if (ac > 1)
  {
    ft_putnbr(eval_expr(av[1]));
    ft_putchar('\n');
  }
  return (0);
}