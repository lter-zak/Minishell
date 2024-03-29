/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_herdoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:09:48 by leyeghia          #+#    #+#             */
/*   Updated: 2023/03/20 17:51:41 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	call_heredoc_part2(char *del, int len)
{
	if (len == 1)
		heredoc(del, 1);
	else
		heredoc(del, 0);
	len--;
	return (len);
}

void	call_heredoc(t_tokens **tk, int len)
{
	t_tokens	*token;
	t_redirects	*red;

	token = *tk;
	while (token)
	{
		red = token->head_redct;
		while (token->head_redct)
		{
			if (token->head_redct && token->head_redct->flag == 2)
			{
				len = call_heredoc_part2(token->head_redct->del, len);
			}
			if (token->head_redct->next)
				token->head_redct = token->head_redct->next;
			else
				break ;
		}
		token->head_redct = red;
		if (token->next)
			token = token->next;
		else
			break ;
	}
	token = (*tk);
}
