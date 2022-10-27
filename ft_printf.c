/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:02:00 by ageiser           #+#    #+#             */
/*   Updated: 2022/10/27 18:00:50 by ageiser          ###   ########.fr       */
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

static void	ft_hexa_converter(unsigned int nb)
{
	if (nb >= 16)
	{
		ft_hexa_converter(nb / 16);
		ft_hexa_converter(nb % 16);
	}
	else
	{
		if (nb <= 9)
			ft_putchar_fd((nb + '0'), 1);
		else
			ft_putchar_fd((nb - 10 + 'a'), 1);
	}	
}

static int	ft_pointer_writer(unsigned int ptr)
{
	int	i;

	write(1, "0x", 2);
	i = 2;
	if (ptr == 0)
	{
		write(1, "0", 1);
	i = i + 1;
	}	
	else
	{
		ft_hexa_converter(ptr);
	i++;
	}		
	return (i);
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
static int	ft_hexa_len(unsigned int nb)
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
static int	ft_hexa_writer(unsigned int nb)
{	
	if (nb == 0)
		return (write(1, "0", 1));
	else
		ft_hexa_converter(nb);
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
		print_length = print_length + ft_pointer_writer(va_arg(args, unsigned int));
	else if (format == 'd')
		print_length = print_length + ft_number_writer(va_arg(args, int));
	else if (format == 'i')
		print_length = print_length + ft_number_writer(va_arg(args, int));
	else if (format == 'u')
		print_length = print_length + ft_unsigned_writer(va_arg(args, unsigned int));
	else if (format == 'x')
		print_length = print_length + ft_hexa_writer(va_arg(args, unsigned int));
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
