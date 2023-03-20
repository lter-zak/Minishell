/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leyeghia <leyeghia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:46:06 by leyeghia          #+#    #+#             */
/*   Updated: 2023/03/16 19:50:30 by leyeghia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ctrl_d_check(char *s)
{
	if (!s)
	{
		write(1, "exit\n", 5);
		exit(g_exit_code);
	}
}

int	sp_sp(char *str)
{
	char	*rt;

	rt = ft_strtrim(str, " ");
	if (rt == NULL)
		return (0);
	else
	{
		free(rt);
		return (1);
	}
}
