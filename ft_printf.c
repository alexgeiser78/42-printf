/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:02:00 by ageiser           #+#    #+#             */
/*   Updated: 2022/11/07 16:48:40 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

// cas print char %c
int	ft_char_writer(int c)
{
	if (write(1, &c, 1) < 0)
		return (-1);
	else
		return (1);
}	
// ligne 19 protection de la fonction

// cas print decimal && print integer %d %i 
int	ft_number_writer(int nb)
{	
	int		length;
	char	*num;

	length = 0;
	num = ft_itoa(nb);
	length = ft_string_writer(num);
	free(num);
	return (length);
}

// cas %
int	ft_percent_writer(void)
{
	if (write(1, "%", 1) < 0)
		return (-1);
	else
		return (1);
}	

int	ft_args_solver(va_list args, const char format)
{
	int	print_length;

	print_length = 0;
	if (format == 'c')
		print_length = print_length + ft_char_writer(va_arg(args, int));
	else if (format == 's')
		print_length = print_length + ft_string_writer(va_arg(args, char *));
	else if (format == 'p')
		print_length += ft_pointer_writer(va_arg(args, unsigned long long));
	else if (format == 'd')
		print_length = print_length + ft_number_writer(va_arg(args, int));
	else if (format == 'i')
		print_length = print_length + ft_number_writer(va_arg(args, int));
	else if (format == 'u')
		print_length += ft_unsigned_writer(va_arg(args, unsigned int));
	else if (format == 'x')
		print_length += ft_hexa_writer(va_arg(args, unsigned int), format);
	else if (format == 'X')
		print_length += ft_hexa_writer(va_arg(args, unsigned int), format);
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
