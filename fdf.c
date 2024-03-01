/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:25:41 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/03/01 19:28:24 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

__attribute__((destructor))
static void destructor() {
    system("leaks -q fdf");
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!check_extension(argv[1]))
			return_error("Invalid file extension\n", 2);
		if (!check_argv(argv[1]))
			return_error("Invalid map\n", 2);
		return (0);
	}
	else
		return_error("Invalid arguments count\n", 2);
}
