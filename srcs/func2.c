/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprovorn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 18:25:32 by dprovorn          #+#    #+#             */
/*   Updated: 2017/01/15 18:28:21 by dprovorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *c)
{
	int i;

	i = -1;
	while (*(c + ++i))
		ft_putchar(*(c + i));
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (*(s1 + i) && *(s1 + i) == *(s2 + i))
		i++;
	return (*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i));
}

/*int		print_error(t_list **f, t_list **s)
{
	write(1, AC_RED, 5);
	ft_putstr("Error\n");
	write(1, AC_RESET, 4);
	free_list(f, s);
	return (0);
}*/
