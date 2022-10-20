/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:02:00 by ageiser           #+#    #+#             */
/*   Updated: 2022/10/20 18:48:41 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>


static int	ft_char_writer(int c)
{
	write(1, &c, 1);
	return (1);
}	
/*
static int	ft_string_writer(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_char_writer("(null)");
		return (6);
	}
	while (str[i])
	{
	write(1, &str[i], 1);
	i++;
	}
	return (i);
}	
*/


static void	ft_text_writer(int c)
{
	write(1, &c, 1);
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
static int ft_args_solver(va_list args, const char format)
{
		if (format == 'c')
		{
		   ft_char_writer(va_arg(args, int));
		}
//		else if (format == 'd')
//			ft_number_writer(va_arg(args, int));
		else
			return (1);
	
	
	return (1);

}

int	ft_printf(const char *format, ...)
{	
int 	i;
va_list args;
int print_length;
va_start(args, format);
print_length = 0;
i = 0;

while (format[i] != '\0')
{
	if (format[i] == '%')
	{
	ft_args_solver(args, format[i + 1]);
	}

	else
	{
	ft_text_writer(format[i]);
		i++;
	}
}
va_end(args);

return (i);
}

