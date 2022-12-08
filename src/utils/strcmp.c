#include "minishell.h"
int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
int ft_strcmp(char *str, char *cmd)
{
	int i;
	int j;
	int len;
int flag = 0;
	i = 0;
	j = 0;
	len = ft_strlen(cmd);
	while (cmd && str && cmd[j] && str[i])
	{
		// if (str[i] != cmd[j])
		// 	i++;
		while (str[i] == cmd[j])
		{
			if (j == len - 1)
				return (1);
				
			i++;
			j++;
		}
		if (j == 0)
				flag =1;
			j = 0;
			if (flag)
				i++;
	}
	return (0);
}