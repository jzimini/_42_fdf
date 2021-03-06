/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:19:30 by aaubin            #+#    #+#             */
/*   Updated: 2013/11/21 06:32:39 by aaubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Prototype
	char * ft_itoa(int n);
Description
	Alloue (avec malloc(3)) et retourne une chaine de caractères
	“fraiche” terminée par un ’\0’ représentant l’entier n passé
	en paramètre. Les nombres négatifs doivent être gérés. Si l’allocation
	échoue, la fonction renvoie NULL.
Param.
	#1 L’entier à convertir en une chaine de caractères.
Retour
	La chaine de caractères représentant l’entier passé en paramètre.
Fonctions
	libc malloc(3)  
*/
char *	ft_itoa(int n)
{
	char *p;

	p = ft_strnew (20) + 19;
	if (n >= 0 && p)
	{
		*--p = '0' + (n % 10);
		n /= 10;
		while (n != 0)
		{
			*--p = '0' + (n % 10);
			n /= 10;
		}
	}
	else if (p)
	{
		*--p = '0' - (n % 10);
		n /= 10;
		while (n != 0)
		{
			*--p = '0' - (n % 10);
			n /= 10;
		}
		*--p = '-';
	}
	return (p);
}
