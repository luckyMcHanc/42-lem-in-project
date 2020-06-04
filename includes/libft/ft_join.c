#include "libft.h"

char	*ft_jointostr(char *str, char *buff)
{
	char *limited;

	if (!str)
		return (NULL);
	limited = ft_strjoin(str, buff);
	free(str);
	return (limited);
}