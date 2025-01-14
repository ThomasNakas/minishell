/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_unset_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:30:34 by sganiev           #+#    #+#             */
/*   Updated: 2024/07/30 20:31:54 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* this function copies pointers to strings from the
*  'src' array to the 'dst' array; it skips the string
*  in 'src' at the index 'var_i'*/
static void	rest_copy(int var_i, char **dst, char **src)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (y != var_i && src[y])
		dst[i++] = src[y++];
	if (y == var_i)
	{
		free_str(&(src[y]));
		y++;
	}
	while (src[y])
		dst[i++] = src[y++];
	dst[i] = NULL;
}

/* this function removes a certain environment 
*  variable named 'var' from the array 'envp'*/
void	remove_env_var(char *var, char ***envp)
{
	char	**envp_new;
	int		var_i;
	int		len;

	var_i = search_env_var(var, *envp);
	if (var_i != -1)
	{
		len = count_args(*envp);
		envp_new = (char **)malloc(sizeof(char *) * len);
		if (envp_new)
		{
			rest_copy(var_i, envp_new, *envp);
			free(*envp);
			*envp = envp_new;
		}
	}
}

static void	print_err_for_unset(char *arg)
{
	write(STDERR_FILENO, "msh: unset: `", 13);
	write(STDERR_FILENO, arg, ft_strlen(arg));
	write(STDERR_FILENO, "': not a valid identifier\n", 26);
}

int	is_unset_arg_valid(char *arg)
{
	int	i;

	i = 0;
	if (!ft_isalpha(arg[i]) && (arg[i] != '_'))
		return (print_err_for_unset(arg), 0);
	i++;
	while (arg[i])
	{
		if (!ft_isalnum(arg[i]) && (arg[i] != '_'))
			return (print_err_for_unset(arg), 0);
		i++;
	}
	return (1);
}
