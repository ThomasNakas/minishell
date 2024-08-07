/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_executor_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:03:55 by sganiev           #+#    #+#             */
/*   Updated: 2024/08/06 20:53:31 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* this function checks if a given command is a builtin command;
*
*  return values:
*				  '-1'   -> not a builtin cmd
*				  '>= 0' -> an index in the 'builtin_names' array
*							where the name of the command is found */
int	is_cmd_builtin(char *cmd, t_msh *info)
{
	char	*cmd_cp;
	int		i;

	i = -1;
	while (info->builtin_names[++i] != NULL)
	{
		if (ft_strcmp(cmd, info->builtin_names[i]) == 0)
			return (i);
	}
	i = -1;
	cmd_cp = str_to_lower_case(cmd);
	if (!cmd_cp)
		return (-1);
	while (info->builtin_names[++i] != NULL)
	{
		if (ft_strcmp(cmd_cp, info->builtin_names[i]) == 0)
			return (free(cmd_cp), i);
	}
	return (free(cmd_cp), -1);
}

/* this function counts how many
*  strings a given array has  */
int	count_args(char **args)
{
	int	i;

	i = 0;
	while (args && args[i])
		i++;
	return (i);
}

/* this function counts the number of nodes in
*  a given linked list; the count represents
*  the total number of commands				*/
int	count_cmds(t_pipe_group *cmds)
{
	int	count;

	count = 0;
	while (cmds != NULL)
	{
		count++;
		cmds = cmds->next;
	}
	return (count);
}

/* this function initializes an array of builtin names */
void	init_builtin_names(char **builtin_names)
{
	builtin_names[0] = "echo";
	builtin_names[1] = "cd";
	builtin_names[2] = "pwd";
	builtin_names[3] = "export";
	builtin_names[4] = "unset";
	builtin_names[5] = "env";
	builtin_names[6] = "exit";
	builtin_names[7] = NULL;
}

/* this function initializes an array of pointers to builtin functions */
void	init_builtin_ptrs(int (**builtin_ptrs)(char **, char ***, t_msh *))
{
	builtin_ptrs[0] = ft_echo;
	builtin_ptrs[1] = ft_cd;
	builtin_ptrs[2] = ft_pwd;
	builtin_ptrs[3] = ft_export;
	builtin_ptrs[4] = ft_unset;
	builtin_ptrs[5] = ft_env;
	builtin_ptrs[6] = ft_exit;
	builtin_ptrs[7] = NULL;
}
