#include "../includes/lem_in.h"

int			room_exist(char *room_name, t_rooms *rooms)
{
	t_rooms	*tmp;

	tmp = rooms;
	if (!rooms)
		return (0);
	while(tmp)
	{
		if (!ft_strcmp(room_name, tmp->data))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int			valid_room(char *room_name)
{
	char	**tmp;
	int		x;
	int		i;

	x = 0;
	i = 0;
	tmp = ft_strsplit(room_name, ' ');
	while (tmp[i])
		i++;
	if (i != 3)
		ft_error();
	i = -1;
	if (ft_isint(tmp[1]) && ft_isint(tmp[2]))
		x = 1;
	
	if (x)
		return (1);
	return (0);
}

t_rooms		*add_room(t_rooms *rooms, char *room_name, t_init *init)
{
	t_rooms	*node;
	t_rooms	*temp;
	int		i;

	if (!valid_room(room_name))
		ft_error();
	if (room_exist(room_name, rooms) || room_name[0] == 'L')
		ft_error();
	i = ft_strchr(room_name, ' ') - room_name;
	if (!(node = (t_rooms *)malloc(sizeof(t_rooms *))))
		ft_error();
	node->data = ft_strndup(room_name, i);
	node->next = NULL;
	ft_putendl(node->data);
	init->nb_rooms++;
	if (!rooms)
		rooms = node;
	else
	{
		temp = rooms;
		while(temp->next)
			temp = temp->next;
		temp->next = node;
	}
	return (rooms);
}
