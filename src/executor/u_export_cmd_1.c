/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_export_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:15:19 by sganiev           #+#    #+#             */
/*   Updated: 2024/07/30 15:42:48 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* this function prints error message if the given variable
*  name for the 'export' command is not correct			 */
static void	print_err_for_export(char *arg)
{
	write(STDERR_FILENO, "msh: export: `", 14);
	write(STDERR_FILENO, arg, ft_strlen(arg));
	write(STDERR_FILENO, "': not a valid identifier", 25);
}

/* this function checks if the given variable name for the
*  'export' command is correct							*/
int	is_export_arg_valid(char *arg)
{
	int	i;

	i = 0;
	if (!ft_isalpha(arg[i]) && (arg[i] != '_'))
		return (print_err_for_export(arg), 0);
	i++;
	while ((arg[i] != '=') && arg[i])
	{
		if (!ft_isalnum(arg[i]) && (arg[i] != '_'))
			return (print_err_for_export(arg), 0);
		i++;
	}
	return (1);
}

/* this function returns an allocated
*  string containing the value of the
*  environment variable			   */
char	*take_env_var_value(char *var)
{
	char	*begin;
	char	*value;

	value = NULL;
	begin = ft_strchr(var, '=');
	if (begin)
		value = ft_strdup(begin + 1);
	return (value);
}

/* this function returns an allocated
*  string containing the name  of the
*  environment variable			   */
char	*take_env_var_name(char *var)
{
	char	*end;
	char	*name;

	name = NULL;
	end = ft_strchr(var, '=');
	if (end)
		name = ft_strndup(var, end - var);
	return (name);
}

/* this function prints all environment
*  variables for the 'export' command*/
char	*print_env_vars(char **list)
{
	char	*name;
	char	*value;
	int		i;

	i = -1;
	while (list[++i])
	{
		name = take_env_var_name(list[i]);
		value = take_env_var_value(list[i]);
		if (name && value)
		{
			write (STDOUT_FILENO, "declare -x ", 11);
			write (STDOUT_FILENO, name, ft_strlen(name));
			write (STDOUT_FILENO, "=\"", 1);
			write (STDOUT_FILENO, value, ft_strlen(value));
			write (STDOUT_FILENO, "\"", 1);
			write (STDOUT_FILENO, "\n", 1);
		}
		if (name)
			free(name);
		if (value)
			free(value);
	}
}