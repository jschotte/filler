/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 01:31:54 by jschotte          #+#    #+#             */
/*   Updated: 2017/05/28 10:14:09 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_env	*ft_init_env(void)
{
	t_env *env;

	env = malloc(sizeof(t_env));
	if (env == NULL || load_player(env) == -1)
		return (NULL);
	return (env);
}

void	free_map(t_env *env)
{
	int i;

	i = 0;
	while (i < env->size_mapx)
	{
		free(env->map[i]);
		env->map[i] = NULL;
		i++;
	}
	free(env->map);
	env->map = NULL;
	free_piece(env);
}

void	free_piece(t_env *env)
{
	int i;

	i = 0;
	while (i < env->size_piecex)
	{
		free(env->piece[i]);
		env->piece[i] = NULL;
		i++;
	}
	free(env->piece);
	env->piece = NULL;
}

void	ft_reset(t_env *env)
{
	env->x = -1;
	env->y = -1;
	env->range = -1;
	env->found = 0;
}

int		main(void)
{
	t_env *env;

	if ((env = ft_init_env()) == NULL)
		return (-1);
	while (1)
	{
		if (load_map(env) == -1 || load_piece(env) == -1)
			return (-1);
		ft_reset(env);
		if (play(env) == -1)
		{
			free_map(env);
			ft_printf("-1 -1\n");
			return (-1);
		}
		else
		{
			free_map(env);
			ft_printf("%d %d\n", env->x, env->y);
		}
	}
	free(env);
	return (0);
}
