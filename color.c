#include "fdf.h"

int	push_color(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
		{
			i += 2;
		}
		i++;
	}
}

int	parse_color(char *str)
{
	t_color color;
	long value;


}
