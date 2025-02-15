/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:09:02 by yaboukir          #+#    #+#             */
/*   Updated: 2025/02/15 14:21:12 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_isdigit(int c)
{
	return (c >= 48 && 57 >= c);
}

int	ft_atoi(const char *str)
{
	long	res;
	int		store;
	int		i;
	int		sign;

	res = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		store = res;
		res = (res * 10) + (str[i++] - '0');
		if (store != (res / 10) && sign == 1)
			return (-1);
		if (store != (res / 10) && sign == -1)
			return (0);
	}
	return (res * sign);
}

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	if (!str || fd < 0)
		return ;
	while (str[i])
	{
		ft_putchar_fd(str[i], fd);
		i++;
	}
}

void	ft_putnbr_fd(int nb, int fd)
{
	long	number;
	int		res;

	number = nb;
	if (fd < 0)
		return ;
	if (number < 0)
	{
		write(fd, "-", 1);
		number *= -1;
	}
	if (number / 10 > 0)
		ft_putnbr_fd(number / 10, fd);
	res = number % 10 + '0';
	write(fd, &res, 1);
}
