/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:15:27 by jamendoe          #+#    #+#             */
/*   Updated: 2023/02/16 18:15:29 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <signal.h>

void	send_char(pid_t pidclient, char bit);
void	send_int(pid_t pidclient, int len);
void	client_handler(int signum, siginfo_t *info, void *context);
void	command_line_handler(int argc);
void	server_handler(int signum, siginfo_t *info, void *context);
char	receive_char(int signum, int bit);
char	*memory_alocation(int msg_len, char *msg);
void	signal_run_handler(int alert);
int		receive_int(int signum, int bit, int msg_len);

#endif
