
#include "../include/so_long.h"
#include "../include/window.h"

void	move_w(t_game *g)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(g->matrix) && g->matrix[i] != 'P')
		i++;

	if (g->matrix[i - g->w] == 'C')
		g->coll_cnt++;

	if (g->matrix[i - g->w] == 'E' && g->all_coll == g->coll_cnt)
		exit_game(g);

	else if (g->matrix[i - g->w] != '1' && g->matrix[i - g->w] != 'E')
	{
		g->matrix[i] = '0';
		g->matrix[i - g->w] = 'P';
		g->walk_cnt++;
		ft_printf("%d\n", g->walk_cnt);
		set_img(g, 'w');
		if (g->all_coll == g->coll_cnt)
			set_open_exit(g);
	}
}
