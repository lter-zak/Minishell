/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_pars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leyeghia <leyeghia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:22:05 by lter-zak          #+#    #+#             */
/*   Updated: 2023/03/16 21:10:41 by leyeghia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	export_print(char *str, int z)
{
	(void)str;
	g_exit_code = z;
	printf("bash: export: `%s': not a valid identifier\n", str);
}

int	export_pars(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if ((str[i] && (ft_strcrcmp(METAE, str[i])))
			|| (str[i] == '+' && i != len - 1)
			|| (str[i] >= '0' && str[i] <= '9'))
		{
			export_print(str, 1);
			return (1);
		}
		i++;
	}
	return (0);
}
