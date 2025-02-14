/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:08:52 by yaboukir          #+#    #+#             */
/*   Updated: 2025/02/14 15:08:55 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    ft_btoa(int sig, siginfo_t *info, void *context)
{
    static int pid;
    static int p_bit;
    static char c;

    (void)context;
    if (pid != info->si_pid)
    {
        pid = info->si_pid;
        p_bit = 0;
        c = 0;
    }
    if (sig == SIGUSR1)
    c |= (1 << p_bit);
    p_bit++;
    if (p_bit == 8)
    {
        ft_putchar_fd(c, 1);
        c = 0;
        p_bit = 0;
        pid = 0;
    }
}

int main(void)
{
    struct sigaction	sig;
    int					pid;
	
	pid = getpid();
	ft_putstr_fd(CY "SERVER PID IS : \e[0m", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n" GRN "Waiting to respond...\n" "\e[0m", 1);
	sig.sa_sigaction = ft_btoa;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while(1)
		pause();
	return (0);
}