#include "libft/libft.h"

typedef struct		s_depedents
{
	char		*start;
	char		*end;
	int		nb_ants;
	int		nb_rooms;
	int		nb_r;
	char		*line;
}			t_init;


typedef struct		s_rooms
{
	struct s_rooms	*next;
	char		*data;
}			t_rooms;

typedef struct		s__links
{
	int		**links;
}			t_links;

typedef struct		s_path
{
	int		*visited;
	char		*map;
	struct  s_path	*next;
}			t_path;

typedef struct		s_visit
{
	int		*path;
}			t_visit;

t_rooms		*create_rooms(t_init *init, t_rooms *t_rooms);
t_rooms		*add_room(t_rooms *rooms, char *room_name, t_init *init);
t_links		*create_links(t_links   *links, t_rooms *rooms, t_init *init);
int		exist_link(char *exist, t_rooms *rooms);
t_path		*find_path(t_rooms *rooms, t_links *links, t_init *init, t_path  *visit);
t_path		*create_map(t_path *visit, t_path *map, t_rooms *rooms, t_init *init);
t_path		*display_ants(t_path *map, t_init *init);
void		free_data(t_links *links, t_rooms *rooms, t_path *visit, t_init *init, t_path *map);
char 		**display_small(t_init *init, char **temp, int pn);

void		ft_error();
