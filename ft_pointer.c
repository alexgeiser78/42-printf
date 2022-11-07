/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:55:03 by ageiser           #+#    #+#             */
/*   Updated: 2022/11/07 15:28:43 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

// cas print pointeur %p

int	ft_hexa_len(unsigned long long nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{	
		len++;
		nb = nb / 16;
	}	
	return (len);
}

void	ft_ptr_hexa_converter(unsigned long long nb)
{
	if (nb >= 16)
	{
		ft_ptr_hexa_converter(nb / 16);
		ft_ptr_hexa_converter(nb % 16);
	}
	else
	{
		if (nb <= 9)
			ft_putchar_fd((nb + '0'), 1);
		else
			ft_putchar_fd((nb - 10 + 'a'), 1);
	}	
}
//ligne 33 si nb est plus grand que 16, nb = nb / 16 jusqu'a ce que nb soit 
//plus petit que 16, on ecrit le premmier caractere selon regle ligne 41-43
//ligne 36, le caractere suivant sera le % 16 de la premiere division par 16, 
//ecrit selon la regle ligne 41 et 43
//ligne 36, le caractere suivant sera le % 16 de nb...
//
//ex:      987   -   -  -  11 
//    / 16  |  % 16        |
//          61   -   13    |
//    / 16  |        |     |
//          3        d     b

int	ft_pointer_writer(unsigned long long ptr)
{
	int	print_length;

	write(1, "0x", 2);
	print_length = 2;
	if (ptr == 0)
	{
		print_length = print_length + write(1, "0", 1);
	}	
	else
	{
		ft_ptr_hexa_converter(ptr);
		print_length = print_length + ft_hexa_len(ptr);
	}		
	return (print_length);
}
