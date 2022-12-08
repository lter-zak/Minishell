
#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <stdio.h>

void	parsing(char *str);
int		ft_strcmp(char *str, char *cmd);

# endif