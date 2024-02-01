/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_line_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:09:12 by khallal           #+#    #+#             */
/*   Updated: 2022/12/29 10:33:42 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	number_line(char *k)
{
	int	j;
	int	n_line;

	j = 0;
	n_line = 0;
	while (k[j])
	{
		if (k[j] == '\n')
			n_line++;
		j++;
	}
	return (n_line);
}
