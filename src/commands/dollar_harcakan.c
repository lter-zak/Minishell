/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_harcakan.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leyeghia <leyeghia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:05:57 by lter-zak          #+#    #+#             */
/*   Updated: 2023/03/16 21:14:30 by leyeghia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	dollar_harcakan(void)
{
	char	*tiv;

	tiv = ft_itoa(g_exit_code);
	g_exit_code = 127;
	write(1, tiv, ft_strlen(tiv));
	write(1, ":", 1);
	write(1, "command not found", 18);
}
