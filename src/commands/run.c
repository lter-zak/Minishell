/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leyeghia <leyeghia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:32:02 by lter-zak          #+#    #+#             */
/*   Updated: 2023/03/16 21:04:57 by leyeghia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_all_part2(t_tokens *token, t_count *count)
{
	if (token->head_redct->flag == 2)
		count->count_herdoc++;
	if (token->head_redct->next)
		token->head_redct = token->head_redct->next;
	else
		return (1);
	return (0);
}

t_count	*count_all(t_tokens **tk)
{	
	t_count		*count;
	t_tokens	*token;
	t_redirects	*red1;

	token = *tk;
	count = malloc(sizeof(t_count));
	count->count_1 = 0;
	count->count_3 = 0;
	count->count_4 = 0;
	count->count_herdoc = 0;
	while (token)
	{
	red1 = token->head_redct;
		while (token->head_redct->flag)
		{
			if (count_all_part2(token, count))
				break ;
		}
		token->head_redct = red1;
		if (token->next)
			token = token->next;
		else
			break ;
	}
	return (count);
}

int	count_red_part2(t_tokens *token, t_count **count)
{
	if (token->head_redct->flag == 1)
		(*count)->count_1++;
	if (token->head_redct->flag == 3)
		(*count)->count_3++;
	if (token->head_redct->flag == 4)
		(*count)->count_4++;
	if (token->head_redct->next)
		token->head_redct = token->head_redct->next;
	else
		return (1);
	return (0);
}

t_count	*count_red(t_tokens **tk)
{
	t_count		*count;
	t_tokens	*token;
	t_redirects	*red1;

	token = *tk;
	count = malloc(sizeof(t_count));
	count->count_1 = 0;
	count->count_3 = 0;
	count->count_4 = 0;
	count->count_herdoc = 0;
	red1 = token->head_redct;
	while (token->head_redct->flag)
	{
		if (count_red_part2(token, &count))
			break ;
	}
	token->head_redct = red1;
	return (count);
}

void	do_the_job(t_redirects *token, t_count *len)
{
	if (token->flag == 1)
	{
		if (len->count_1 == 1)
			redirection_input(token->del, 1);
		else
			redirection_input(token->del, 0);
		len->count_1--;
	}
	if (token->flag == 3)
	{
		if (len->count_3 == 1)
			redirection_output(token->del, 1);
		else
			redirection_output(token->del, 0);
		len->count_3--;
	}
	if (token->flag == 4)
	{
		if (len->count_4 == 1)
			redirection_output_append(token->del, 1);
		else
			redirection_output_append(token->del, 0);
		len->count_4--;
	}	
}
