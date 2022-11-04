/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:55:16 by ageiser           #+#    #+#             */
/*   Updated: 2022/11/04 17:36:56 by ageiser          ###   ########.fr       */
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
#endif
