/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smart_sub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leyeghia <leyeghia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:04:47 by leyeghia          #+#    #+#             */
/*   Updated: 2023/03/16 21:10:49 by leyeghia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_smart_sub( char *rdl, t_tokens **hert)
{
	int		i;
	char	*tmp;

	tmp = NULL;
	i = 0;
	while (rdl[i])
	{
		while (rdl[i] && rdl[i] == ' ')
		i++;
		if (rdl[i] && rdl[i + 1] && rdl[i] == '<' && rdl[i + 1] == '<')
			i = ft_smart_sub_part1(rdl, i, hert);
		else if (rdl[i] && rdl[i + 1] && rdl[i] == '>' && rdl[i + 1] == '>')
			i = ft_smart_sub_part2(rdl, i, hert);
		else if (rdl[i] && rdl[i] == '>')
			i = ft_smart_sub_part3(rdl, i, hert);
		else if (rdl[i] && rdl[i] == '<')
			i = ft_smart_sub_part4(rdl, i, hert);
		else
			i = ft_smart_sub_part5(rdl, i, &tmp);
	}
	if (tmp)
	{
		(*hert)->cmd = smart_split(tmp, ' ');
		free(tmp);
	}
}
