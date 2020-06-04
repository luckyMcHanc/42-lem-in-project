#include "../includes/lem_in.h"

int     	is_position(char *line)
{
	if (!ft_strcmp(line, "##start"))
		return 1;
	else if (!ft_strcmp(line, "##end"))
		return 2;
	return 0;
}

void    	room_name(char *line, t_init *init, int state)
{
	int		i;
	char	**name;

	if (!ft_strchr(line, ' ') || ft_strchr(line, '#') || line[0] == 'L')
		ft_error(); 
	name = ft_strsplit(line, ' ');
	i = 0;
	while (name[i])
		i++;
	if (i != 3)
		ft_error();
	if (state == 1)
		init->start = ft_strdup(name[0]);
	if (state == 2)
		init->end = ft_strdup(name[0]);
	i = 0;
	
}

t_rooms    *create_rooms(t_init *init, t_rooms *rooms)
{
	char	*line;
	char	*tmp;
	int		state;

	state = 0;
	while (get_next_line(0, &line) == 1)
	{
		tmp = ft_strdup(line);
		if (state > 0)
			room_name(tmp, init, state);
		state = is_position(line);
		if (line[0] != '#' && ft_strchr(line, ' '))
			rooms = add_room(rooms, line, init);
		if (!ft_strchr(line, ' ') && line[0] != '#')
		{
			init->line = ft_strdup(line);
			break ;
		}
		
	}
	if (ft_strlen(line) == 0)
	    ft_error();
	
	return (rooms);
}
