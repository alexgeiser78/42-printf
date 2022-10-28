/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:02:00 by ageiser           #+#    #+#             */
/*   Updated: 2022/10/28 17:29:57 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h> // printf

// cas print char %c
static int	ft_char_writer(int c)
{
	if (write(1, &c, 1) < 0)
		return (-1);
	else
		return (1);
}	
// ligne 20 protection de la fonction

// cas print string %s
static int	ft_string_writer(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}	
// cas print pointeur %p

static int	ft_hexa_len(unsigned long long nb)
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

static void	ft_ptr_hexa_converter(unsigned long long nb)
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
//ligne 51 si nb est plus grand que 16, nb = nb / 16 jusqu'a ce que nb soit 
//plus petit que 16, on ecrit le premmier caractere selon regle ligne 56-58
//ligne 53, le caractere suivant sera le % 16 de la premiere division par 16, 
//ecrit selon la regle ligne 56 et 58
//ligne 53, le caractere suivant sera le % 16 de nb...
//
//ex:      987   -   -  -  11 
//    / 16  |  % 16        |
//          61   -   13    |
//    / 16  |        |     |
//          3        d     b

static int	ft_pointer_writer(unsigned long long ptr)
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

// cas print decimal && print integer %d %i 
static int	ft_number_writer(int nb)
{	
	int		length;
	char	*num;

	length = 0;
	num = ft_itoa(nb);
	length = ft_string_writer(num);
	free(num);
	return (length);
}

// cas unsigned %u
static int	ft_nbrlen(unsigned int num)
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

static char	*ft_unsigned_itoa(unsigned int nb)
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
// ligne 107 exemple: 784 | 784 % 10 = 4 | 4 + 48 = 4 ascii
// ligne 108 784 / 10 = 78 | retour ligne 107 exemple 78...

static int	ft_unsigned_writer(unsigned int nb)
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

// cas hexadecimal %x
static void	ft_hexa_converter(unsigned int nb, const char format)
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

static int	ft_hexa_writer(unsigned int nb, const char format)
{	
	if (nb == 0)
		return (write(1, "0", 1));
	else
		ft_hexa_converter(nb, format);
	return (ft_hexa_len(nb));
}	

// cas %
static int	ft_percent_writer(void)
{
	write(1, "%", 1);
	return (1);
}	

static int	ft_args_solver(va_list args, const char format)
{
	int	print_length;

	print_length = 0;
	if (format == 'c')
		print_length = print_length + ft_char_writer(va_arg(args, int));
	else if (format == 's')
		print_length = print_length + ft_string_writer(va_arg(args, char *));
	else if (format == 'p')
		print_length = print_length + ft_pointer_writer(va_arg(args, unsigned long long));
	else if (format == 'd')
		print_length = print_length + ft_number_writer(va_arg(args, int));
	else if (format == 'i')
		print_length = print_length + ft_number_writer(va_arg(args, int));
	else if (format == 'u')
		print_length = print_length + ft_unsigned_writer(va_arg(args, unsigned int));
	else if (format == 'x')
		print_length = print_length + ft_hexa_writer(va_arg(args, unsigned int), format);
	else if (format == 'X')
		print_length = print_length + ft_hexa_writer(va_arg(args, unsigned int), format);
	else if (format == '%')
		print_length = print_length + ft_percent_writer();
	return (print_length);
}

int	ft_printf(const char *format, ...)
{	
	int		i;
	va_list	args;
	int		print_length;

	va_start(args, format);
	print_length = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
		print_length = print_length + ft_args_solver(args, format[i + 1]);
			i++;
		}
		else
		{
			print_length = print_length + ft_char_writer(format[i]);
		}
		i++;
	}
	va_end(args);
	return (print_length);
}
