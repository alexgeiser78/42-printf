/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:02:00 by ageiser           #+#    #+#             */
/*   Updated: 2022/10/16 13:59:52 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>


static void	ft_text_writer(int c)
{
	write(1, &c, 1);
}

static void ft_putnbr(int nb)
{	

}

static int ft_args_solver(va_list args, const char *format)
{
	int i;
	i = 0;

	while (*format && *format != '%')
	{
	if (format[i] != '%')	
	{
		i++;
	}
	else if (format[i] == '%')
	{
		if (format[i + 1] == 'd')
		{
			i = i + 1;
			int d = (va_arg(args, int));	
		ft_putnbr(d);	
		}
		else
			return (i);
	}
	}
	return (i);

}

int	ft_printf(const char *format, ...)
{	
int 	i;
va_list args;
int print_length;
va_start(args, format);
print_length = 0;
i = 0;

while (format[i])
{
	if (format[i] == '%')
	{
	ft_args_solver(args, &format[i + 1]);
	}
	else
	{
	ft_text_writer(format[i]);
		i++;
	}
}
va_end(args);

return (print_length);
}

