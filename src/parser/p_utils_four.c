/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_utils_four.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 22:35:17 by tnakas            #+#    #+#             */
/*   Updated: 2024/08/20 00:01:41 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	pipe_group_print(t_pipe_group *group)
{
	int	i;

	while (group)
	{
		printf("Command: %s\n", group->command);
		printf("Arguments:\n");
		i = -1;
		while (group->args && group->args[++i])
			printf("  [%d]: %s\n", i, group->args[i]);
		group = group->next;
	}
}

t_pipe_group	*pipe_group_init(void)
{
	t_pipe_group	*new_group;

	new_group = (t_pipe_group *)malloc(sizeof(t_pipe_group));
	if (!new_group)
		return (NULL);
	new_group->command = NULL;
	new_group->args = NULL;
	new_group->file_in = NULL;
	new_group->file_out = NULL;
	new_group->redir_in = 0;
	new_group->redir_out = 0;
	new_group->mode_in = 0;
	new_group->mode_out = 0;
	new_group->heredoc_strs = NULL;
	new_group->is_heredoc_in = false;
	new_group->argv = NULL;
	new_group->cmd_path = NULL;
	new_group->next = NULL;
	return (new_group);
}

void	pipe_group_add(t_pipe_group **head, t_pipe_group *new_group)
{
	t_pipe_group	*temp;

	if (!head || !new_group)
		return ;
	temp = *head;
	if (!*head)
		*head = new_group;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new_group;
	}
}

void	free_is_existing(void *mem)
{
	if (mem)
		free(mem);
	mem = NULL;
}

void	pipe_group_free(t_pipe_group **head)
{
	t_pipe_group	*current;
	t_pipe_group	*next;

	if (!head || !*head)
		return ;
	current = *head;
	while (current)
	{
		next = current->next;
		free_is_existing((char *)current->command);
		free_arr_str(&(current->args));
		free_is_existing((char *)current->file_in);
		free_is_existing((char *)current->file_out);
		if (current->is_heredoc_in)
			free_is_existing((char *)current->heredoc_strs);
		free_arr_str(&(current->argv));
		free_is_existing((char *)current->cmd_path);
		free(current);
		current = next;
	}
	head = NULL;
}
