/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_putusnbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:23:44 by jamendoe          #+#    #+#             */
/*   Updated: 2022/11/12 18:23:49 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

int	ft_lenght_number(int number)
{
	int	len_number;

	len_number = 0;
	if (number < 0)
	{
		number *= -1;
		len_number++;
	}
	while (number != 0)
	{
		number = number / 10;
		len_number++;
	}
	return (len_number);
}

void	ft_write_number(unsigned int n)
{
	if (n > 9)
	{
		ft_pf_putnbr(n / 10);
		ft_pf_putnbr(n % 10);
	}
	else
	{
		n = n + 48;
		write(1, &n, 1);
	}
}

int	ft_pf_putusnbr(unsigned int n)
{
	ft_write_number(n);
	return (ft_lenght_number(n));
}
