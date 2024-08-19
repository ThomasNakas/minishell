/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_utils_eight.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 05:14:21 by tnakas            #+#    #+#             */
/*   Updated: 2024/08/19 05:16:16 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	token_to_token_preexp(t_token *src, t_token **dest)
{
	while (src)
	{
		token_lstadd(dest, token_create_preexp(src->token_start,
				src->len, src->type));
		src = src->next;
	}
}

void	token_preexp_free(t_token **dest)
{
	t_token	*temp;
	t_token	*next;

	temp = *dest;
	while (temp)
	{
		if (temp->token_start)
			free(temp->token_start);
		next = (temp)->next;
		free(temp);
		temp = next;
	}
	*dest = NULL;
}

void	token_preexp_to_trimed(t_token **dest)
{
	t_token	*temp;
	char	*temp_str;

	temp = *dest;
	while (temp)
	{
		if (temp->type == 8 || temp->type == 7)
		{
			if (ft_strlen(temp->token_start) > 2)
				temp_str = ft_strndup(temp->token_start + 1,
						temp->len - 2);
			else
				temp_str = ft_strdup("\0");
			if (!temp_str)
			{
				token_preexp_free(dest);
				return ;
			}
			free(temp->token_start);
			temp->token_start = temp_str;
		}
		temp = temp->next;
	}
}

static void	t_preex_helper(t_token **temp, t_token **prev)
{
	if ((*temp)->type != SPC)
		*prev = (*temp);
	(*temp) = (*temp)->next;
}

void	token_preexp_to_token_exp(int l, t_token **dest, char **envp)
{
	t_token	*temp;
	t_token	*prev;
	char	*temp_str;

	temp = *dest;
	prev = NULL;
	while (temp)
	{
		if ((temp->type == EXP_FIELD || ((temp->type == D_QUOTED)
					&& ft_strchr(temp->token_start, '$')))
			&& (!prev || prev->type != HEREDOC))
		{
			if (temp->type == EXP_FIELD)
				temp_str = expand_var(l, temp->token_start, envp);
			else
				temp_str = expand_double_quoted(l, temp->token_start, envp);
			if (!temp_str)
				token_preexp_free(dest);
			free_is_existing(temp->token_start);
			temp->token_start = temp_str;
			temp->len = ft_strlen(temp->token_start);
		}
		t_preex_helper(&temp, &prev);
	}
}