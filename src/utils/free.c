/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leyeghia <leyeghia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:14:16 by lter-zak          #+#    #+#             */
/*   Updated: 2023/03/17 14:08:10 by leyeghia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	matrix_free(char **env_split)
{
	int	j;

	j = 0;
	while (env_split && env_split[j])
	{
		free(env_split[j]);
		j++;
	}
	free(env_split);
}

void	one_node_free(t_env **rtv)
{
	free((*rtv)->value);
	free((*rtv)->key);
	free((*rtv));
}

void	free_part2(t_tokens **token)
{
	t_redirects	*hrd_next;

	hrd_next = (*token)->head_redct->next;
	if ((*token)->head_redct->del)
		free((*token)->head_redct->del);
	free((*token)->head_redct);
	(*token)->head_redct = hrd_next;
}

void	free_t_list(t_tokens **token)
{
	int			i;
	t_tokens	*next;

	i = 0;
	while ((*token))
	{
		i = 0;
		next = (*token)->next;
		if ((*token)->rdl)
			free((*token)->rdl);
		if ((*token)->cmd)
		{
			while ((*token)->cmd[i])
				free((*token)->cmd[i++]);
		}
		while ((*token)->head_redct && (*token)->head_redct->flag)
			free_part2(token);
		free((*token)->head_redct);
		next = (*token)->next;
		free((*token)->cmd);
		free(*token);
		(*token) = next;
	}
	token = NULL;
}
