#include "../includes/lem_in.h"

char		**reverse(t_path *head, char **tmp, t_init *init)
{
	t_path	*map;
	int		i;

	map = head;
	i = 0;
	if (!(tmp = (char **)malloc(sizeof(char *) * init->nb_r)))
		ft_error();
	while (map)
	{
		if (!(tmp[i] = (char *)malloc(sizeof(char) * ft_strlen(map->map))))
			ft_error();
		tmp[i] = ft_strcpy(tmp[i], map->map);
		map = map->next;
		i++;
	}
	return (tmp);
}

int			ft_positive(int x, char **map, t_init *init)
{
	int		a;
	char	**tmp;
	int		c;

	tmp = map;
	a = 0;
	while (a < x && tmp[a])
	{
		a++;
	}
	c = 1;
	if (x == (init->nb_r - 1))
		return (2);
	while (c <= x)
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
	if (x >= init->nb_ants)
		return (2);
	return (1);
}

int			ft_constant(int x, char **map, t_init *init)
{
	int		a;
	int		b;
	int		c;
	char	**tmp;

	tmp = map;
	a = init->nb_r - 1;
	c = x - init->nb_r + 1;
	b = 1;
	while(b < init->nb_r)
	{
		ft_putchar('L');
		ft_putnbr(c);
		ft_putchar('-');	
		ft_putstr(tmp[a]);
		ft_putchar(' ');
		a--;
		b++;
		c++;
	}
	ft_putchar('\n');
	if (x >= init->nb_ants)
		return (3);
	return 2;
}

int			ft_negative(int x, char **map, t_init *init, int pn)
{
	int		a;
	int		b;
	int		c;
	int		i;
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

t_path		*display_ants(t_path *map, t_init *init)
{
	int		x;
	int		pn;
	int		status;
	char	**tmp;

	x = 1;
	status = 1;
	tmp = NULL;
	pn = init->nb_ants + init->nb_r;
	tmp = reverse(map, tmp, init);
	ft_putchar('\n');
	if (init->nb_ants < init->nb_r)
		tmp = display_small(init, tmp, pn);
	else
	{		
		while (x < pn)
		{
			if (status == 1)
				status = ft_positive(x, tmp, init);
			else if (status == 2)
				status = ft_constant(x, tmp, init);
			else if (status == 3)
				status = ft_negative(x, tmp, init, pn);
			x++;
		}	
	}
	
	return (map);
}
