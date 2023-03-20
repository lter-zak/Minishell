/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leyeghia <leyeghia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 21:57:57 by lter-zak          #+#    #+#             */
/*   Updated: 2023/03/16 21:05:17 by leyeghia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	shell_level(t_env **env)
{
	t_env	*rtv;
	int		tmp;

	rtv = get_env(env, "SHLVL");
	tmp = ft_atoi(rtv->value);
	free(rtv->value);
	rtv->value = ft_itoa(tmp + 1);
}
