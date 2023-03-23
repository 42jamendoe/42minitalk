/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:14:14 by jamendoe          #+#    #+#             */
/*   Updated: 2023/02/16 18:14:23 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minitalk.h"
#include "../includes/libft.h"

int	receive_int(int signum, int bit, int msg_len)
{
	if (signum == SIGUSR1)
		msg_len = msg_len | (1 << (15 - bit));
	return (msg_len);
}

char	*memory_alocation(int msg_len, char *msg)
{
	msg = (char *)malloc(msg_len + 1);
	if (!msg)
		return (NULL);
	return (msg);
}

char	receive_char(int signum, int bit)
{
	static char	c = '\0';
	int			i;

	i = (bit - 16) % 8;
	if (i == 0)
		c = '\0';
	if (signum == SIGUSR1)
		c = c | 1 << (7 - i);
	return (c);
}

void	server_handler(int signum, siginfo_t *info, void *context)
{
	static int	bit = 0;
	static int	msg_len = 0;
	static char	*msg;

	(void)info;
	(void)context;
	if (bit <= 15)
		msg_len = receive_int(signum, bit, msg_len);
	if (bit == 16)
		msg = memory_alocation(msg_len, msg);
	if (bit > 15 && bit < (16 + ((msg_len + 1) * 8)))
		msg[(bit - 16) / 8] = receive_char(signum, bit);
	if (bit == (15 + ((msg_len + 1) * 8)))
	{
		write(1, msg, msg_len + 1);
		free((void *)msg);
		bit = -1;
		msg_len = 0;
	}
	bit++;
}

int	main(void)
{
	pid_t				pidserver;
	struct sigaction	sigserver;

	pidserver = getpid();
	ft_printf("SERVER PID: %d\n", pidserver);
	while (1)
	{
		sigserver.sa_sigaction = &server_handler;
		if (sigaction(SIGUSR1, &sigserver, NULL) == -1)
			signal_run_handler(1);
		if (sigaction(SIGUSR2, &sigserver, NULL) == -1)
			signal_run_handler(2);
	}
	return (0);
}
