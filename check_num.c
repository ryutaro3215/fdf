/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:54:15 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/03/14 17:56:54 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	range_of_int(char *number)
{
	int		i;
	long	l_number;
	int		sign;

	i = 0;
	sign = 1;
	l_number = 0;
	if (number[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (number[i])
	{
		l_number = l_number * 10 + (number[i] - '0');
		if (l_number * sign > INT_MAX || l_number * sign < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

int	collect_number(char *number)
{
	int	index;

	index = 0;
	if (!number)
		return (0);
	if (number[index] == '-')
	{
		index++;
		if (number[index] == '\0')
			return (0);
	}
	if (number[index] == '0' && ft_strlen(number) != 1)
		return (0);
	while (number[index] != '\0')
	{
		if (!ft_isdigit(number[index]))
			return (0);
		index++;
	}
	if (!range_of_int(number))
		return (0);
	return (1);
}

bool	eachline_num(char **split)
{
	int		i;
	char	*copy;

	i = 0;
	while (split[i] != NULL)
	{
		copy = ft_copy_to_char(split[i], ',');
		if (!copy)
			return (false);
		if (!collect_number(copy))
		{
			free(copy);
			return (false);
		}
		free(copy);
		i++;
	}
	return (true);
}
