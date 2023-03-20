/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leyeghia <leyeghia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:11:37 by lter-zak          #+#    #+#             */
/*   Updated: 2023/03/16 19:49:22 by leyeghia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_error(char *cmd, char *str, int code)
{
	g_exit_code = code;
	ft_putstr_fd("minishell : ", 2);
	if (cmd)
	{
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
}

void	ft_putstr_fd1(char *s, int fd, int fl)
{
	write(fd, s, ft_strlen(s));
	if (fl)
		write(fd, "\n", 1);
}
