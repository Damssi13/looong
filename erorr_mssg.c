#include "long.h"

void erorr_mssg(char *str, t_game *data)
{
    ft_putstr("Error:\n");
    ft_putstr(str);
    checks_free(data);
    exit(1);
}
void    exit_mssg(char *str)
{
    ft_putstr("Error:\n");
    ft_putstr(str);
    exit(1);
}

void	check_name(char *name)
{
	int	len;


	len = ft_strlen(name);
	if (len >= 4 && ft_strncmp(name + len - 4, ".ber", 4) == 0)
		return ;
	else
		exit_mssg("Uncorrect extention");;
}