/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:34:01 by yaboukir          #+#    #+#             */
/*   Updated: 2025/02/15 14:19:28 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	reset_vars(int *pid, int *p_bit, char *c, int *buffer_index)
{
	*pid = 0;
	*p_bit = 0;
	*c = 0;
	*buffer_index = 0;
}

void	write_buffer_and_msg(char *buffer, int *buffer_index, int pid)
{
	int	i;

	i = 0;
	while (i < *buffer_index)
	{
		ft_putchar_fd(buffer[i], 1);
		i++;
	}
	if (buffer[*buffer_index - 1] == '\0')
	{
		kill(pid, SIGUSR1);
	}
	*buffer_index = 0;
}

void	ft_btoa(int sig, siginfo_t *info, void *context)
{
	static int	pid = 0;
	static int	p_bit = 0;
	static char	c = 0;
	static char	buffer[4] = {0};
	static int	buffer_index = 0;

	(void)context;
	if (pid != info->si_pid)
		reset_vars(&pid, &p_bit, &c, &buffer_index);
	pid = info->si_pid;
	if (sig == SIGUSR1)
		c |= (1 << p_bit);
	p_bit++;
	if (p_bit == 8)
	{
		buffer[buffer_index++] = c;
		c = 0;
		p_bit = 0;
		if (buffer_index == 4 || buffer[buffer_index - 1] == '\0')
			write_buffer_and_msg(buffer, &buffer_index, pid);
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sig;

	pid = getpid();
	ft_putstr_fd(CY "SERVER PID IS : \e[0m", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n" GRN "Waiting to respond...\n" "\e[0m", 1);
	sig.sa_sigaction = ft_btoa;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}
