/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_pourcent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 18:41:42 by jschotte          #+#    #+#             */
/*   Updated: 2017/05/27 02:23:42 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	conv_pourcent(t_printf *env)
{
	int	i;

	i = 1;
	if (env->moins)
		ft_putchar('%');
	if (!env->zero || env->moins)
	{
		while (i < env->width)
		{
			ft_putchar(' ');
			i++;
		}
	}
	if (env->zero && !env->moins)
	{
		while (i < env->width)
		{
			ft_putchar('0');
			i++;
		}
	}
	if (!env->moins)
		ft_putchar('%');
	env->ret = env->ret + i;
}
