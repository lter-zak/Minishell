/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dolar_pars1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:42:16 by lter-zak          #+#    #+#             */
/*   Updated: 2023/03/14 21:43:40 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	go_until_spasce(char *str, int i)
{
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i] && str[i] != ' ')
		i++;
	return (i);
}

char	*join_dolar_str(char *str, char *world, int x, int z)
{
	int		len_s;
	char	*new_str;
	char	*rtv;
	char	*tmp;

	len_s = ft_strlen(str);
	new_str = ft_substr(str, 0, x - 1);
	rtv = new_str;
	if (world)
	{
		new_str = ft_strjoin(new_str, world);
		free(rtv);
		rtv = new_str;
	}
	tmp = ft_substr(str, x + z - 1, len_s);
	rtv = new_str;
	new_str = ft_strjoin(new_str, tmp);
	free(tmp);
	free(rtv);
	free(str);
	return (new_str);
}
