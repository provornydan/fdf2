/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprovorn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 13:32:22 by dprovorn          #+#    #+#             */
/*   Updated: 2017/01/19 13:32:23 by dprovorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int i;
	int j;
	int out;

	i = 0;
	j = 1;
	out = 0;

	while (str[i] >= '0' && str[i] <= '9')
	{
		out *= 10;
		out += str[i] - '0';
		i++;
	}
	return (out);
}

int		*intarr_dup(int *src, int n)
{
	int *dest;
	int i;

	i = -1;
	dest = (int*)malloc(sizeof(int)*n);
	while(++i < n)
		dest[i] = src[i];
	return(dest);
}