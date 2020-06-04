#include "../includes/lem_in.h"

void	initializer(t_init *init)
{
	t_init	*temp;

	temp = init;
	temp->start = NULL;
	temp->end = NULL;
	temp->line = NULL;
	temp->nb_ants = 0;
	temp->nb_rooms = 0;
	temp->nb_r = 0;
}

void	is_map_valid(t_init *init)
{
	if (init->start == NULL || init->end == NULL)
		ft_error();
}

void	get_ants(t_init *init)
{
	char	*line;

	while(get_next_line(0, &line) == 1)
	{
		if(ft_isint(line) && ft_atoi(line) > 0)
		{
			init->nb_ants = ft_atoi(line);
			free(line);
			break ;
		}
		else
		{
			if (line[0] != '#')
				ft_error();
		}
		free(line);
	}
	ft_putnbr(init->nb_ants);
	ft_putchar('\n');
}

int	main(void)
{
	t_init	init;
	t_rooms	*rooms;
	t_links	*links;
	t_path	*visit;
	t_path	*map;

	rooms = NULL;
	map = NULL;
	links = NULL;
	visit = NULL;
	initializer(&init);
	get_ants(&init);
	rooms = create_rooms(&init, rooms);
	links = create_links(links, rooms, &init);
	is_map_valid(&init);
	visit = find_path(rooms, links, &init, visit);
	map = create_map(visit, map, rooms, &init);
	map = display_ants(map, &init);

	return (0);
}
