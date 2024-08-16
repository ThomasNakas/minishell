/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_utils_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:57:37 by sganiev           #+#    #+#             */
/*   Updated: 2024/08/16 15:02:10 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// handle env vars expansion
bool	handle_heredoc(char *end, int *p)
{
	static bool	is_opened = false;
	char		*str;

	if (is_opened)
	{
		close(p[0]);
		is_opened = false;
	}
	if (pipe(p) == -1)
		return (false);
	is_opened = true;
	while (true)
	{
		str = readline(GRAY"> "RESET);
		if (!str || (ft_strcmp(str, end) == 0))
			break ;
		write(p[1], str, ft_strlen(str));
		write(p[1], "\n", 1);
		free(str);
	}
	close(p[1]);
	if (str)
		free(str);
	return (true);
}

void	create_file(char *file, int mode)
{
	int	fd;

	fd = open(file, mode, 0666);
	if (fd == -1)
		return ;
	close(fd);
}

void	close_read_end(t_pipe_group *cmd)
{
	if (cmd->is_heredoc_in)
		close(cmd->heredoc_p[0]);
	cmd->is_heredoc_in = false;
}

void	print_array(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		printf("str[%d] = %s\n", i, str[i]);
	printf("(null)\n");
}
