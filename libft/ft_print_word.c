/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:32:44 by rmatsuba          #+#    #+#             */
/*   Updated: 2023/12/05 18:30:07 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_char(int chr)
{
	write(1, &chr, 1);
	return (1);
}

int	ft_print_string(char *str)
{
	size_t	str_len;

	str_len = ft_strlen(str);
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	write(1, str, (int)str_len);
	return (str_len);
}
