#include "../includes/lem_in.h"

t_links		*init_links(t_links *links, int i)
{
	int	x;

	x = 0;
	if (!(links = (t_links *)malloc(sizeof(t_links))))
		ft_error(0);
	if (!(links->links = (int **)malloc(sizeof(int*) * i)))
		ft_error(0);
	while (x < i)
	{
		if (!(links->links[x] = (int *)malloc(sizeof(int) * i)))
			ft_error(0);
		x++;
	}
	return (links);
}

int			exist_link(char *exist, t_rooms *rooms)
{
	int		i;
	t_rooms	*tmp;

	i = 0;
	tmp = rooms;
	while (tmp)
	{
		if (!ft_strcmp(exist, tmp->data))
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (-1);
}


t_links		*add_link(t_rooms *rooms, t_links *links, char *line)
{
	char	**li;
	int		a;
	int		b;

	li = ft_strsplit(line, '-');
	a = 0;
	while(li[a])
		a++;
	if (a != 2)
		ft_error();
	a = exist_link(li[0], rooms);
	b = exist_link(li[1], rooms);

	ft_putendl(line);
	if (a ==-1 || b == -1)
		ft_error();
	links->links[a][b] = 1;
	links->links[b][a] = 1;
	return (links);
}

t_links		*create_links(t_links   *links, t_rooms *rooms, t_init *init)
{
	int		i;

	i = init->nb_rooms;
	links = init_links(links, i);
	if (init->line)
		links = add_link(rooms, links, init->line);

	while(get_next_line(0, &init->line) == 1)
	{
		if (init->line[0] != '#')
			links = add_link(rooms, links, init->line);
	
	}
	return (links);
}
