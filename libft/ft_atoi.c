/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabathur <wabathur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:03:00 by wabathur          #+#    #+#             */
/*   Updated: 2022/02/22 11:03:01 by wabathur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *num)
{
	int	res;
	int	buff;

	if (!num || *num == 0)
		return (-1);
	res = 0;
	while (*num)
	{
		if (res > 255)
			return (-1);
		if (*num > 57 || *num < 48)
			break ;
		buff = *num - '0';
		res = res * 10 + buff;
		num++;
	}
	return (res);
}
