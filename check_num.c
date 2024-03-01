/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:02:10 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/03/01 18:02:15 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int range_of_int(char *number)
{
	int i;
	long	l_number;
	int sign;

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
		if (!ft_isdigit(number[index]) && number[index] != '\n' && number[index] != '\0')
			return (0);
		index++;
	}
	if (!range_of_int(number))
		return (0);
	return (1);
}

int	is_number(char **arg_list)
{
	int i;

	i = 0;
	if (!arg_list)
		return (0);
	while (arg_list[i] != NULL)
	{
		if (!collect_number(arg_list[i]))
			return (0);
		i++;
	}
	return (1);
}
