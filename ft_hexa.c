/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:45:25 by ageiser           #+#    #+#             */
/*   Updated: 2022/11/07 13:04:58 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

// cas hexa % x
void	ft_hexa_converter(unsigned int nb, const char format)
{
	if (nb >= 16)
	{
		ft_hexa_converter(nb / 16, format);
		ft_hexa_converter(nb % 16, format);
	}
	else
	{
		if (nb <= 9)
			ft_putchar_fd((nb + '0'), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((nb - 10 + 'a'), 1);
			if (format == 'X')
				ft_putchar_fd((nb - 10 + 'A'), 1);
		}
	}	
}

int	ft_hexa_writer(unsigned int nb, const char format)
{	
	if (nb == 0)
		return (write(1, "0", 1));
	else
		ft_hexa_converter(nb, format);
	return (ft_hexa_len(nb));
}	
