/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:38:16 by tnakas            #+#    #+#             */
/*   Updated: 2024/08/09 18:24:24 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	print_header_utils_one(void)
{
	const char	*m;
	const char	*r;
	const char	*y;
	const char	*g;

	m = "\033[1;35m";
	y = "\033[1;33m";
	r = "\033[0m";
	g = "\033[1;32m";
	printf("┬┴┬┴┤╚(▲_▲)╝├┬┴┬┴┬┴┬┴┤･ω･)ﾉ├┬┴┬┴┬┴┬┴┤");
	printf("╚(▲_▲)╝├┬┴┬┴┬┴┬┴┤･ω･)ﾉ├\n");
	printf("%s┬┴┬┴┤･ω･)ﾉ├┬┴┬┴┬┴┬┴┤･ω･)ﾉ", g);
	printf("├┬┴┬┴┬┴┬┴┤･ω･)ﾉ├┬┴┬┴┬┴┬┴┤･ω･)ﾉ├┬┴┬┴%s\n", r);
	printf("%s========ʕ•̫͡•ʕ*̫͡*ʕ•͓͡•ʔ-̫͡-ʕ•̫͡•ʔ*̫͡*ʔ-̫͡-ʔ ", y);
	printf("ʕ•̫͡•ʕ*̫͡*ʕ•͓͡•ʔ-̫͡-ʕ•̫͡•ʔ*̫͡*ʔ-̫͡-ʔ========%s\n", r);
	printf("%s  __           _         _ __    ", m);
	printf("__   __   _            _  _  \n%s", r);
	printf("%s / /          (_)       (_)\\ ", m);
	printf("\\  / /   \\ \\ | |          | || | \n%s", r);
	printf("%s| | _ __ ___   _  _ __   _  | || | ", m);
	printf("___ | || |__    ___ | || | \n%s", r);
}

void	print_header(void)
{
	const char	*m;
	const char	*r;
	const char	*y;
	const char	*g;

	m = "\033[1;35m";
	y = "\033[1;33m";
	r = "\033[0m";
	g = "\033[1;32m";
	print_header_utils_one();
	printf("%s| || '_ ` _ \\ | || '_ \\ | | | ", m);
	printf("|| |/ __|| || '_ \\  / _ \\| || | \n%s", r);
	printf("%s| || | | | | || || | | || | ", m);
	printf("| || |\\__ \\| || | | ||  __/| || | \n%s", r);
	printf("%s| ||_| |_| |_||_||_| |_||_| ", m);
	printf("| || ||___/| ||_| |_| \\___||_||_| \n%s", r);
	printf("%s \\_\\                       /_/ ", m);
	printf(" \\_\\   /_/          \n%s", r);
	printf("%s========ʕ•̫͡•ʕ*̫͡*ʕ•͓͡•ʔ-̫͡-ʕ•̫͡•ʔ*̫͡*ʔ-̫͡-ʔ", y);
	printf("ʕ•̫͡•ʕ*̫͡*ʕ•͓͡•ʔ-̫͡-ʕ•̫͡•ʔ*̫͡*ʔ-̫͡-ʔ========%s\n", r);
	printf("%s┬┴┬┴┤･ω･)ﾉ├┬┴┬┴┬┴┬┴┤･ω･)ﾉ├┬┴┬┴┬┴┬┴┤", g);
	printf("･ω･)ﾉ├┬┴┬┴┬┴┬┴┤･ω･)ﾉ├┬┴┬┴%s\n", r);
	printf("┬┴┬┴┤╚(▲_▲)╝├┬┴┬┴┬┴┬┴┤･ω･)ﾉ├┬┴┬┴┬┴┬┴┤");
	printf("╚(▲_▲)╝├┬┴┬┴┬┴┬┴┤･ω･)ﾉ├\n");
}
