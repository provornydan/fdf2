#include "mlx.h"
#include <unistd.h>
#include <stdlib.h>

void *win;

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int	my_key_func(int keycode, void *mlx)
{
	int n;

	n = keycode;
	if(keycode == 53)
		exit(0);
	return(0);
}

int	main()
{
	void *mlx;
	int x;
	int y;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 600, 600, "DANU");
	x = 100;
	y = 100;
	while(++x< 300)
	{		
	y = 100;
	while(++y < 300)
		mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
	}
	mlx_key_hook(win, my_key_func, 0);
	mlx_loop(mlx);

}
