/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:08:48 by yaboukir          #+#    #+#             */
/*   Updated: 2025/02/14 14:45:11 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
#define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

# define PUR "\033[0;35m"
# define CY "\033[0;36m"
# define RED "\033[0;31m"
# define GRN "\033[0;32m"

int		ft_isdigit(int c);
int		ft_atoi(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putnbr_fd(int nb, int fd);

#endif