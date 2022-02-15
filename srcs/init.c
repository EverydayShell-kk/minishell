#include "proto.h"

int	init_info(t_info **info)
{
	(*info) = malloc(sizeof(t_info));
	(*info)->cmd = 0;
	(*info)->pipe_flag = -1;
	(*info)->redirection_flag = -1;
	(*info)->double_shift_flag = -1;
	return (EXIT_SUCCESS);
}