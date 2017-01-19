/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprovorn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 19:07:00 by dprovorn          #+#    #+#             */
/*   Updated: 2017/01/19 14:54:58 by dprovorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line2.c"
#include "ft_strsplit2.c"
#include "func2.c"
#include "func.c"

int		my_key_func(int key, void *mlx);
void	*init_window(void **mlx, int x, int y, char *c);
int		show_usage(char *str);

int		show_usage(char *str)
{
	ft_putstr("Usage: ");
	ft_putstr(str);
	ft_putstr(" <filename> \n");
	return(0);
}

int		my_key_func(int keycode, void *mlx)
{
	int n;

	n = keycode;
	if(keycode == 53)
		exit(0);
	return(0);
}

void	*init_window(void **mlx, int x, int y, char *c)
{
	void *win;

	*mlx = mlx_init();
	win = mlx_new_window(*mlx, x, y, c);
	mlx_key_hook(win, my_key_func, 0);
	return(win);
}

int		*get_array(int *fd, int *n)
{
	int *x;
	char *str;
	char **cr;
	int i;

	i = -1;
	x = NULL;
	if((str = get_next_line(*fd)))
	{
		x = (int*)malloc(sizeof(int));
		cr = ft_split_whitespaces(str);
		while(*(cr + ++i))
		{
			x[0] = ft_atoi(*(cr + i));
			x = num_realloc(x, i, i+1);
		}
		*n = i;
		return(x);
	}
	return(NULL);
}
void	reset_array(int *coord)
{
	int i;

	i = -1;
	while(++i < 5)
		coord[i] = 5;
}

void	huge_pixel(void **mlx, void **win, int *coord)
{
	int x;
	int y;
	int i;
	int j;

	x = 30+coord[0]*coord[3]+coord[3];
	y = 30+coord[1]*coord[4]+coord[4];
	i = 30+coord[0]*coord[3]-1;
	j = 30+coord[1]*coord[4]-1;
	while(++i < x)
		mlx_pixel_put(*mlx, *win, i, 30+coord[1]*coord[4], 0x00FFFFFF);
	while(++j < y)
		mlx_pixel_put(*mlx, *win, 30+coord[0]*coord[3], j, 0x00FFFFFF);
	while(--i > 30+coord[0]*coord[3])
		mlx_pixel_put(*mlx, *win, i, j, 0x00FFFFFF);
	while(--j > 30+coord[1]*coord[4])
		mlx_pixel_put(*mlx, *win, x, j, 0x00FFFFFF);
}

void	draw_figure(void **mlx, void **win, int *fd, int *n)
{
	int *coord;
	int *x;
	int i;

	coord = (int*)malloc(sizeof(int)*5);
	reset_array(coord);
	coord[3] = 20;
	coord[4] = 20;
	while((x = get_array(fd, n)) != NULL)
	{
		i = -1;
		while(++i < *n)
		{
			coord[0] = i;
			coord[2] = x[i];
			huge_pixel(mlx, win, coord);
		}
		coord[1]++;
	}
}

void	draw_lines(char *l, void **mlx, void **win, int j)
{
	int fd;
	int *x;
	int n;
	int i;

	i = -1;
	fd = open(l, O_RDONLY);
	draw_figure(mlx, win, &fd, &n);
//	x = get_array(&fd, &n);
//	while(++i < n)
//	{
//		mlx_pixel_put(*mlx, *win, i+j, j, 0x00FFFFFF);
//	}
	close(fd);
}

int		main(int argc, char **argv)
{
	void *mlx;
	void *win;
	char *line;
	int j;
	int n;

	j = 0;
	if(argc != 2)
		return(show_usage(argv[0]));
	win = init_window(&mlx, 600, 600, "DANU");
	draw_lines(argv[1], &mlx, &win, 50);
/*	x = 100;
	y = 100;
	while(++x< 300)
	{		
	y = 100;
	while(++y < 300)
		mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
	}*/
	mlx_loop(mlx);
}
