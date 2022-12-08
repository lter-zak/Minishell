
#include "minishell.h"

int	main(int arg_nb, char **argv, char **env)
{
	(void)arg_nb;
	(void)argv;
	(void)env;
	char *str;

	while (1)
	{
		str = readline ("Minishell$> ");
		parsing(str);
	}
	return (0);
}
