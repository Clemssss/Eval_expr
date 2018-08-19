/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clementg <clementg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 01:23:08 by clementg          #+#    #+#             */
/*   Updated: 2018/08/18 12:50:32 by clementgirard    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

int			ft_atoi(const char *str)
{
	int	res;
	int	i;
	int	sign;

	res = 0;
	i = 0;
	sign = 1;
	if (!str)
		return (0);
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\t'
		|| str[i] == '\n' || str[i] == '\r' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0') * sign;
		i++;
	}
	return (res);
}

void	ft_putnbr(int n)
{
	long	int	i;

	i = n;
	if (i < 0)
	{
		ft_putchar('-');
		i = i * -1;
	}
	if (i >= 10)
		ft_putnbr(i / 10);
	ft_putchar(i % 10 + '0');
}

void    ft_putchar(char c)
{
  write(1, &c, 1);
}

int     ft_strlen(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

void    ft_putstr(char *str)
{
  write(1, str, ft_strlen(str));
}

int     ft_isdigit(char c)
{
  if ((c >= '0' && c <= '9'))
    return (1);
  return (0);
}

int     ft_isop(char c)
{
  if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
    return (1);
  return (0);
}

int      ft_isprio(char pile, char op)
{
  if ((op == '*' || op == '/' || op == '%') && (pile == '-' || pile == '+'))
    return (1);
  return (0);
}
