#include "long.h"
void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putnbr(int n)
{

    if(n == -2147483648)
    {
        write(1,"-2147483648", 11);
        return ;
    }
    if(n < 0)
    {
        ft_putchar('-');
        n *= -1;
    }
    if(n > 9)
    {
        ft_putnbr(n / 10);
        ft_putnbr(n % 10);
    }
    if(n < 10)
        ft_putchar(n + 48);
}

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