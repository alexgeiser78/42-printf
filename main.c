/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:28:20 by ageiser           #+#    #+#             */
/*   Updated: 2022/10/27 18:00:45 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	a = 'q'; // %c
	char	b[] = "wertyuiop"; // %s
	char	*c = "asdf"; // %p
	int		d = 123; // %d
	int		e = 456; // %i
	int		f = 789; // %u
	int		g =	987; // %x
	int		h = 654; // %X("hexa
	
	ft_printf("\n");
	ft_printf("Pleiades\n");
	ft_printf("char = %c\n", a);
	ft_printf("string = %s\n", b);
	ft_printf("pointeur = %p\n", c);
	ft_printf("decimal = %d\n", d);
	ft_printf("entier = %i\n", e);
	ft_printf("nonsigne = %u\n", f);
	ft_printf("hexadecmin = %x\n", g);
//	ft_printf("hexadecmaj = %X\n", h);
	ft_printf(" = %%\n");
	return (0);
}
