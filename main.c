/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:28:20 by ageiser           #+#    #+#             */
/*   Updated: 2022/10/11 13:48:31 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
	char a = 'q'; // %c
	char b[] = "wertyuiop"; // %s
	*c = "asdf"; // %p
	int d = 789; // %d
	int e = 456; // %i
	int f = 123; // %u
	int g = 741; // %x
	int h = 258; // %X
	int i = 0;   // %%

	ft_printf("char %c\n", a);
	ft_printf("string %s\n", b);
	ft_printf("pointeur %p\n", c);
	ft_printf("decimal %d\n", d);
	ft_printf("entier %i\n", e);
	ft_printf("nonsigne %u\n", f);
	ft_printf("hexadecmin %x\n", g);
	ft_printf("hexadecmaj %X\n", h);
	ft_printf("% %%\n", i); 
	return (0);
