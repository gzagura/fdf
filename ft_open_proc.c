/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open&proc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzagura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 15:36:27 by gzagura           #+#    #+#             */
/*   Updated: 2018/06/20 15:36:29 by gzagura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_strlen_spec(char *str, t_fdflist *head)
{
	int height;
	int width;
	int i;

	i = 0;
	width = 0;
	height = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		while (str[i] != '\n' && str[i] == ' ')
			i++;
		width++;
		while (str[i] != '\n' && str[i] != ' ')
			i++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			height++;
		i++;
	}
	head->height = height;
	head->width = width;
}

void	ft_num(t_fdflist *head, int x, int y, int number)
{
	head->curr->z = number;
	head->curr->x = x;
	head->curr->y = y;
	head->curr = ft_add_new(head->vector);
}

int		ft_space(char *str, int i, char **line)
{
	int		start;
	int		end;

	start = i;
	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\n')
		i++;
	end = i;
	*line = ft_strsub(str, start, end);
	return (end);
}

void	ft_str_nospace(char *str, t_fdflist *head)
{
	char	*num;
	int		i;
	int		x;
	int		y;

	i = 0;
	y = 0;
	x = 0;
	num = NULL;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			i = ft_space(str, i, &num);
			ft_num(head, x, y, ft_getnbr(num));
			x++;
		}
		if (str[i] == '\n')
		{
			y++;
			x = 0;
		}
		if (str[i])
			i++;
	}
}

int		ft_write_data(t_fdflist *head)
{
	char	*buffer;
	char	*tmp;
	int		fd;

	head->vector = ft_add_new(NULL);
	head->curr = head->vector;
	fd = open(head->filename, O_RDONLY);
	buffer = NULL;
	tmp = ft_strnew(1);
	while (get_next_line(fd, &buffer) > 0)
	{
		tmp = ft_strjoin(tmp, buffer);
		tmp = ft_strjoin(tmp, "\n");
		free(buffer);
	}
	ft_strlen_spec(tmp, head);
	ft_str_nospace(tmp, head);
	return (0);
}