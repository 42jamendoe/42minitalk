/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:15:15 by jamendoe          #+#    #+#             */
/*   Updated: 2023/02/16 18:15:17 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>

void	send_char(pid_t pidclient, char bit);
void	send_int(pid_t pidclient, int len);
void	command_line_handler(int argc);
void	send_char(pid_t pidclient, char bit);
void	send_int(pid_t pidclient, int len);
void	command_line_handler(int argc);
void	signal_run_handler(int alert);

#endif