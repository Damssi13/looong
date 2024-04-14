#include "long.h"

void    ft_putstr(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        write(2, &str[i], 1);
        i++;
    }
}

void erorr_mssg(char *str)
{
    ft_putstr(str);
    exit(1);
}