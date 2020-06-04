#include "../includes/lem_in.h"

int			node_exist(char *node, t_path *map)
{
	t_path	*tmp;

	tmp = map;
	while(tmp)
	{
		if (!ft_strcmp(node, map->map))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_path		*add_to_map(t_path *map, t_rooms *rooms, t_init *init)
{
	t_path	*node;
	t_path	*tmp;

	if (node_exist(rooms->data, map))
		return (map);
	if (!(node = (t_path *)malloc(sizeof(t_path *))))
		ft_error();
	node->map = ft_strdup(rooms->data);
	node->next = NULL;
	if (!map)
		map = node;
	else
	{
		tmp = map;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
	init->nb_r++;
	return (map);
}

t_path		*create_map(t_path *visit, t_path *map, t_rooms *rooms, t_init *init)
{
	int		x;
	int		j;
	t_rooms	*tmp;

	x = 0;
	while (x < init->nb_rooms && x > -1)
	{
		j = 0;
		tmp = rooms;
		while (j < init->nb_rooms && tmp)
		{
			if (j == visit->visited[x])
				map = add_to_map(map, tmp, init);
			tmp = tmp->next;
			j++;
		}
		x++;
	}
	return (map);
}
