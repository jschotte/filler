/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 01:31:54 by jschotte          #+#    #+#             */
/*   Updated: 2017/05/28 05:32:26 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		load_player(t_env *env)
{
	char	*line;

	get_next_line(0, &line);
	if (ft_strlen(line) < 10)
		return (-1);
	if (line[10] == '1' || line[10] == '2')
	{
		if (line[10] == '2')
			env->player = 'X';
		else
			env->player = 'O';
	}
	ft_strdel(&line);
	return (0);
}

int		load_sizemap(t_env *env)
{
	char	*line;
	char	**split;
	int		i;

	i = 0;
	get_next_line(0, &line);
	split = ft_strsplit(line, ' ');
	if (ft_arraylen(split) < 3)
		return (-1);
	env->size_mapx = ft_atoi(split[1]);
	env->size_mapy = ft_atoi(split[2]);
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
	ft_strdel(&line);
	return (0);
}

int		load_map(t_env *env)
{
	int		i;
	char	*line;

	i = 0;
	if (load_sizemap(env) == -1)
		return (-1);
	get_next_line(0, &line);
	free(line);
	env->map = malloc(sizeof(char*) * (env->size_mapx + 1));
	if (env == NULL)
		return (-1);
	while (i < env->size_mapx)
	{
		get_next_line(0, &line);
		env->map[i] = ft_strdup(line + 4);
		if (env->map[i] == NULL)
			return (-1);
		ft_strdel(&line);
		i++;
	}
	return (0);
}

int		load_sizepiece(t_env *env)
{
	char	*line;
	char	**split;
	int		i;

	i = 0;
	get_next_line(0, &line);
	split = ft_strsplit(line, ' ');
	if (ft_arraylen(split) < 3)
		return (-1);
	env->size_piecex = ft_atoi(split[1]);
	env->size_piecey = ft_atoi(split[2]);
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
	ft_strdel(&line);
	return (0);
}

int		load_piece(t_env *env)
{
	int		i;
	char	*line;

	i = 0;
	if (load_sizepiece(env) == -1)
		return (-1);
	env->piece = malloc(sizeof(char*) * (env->size_piecex + 1));
	if (env == NULL)
		return (-1);
	while (i < env->size_piecex)
	{
		get_next_line(0, &line);
		env->piece[i] = ft_strdup(line);
		if (env->piece[i] == NULL)
			return (-1);
		ft_strdel(&line);
		i++;
	}
	return (0);
}
