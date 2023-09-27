/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:47:57 by rmatsuba          #+#    #+#             */
/*   Updated: 2023/09/27 19:15:10 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		&& !(c >= '0' && c <= '9'))
		return (0);
	else
		return (1);
}
