/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:14:48 by jamendoe          #+#    #+#             */
/*   Updated: 2023/02/16 18:14:50 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minitalk.h"
#include "../includes/libft.h"

void	command_line_handler(int argc)
{
	char	*alt_morethreeargv;
	char	*alt_lessthreeargv;

	alt_morethreeargv = "You must enter only a message. sintax .\
	/client Server PID <message>\n";
	alt_lessthreeargv = "You must enter the Pid Server after a message. sintax \
	./client Server PID <message>\n";
	if (argc > 3)
	{
		write(1, alt_morethreeargv, ft_strlen(alt_morethreeargv));
		exit(0);
	}	
	if (argc < 3)
	{
		write(1, alt_lessthreeargv, ft_strlen(alt_lessthreeargv));
		exit(0);
	}
}

void	client_handler(int signum, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (signum == SIGUSR2)
		write(1, "Message received! Thank you!", 29);
}

void	send_int(pid_t pidclient, int len)
{
	int	i;

	i = 0;
	while (i <= 15)
	{
		if (((len >> (15 - i)) & 1) == 1)
			kill(pidclient, SIGUSR1);
		else
			kill(pidclient, SIGUSR2);
		i++;
		usleep(200);
	}
}

void	send_char(pid_t pidclient, char bit)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (((bit >> (7 - i)) & 1) == 1)
			kill(pidclient, SIGUSR1);
		else
			kill(pidclient, SIGUSR2);
		i++;
		usleep(200);
	}
}

int	main(int argc, char **argv)
{
	pid_t				pidclient;
	struct sigaction	sigclient;
	int					i;
	int					len;

	command_line_handler(argc);
	len = ft_strlen(argv[2]);
	i = 0;
	pidclient = ft_atoi(argv[1]);
	sigclient.sa_sigaction = &client_handler;
	if (sigaction(SIGUSR2, &sigclient, NULL) == -1)
		signal_run_handler(2);
	send_int(pidclient, len);
	while (i < len)
	{
		send_char(pidclient, argv[2][i]);
		i++;
	}
	send_char(pidclient, '\0');
	return (0);
}
