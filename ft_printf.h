/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:55:16 by ageiser           #+#    #+#             */
/*   Updated: 2022/11/07 13:09:02 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"

int		ft_printf(const char *format, ...);
int		ft_hexa_len(unsigned long long nb);
void	ft_ptr_hexa_converter(unsigned long long nb);
int		ft_pointer_writer(unsigned long long ptr);
void	ft_hexa_converter(unsigned int nb, const char format);
int		ft_hexa_writer(unsigned int nb, const char format);
int		ft_nbrlen(unsigned int num);
char	*ft_unsigned_itoa(unsigned int nb);
int		ft_unsigned_writer(unsigned int nb);
int		ft_string_writer(char *str);
int		ft_char_writer(int c);
int		ft_string_writer(char *str);
int		ft_number_writer(int nb);
int		ft_percent_writer(void);
int		ft_args_solver(va_list args, const char format);
int		ft_printf(const char *format, ...);
#endif
