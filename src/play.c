/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 01:31:54 by jschotte          #+#    #+#             */
/*   Updated: 2017/05/28 05:50:18 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		can_place2(t_env *env, int x, int y, char piece)
{
	if ((piece == '*' && (x >= env->size_mapx || x < 0))
			|| (piece == '*' && (y >= env->size_mapy || y < 0))
			|| (piece == '*' && env->map[x][y] != env->player
				&& env->map[x][y] != '.'))
		return (-1);
	if (piece == '*' && env->map[x][y] == env->player)
		return (1);
	return (0);
}

int		get_range(t_env *env, int x, int y)
{
	int		r;
	int		i;
	int		j;

	r = 1;
	while (r < env->size_mapx)
	{
		i = 0;
		while (i < r)
		{
			j = 0;
			while (j < r)
			{
				if (x + i < env->size_mapx && y + j < env->size_mapy
					&& x + i > 0 && y + j > 0 && env->map[x + i][y + j] != '.'
					&& env->map[x + i][y + j] != env->player)
					return (r);
				j++;
			}
			i++;
		}
		r++;
	}
	return (0);
}

int		can_place(t_env *env, int x, int y)
{
	int x2;
	int y2;
	int count;
	int ret;

	count = 0;
	x2 = 0;
	while (x2 < env->size_piecex)
	{
		y2 = 0;
		while (y2 < env->size_piecey)
		{
			if ((ret = can_place2(env, x + x2, y + y2,
				env->piece[x2][y2])) == 1)
				count++;
			if (ret == -1)
				return (-1);
			y2++;
		}
		x2++;
	}
	if (count == 1)
		return (1);
	else
		return (0);
}

void	new_range(t_env *env, int i, int j, int range)
{
	env->x = i;
	env->y = j;
	env->range = range;
	env->found = 1;
}

int		play(t_env *env)
{
	int i;
	int j;
	int range;

	i = -env->size_piecex;
	while (i < env->size_mapx)
	{
		j = -env->size_piecey;
		while (j < env->size_mapy)
		{
			if (can_place(env, i, j) == 1)
			{
				range = get_range(env, i, j);
				if (env->range == -1 || (env->range != -1
					&& range < env->range))
					new_range(env, i, j, range);
			}
			j++;
		}
		i++;
	}
	if (env->found == 0)
		return (-1);
	else
		return (0);
}
