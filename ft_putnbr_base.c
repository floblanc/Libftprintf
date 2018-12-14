/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 14:34:45 by floblanc          #+#    #+#             */
/*   Updated: 2018/12/14 15:20:49 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		base_isvalide(char *base, unsigned int size)
{
	unsigned int		i;
	unsigned int		j;

	i = 0;
	if (size < 2)
		return (0);
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int n, char *base)
{
	unsigned int	nb;
	unsigned int	base_size;

	base_size = ft_strlen(base);
	if (!(base_isvalide(base, base_size)))
	{
		ft_putstr("erreur de base\n");
		return ;
	}
	nb = n;
	if (n < 0)
	{
		ft_putchar('-');
		nb = -n;
	}
	if (nb < base_size)
		ft_putchar(base[nb]);
	else
	{
		ft_putnbr_base((nb / base_size), base);
		ft_putchar(base[nb % base_size]);
	}
}
