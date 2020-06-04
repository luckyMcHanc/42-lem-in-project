#include "../includes/lem_in.h"

int			visited_before(int *visited, int v, int i)
{
	int	x;

	x = 0;
	while(x < i)
	{
		if (visited[x] == v)
			return (1);
		x++;
	}
	return (0);
}

t_path		*init_path(t_path *visit, t_init *init, int start)
{
	if (!(visit = (t_path *)malloc(sizeof(t_path))))
		ft_error();
	if (!(visit->visited = (int *)malloc(sizeof(int) * init->nb_rooms + 1)))
		ft_error();
	visit->visited[0] = start;
	return (visit);
}

t_visit		*init_visit(t_visit *visit, t_init *init, int start)
{
	if (!(visit = (t_visit *)malloc(sizeof(t_visit))))
		ft_error();
	if (!(visit->path = (int *)malloc(sizeof(int) * init->nb_rooms + 1)))
		ft_error();
	visit->path[0] = start;
	return (visit);
}


int        ft_minus(int j)
{
	j = j - 1;
	if( j < 0)
		ft_error();
	return (j);
}

t_path		*visit_rooms(t_path *visit, int start, int end, t_init *init, t_links *links, t_visit *path)
{
	int	x;
	int	j;
	int	a;
	int b;

	j = 0;
	b = 0;
	a = -1;
	while (a != end)
	{
		x = 0;
		while (x < init->nb_rooms)
		{
			if (links->links[start][x] == 1 && !visited_before(path->path, x, init->nb_rooms))
			{
				visit->visited[++j] = x;
				path->path[++b] = x;
				if (x == end)
				{
					visit->visited[j] = x;
					a = x;   
					break;
				}
				start = x;
				x = 0;
			}
			x++;
		}
		j = ft_minus(j);
		start = visit->visited[j];
	}
	return (visit);
}

t_path		*find_path(t_rooms *rooms, t_links *links, t_init *init, t_path  *visit)
{
	int	start;
	int	end;
	t_visit *path;

	path = NULL;
	start = exist_link(init->start, rooms);
	end = exist_link(init->end, rooms);
	visit = init_path(visit, init, start);
	path = init_visit(path, init, start);
	visit = visit_rooms(visit, start, end, init, links, path);
	return (visit);
}
