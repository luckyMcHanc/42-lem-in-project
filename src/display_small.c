#include "../includes/lem_in.h"

int         print_first(int x, char **tmp, t_init *init)
{
	int c;
	int a;

	c = 1;
	a = 0;
	if (x >= init->nb_ants)
		return (2);
	while (a < x && tmp[a])
		a++;
	while (c <= x && x < init->nb_ants)
	{
		ft_putchar('L');
		ft_putnbr(c);
		ft_putchar('-');
		ft_putstr(tmp[a]);
		ft_putchar(' ');
		a--;
		c++;
	}
	ft_putchar('\n');
	return (1);
}

int         print_medium(int x, char **tmp, t_init *init)
{
	int a;
	int b;
	int c;
	int d;

	a = x - 1;
	b = 1;
	c = 1;
	d = 1;
	if (a >= init->nb_r)
		return (3);
	while(b <= init->nb_ants)
	{
		if (!ft_strcmp(tmp[a], init->end))
			d = 2;
		ft_putchar('L');
		ft_putnbr(c);
		ft_putchar('-');
		ft_putstr(tmp[a]);
		ft_putchar(' ');
		a--;
		c++;
		b++;
	}
	ft_putchar('\n');
	if (d == 2)
		return (3);
	return (2);
}

int		    print_last(int x, char **map, t_init *init, int pn)
{
	int     a;
	int     b;
	int     c;
	int     i;
	char	**tmp;

	b = pn - x;
	c = x - init->nb_r + 1;
	tmp = map;
	a = 1;
	i = init->nb_r - 1;
	while (a <= b && b <= init->nb_ants)
	{
		ft_putchar('L');
		ft_putnbr(c);
		ft_putchar('-');
		ft_putstr(tmp[i]);
		ft_putchar(' ');
		a++;
		c++;
		i--;
	}
	ft_putchar('\n');
	return (3);
}

char		**display_small(t_init *init, char **temp, int pn)
{
	int x;
	int status;

	x = 1;
	status = 1;
	while(x < pn)
	{
		if (status == 1)
			status = print_first(x, temp, init);
		else if (status == 2)
			status = print_medium(x, temp, init);
		else if (status == 3)
			status = print_last(x, temp, init, pn);
		x++;
	}
	return(temp);
}
