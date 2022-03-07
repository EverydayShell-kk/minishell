#include "../proto.h"

void	env_add(t_info *info, char *key, char *content)
{
	t_list *check;

	check = sh_lstnew(NULL);
	check->type = O_ENV;
	check->content = content;
	check->key = key;
	sh_lstadd_back(&info->head, check);
}

char **made_temp(t_info *info)
{
	char **s = NULL;
	int len;
	t_token *check;

	len = 1;
	check = info->t_head->next;
	while (check->next != NULL)
	{
		check = check->next;
		len++;
	}
	char **str  = malloc(sizeof(char *) * (len + 1));
	s = str;
	check = info->t_head->next;
	while (check->next != NULL)
	{
		*str = ft_strdup(check->data);
		check = check->next;
		str++;
	}
	*str = ft_strdup(check->data);
	str++;
	*str = NULL;
	
	return (s);
}

int	str_len(char **str)
{
	int len;
	char **temp;

	len = 0;
	temp = str;
	while (*temp)
	{
		len++;
		temp++;
	}
	return (len);
}

void	implement_cmd(t_info *info, int *exit_signal)
{
	int fd[2];

	fd[0] = STDIN_FILENO;
	fd[1] = STDOUT_FILENO; 
	if (!ft_strncmp("env", info->t_head->next->data, 4))
		builtin_env(info, fd[1], exit_signal);
	else if (!ft_strncmp("export", info->t_head->next->data, 7))
		builtin_export(info, fd[1], exit_signal);
	else if (!ft_strncmp("unset", info->t_head->next->data, 6))
		builtin_unset(info, exit_signal);
	else if (!ft_strncmp("pwd", info->t_head->next->data, 4))
		builtin_pwd(info, fd[1], exit_signal);
	else if (!ft_strncmp("cd", info->t_head->next->data, 3))
		builtin_cd(info, exit_signal);
	else if (!ft_strncmp("echo", info->t_head->next->data, 5))
		builtin_echo(info, fd[1], exit_signal);
	else if (!ft_strncmp("exit", info->t_head->next->data, 5))
		builtin_exit(info, exit_signal);
}