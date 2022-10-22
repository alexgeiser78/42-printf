/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:02:00 by ageiser           #+#    #+#             */
/*   Updated: 2022/10/22 18:53:41 by ageiser          ###   ########.fr       */
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
static void	ft_pointer_converter(char ptr)
{
	if (ptr >= 16)
	{
		ptr = ptr / 16;
		ptr = ptr % 16;
	}
	else
	{
		if (ptr <= 9)
			write(1, "x", 1);
		else
			write(1, "y", 1);
	}	
}	
static int	ft_pointer_writer(unsigned int ptr)
{
	int i;
	write(1, "0x", 2);
	i = 2;
	if (ptr == 0)
	{
		write(1, "0", 1);
	i = i + 1;
	}	
	else 
	{
		ft_pointer_converter(ptr);
	i++;
	}		
	return (i);
}
/*
static int ft_number_writer(int nb)
{	
	int	len;
	char	*num; 
	len = 0;
	num = ft_itoa(nb);
	len = ft_string_writer(num);
	free(num);
	return (len);	
}
*/

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
//		else if (format == 'd')
//			ft_number_writer(va_arg(args, int));
//	else
//		return (1);
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

//		if (format == NULL)
//			return (0);
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
//	printf("format i es %c\n", format[i]);
	}
//	printf("i = %d\n", i);
//	printf("print_length = %d\n", print_length);
	va_end(args);
	return (print_length);
}
