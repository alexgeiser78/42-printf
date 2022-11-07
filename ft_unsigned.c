/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:12:48 by ageiser           #+#    #+#             */
/*   Updated: 2022/11/07 15:30:31 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

// cas unsigned %u
int	ft_nbrlen(unsigned int num)
{
	int	i;

	i = 0;
	while (num != 0)
	{
		i++;
		num = num / 10;
	}
	return (i);
}

char	*ft_unsigned_itoa(unsigned int nb)
{
	char	*num;
	size_t	len;

	len = ft_nbrlen(nb);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (nb != 0)
	{
		num[len - 1] = nb % 10 + 48;
		nb = nb / 10;
		len--;
	}
	return (num);
}	
// ligne 42 exemple: 784 | 784 % 10 = 4 | 4 + 48 = 4 ascii
// ligne 43 784 / 10 = 78 | retour ligne 107 exemple 78...

int	ft_unsigned_writer(unsigned int nb)
{
	int		print_length;
	char	*num;

	print_length = 0;
	if (nb == 0)
		print_length = print_length + write(1, "0", 1);
	else
	{	
	num = ft_unsigned_itoa(nb);
	print_length = print_length + ft_string_writer(num);
		free(num);
	}
	return (print_length);
}
