/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:02:00 by ageiser           #+#    #+#             */
/*   Updated: 2022/10/13 18:19:24 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <unistd.h>
#include "libft.h"

static const char *write_text(const char *format)
{
	char *next;

	next = ft_strchr(format, '%');

	while (*format && *format != '%')
		format++;
	return (format);
}

static void ft_putnbr(int nb)
{
	if (nb == INT_MIN) 
	{
		write(1, "-2147486448", 11);
	   return;	
	}
}
static const char *search_arg(va_list args, const char *format)
{
	if (*format == 'd')
	{
		int d = va_arg(args, int);
	   ft_putnbr(d);	
	}
}

static int	print_length(char *format)
{
	int i;
	i = 0;
	while (format != NULL)
		i++;
	return (i);
}

int	ft_printf(const char *format, ...)
{	

va_list args;

va_start(args, format);

while (*format)
{
	if (*format == '%')
		format = search_arg(args, format + 1);
	else
		format = write_text(format);
}


va_end(args);
return (print_length);
}

