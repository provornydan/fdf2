/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprovorn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 19:07:00 by dprovorn          #+#    #+#             */
/*   Updated: 2017/01/18 20:17:11 by dprovorn         ###   ########.fr       */
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

void draw_lines(char *l, void **mlx, void **win)
{
	int fd;
	int *x;
	char *got;
	char **str;

	fd = open(l, O_RDONLY);
}

int		main(int argc, char **argv)
{
	void *mlx;
	void *win;
	char *line;

	if(argc != 2)
		return(show_usage(argv[0]));
//	win = init_window(&mlx, 600, 600, "DANU");
	draw_lines(argv[1], &win, &mlx);
/*	x = 100;
	y = 100;
	while(++x< 300)
	{		
	y = 100;
	while(++y < 300)
		mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
	}*/
//	mlx_loop(mlx);
}
