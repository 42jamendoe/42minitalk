/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:17:12 by jamendoe          #+#    #+#             */
/*   Updated: 2023/02/16 18:17:13 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minitalk_bonus.h"
#include "../includes/libft.h"

void	signal_run_handler(int alert)
{
	char	*alt_nsigusr1;
	char	*alt_nsigusr2;

	alt_nsigusr1 = "Failed to handle SIGUSR1 signal! exiting...\n";
	alt_nsigusr2 = "Failed to handle SIGUSR2 signal! exiting...\n";
	if (alert == 1)
	{
		write(1, alt_nsigusr1, ft_strlen(alt_nsigusr1));
		exit(0);
	}
	if (alert == 2)
	{
		write(1, alt_nsigusr2, ft_strlen(alt_nsigusr2));
		exit(0);
	}
}
