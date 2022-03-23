# include "../proto.h"

int	change_stdout(int fd)
{
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		printf("CHANGE_STDOUT\n");
		printf("%s\n", strerror(errno));
		return (-1);
	}
	close(fd);
	return (EXIT_SUCCESS);
}

int	change_stdin(int fd)
{
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		printf("CHANGE_STDIN\n");
		printf("%s\n", strerror(errno));
		return (-1);
	}
	close(fd);
	return (EXIT_SUCCESS);
}

int	right_redir(char *path)
{
	int		fd;

	fd = 0;
	if (path == NULL)
	{
		printf("RIGHT_REDIR : empty path\n");
		printf("%s\n", strerror(errno));
		return (-1);
	};
	fd = open(path, O_WRONLY|O_CREAT|O_TRUNC, 0755);
	if (fd == -1)
	{
		printf("RIGHT_REDIR : fail open(%s)\n", path);
		printf("%s\n", strerror(errno));
		return (-1);
	};
	if (change_stdout(fd) == EXIT_FAILURE)
	{
		printf("%s\n", strerror(errno));
		return (-1);
	}
	return (EXIT_SUCCESS);
}

int	double_right_redir(char *path)
{
	int		fd;

	fd = 0;
	if (path == NULL)
	{
		printf("RIGHT_REDIR\n");
		printf("%s\n", strerror(errno));
		return (EXIT_FAILURE);
	}
	fd = open(path, O_WRONLY|O_CREAT|O_APPEND, 0755);
	if (fd == -1)
	{
		printf("RIGHT_REDIR\n");
		printf("%s\n", strerror(errno));
		return (EXIT_FAILURE);
	}
	if (change_stdout(fd) == EXIT_FAILURE)
	{
		printf("%s\n", strerror(errno));
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	left_redir(char *path)
{
	int		fd;

	fd = 0;
	if (path == NULL)
	{
		printf("RIGHT_REDIR\n");
		printf("%s\n", strerror(errno));
		return (EXIT_FAILURE);
	};
	fd = open(path, O_RDONLY, NULL);
	if (fd == -1)
	{
		printf("LEFT_REDIR\n");
		printf("%s\n", strerror(errno));
		return (EXIT_FAILURE);
	}
	if (change_stdin(fd) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
void	ft_putendl_fd(char *s, int fd)
{
	if (fd < 0 || !(s))
		return ;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

int double_left_redi(char *path)
{
	int		fd;
	int 	pip[2];
	char	*line;
	
	fd = 0;
	pipe(pip);
	line = readline("> ");
	while (ft_strncmp(line, path, 5))
	{
		ft_putendl_fd(line, pip[1]);
	}
	close(pip[1]);
	dup2(pip[0], 0);
	close(pip[0]);
	pipe((*fds));
	return (0);
}

void	redir_hub(t_tree *root)
{
	if (root->left->left->type == LEFT_REDI)
		left_redir(root->left->right->data[0]);
	else if (root->left->left->type == RIGHT_REDI)
		right_redir(root->left->right->data[0]);
	else if (root->left->left->type == RIGHT_DOUBLE_REDI)
		double_right_redir(root->left->right->data[0]);
	else if (root->left->left->type == LEFT_DOUBLE_REDI)
		double_left_redi(root->left->right->data[0]);
	return ;
}
