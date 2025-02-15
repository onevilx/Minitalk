/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:34:15 by yaboukir          #+#    #+#             */
/*   Updated: 2025/02/15 16:02:51 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_receive(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr_fd(GRN "Message acknowledged.\n" "\e[0m", 1);
}

void	ft_message_sig(int pid, char c)
{
	int	signal;
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (1 << bit))
			signal = SIGUSR1;
		else
			signal = SIGUSR2;
		if (kill(pid, signal) == -1)
		{
			ft_putstr_fd(RED "Invalid PID, Signal Error.\n" "\e[0m", 2);
			exit(1);
		}
		usleep(100);
		bit++;
	}
}

int	check_validation(char *pid_str)
{
	int	i;
	int	pid;

	i = 0;
	while (pid_str[i])
	{
		if (!ft_isdigit(pid_str[i]))
		{
			ft_putstr_fd(RED "PID has no digit.\n" "\e[0m", 2);
			return (0);
		}
		i++;
	}
	pid = ft_atoi(pid_str);
	if (pid <= 0)
	{
		ft_putstr_fd(RED "PID is a NEGATIVE !\n" "\e[0m", 2);
		return (0);
	}
	return (pid);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3 && argv[2][0] != '\0')
	{
		pid = check_validation(argv[1]);
		if (pid != 0)
		{
			ft_putstr_fd(GRN "PID IS VALID, reaching server...\n" "\e[0m", 1);
			signal(SIGUSR1, handle_receive);
			while (argv[2][i])
				ft_message_sig(pid, argv[2][i++]);
			ft_message_sig(pid, '\0');
		}
	}
	else
	{
		ft_putstr_fd(RED "invalid args or empty message.\n" "\e[0m", 2);
		ft_putstr_fd(YLW "Usage: ./client [PID] [MSG]\n" "\e[0m", 2);
	}
	return (0);
}
