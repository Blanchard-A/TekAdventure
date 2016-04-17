/*
** load_node.c for tekadv in /home/blanch_p/rendu/Semestre2/Infographie/gfx_tekadventure
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Sun Apr 17 10:24:01 2016 Alexandre Blanchard
** Last update Sun Apr 17 23:01:45 2016 Alexandre Blanchard
*/

#include "adventure.h"

int	malloc_node_1(t_data *data)
{
  int	i;

  i = 0;
  if ((data->plan[0]->node = bunny_malloc(sizeof(t_node *) * 11)) == NULL)
    return (-1);
  while (i < 10)
    {
      if ((PLAN->node[i] = bunny_malloc(sizeof(t_node) * 1)) == NULL ||
	  (PLAN->node[i]->way = bunny_malloc(sizeof(int) * 3)) == NULL)
	return (-1);
      i++;
    }
  data->plan[0]->node[10] = NULL;
  return (0);
}
int	malloc_node_2(t_data *data)
{
  int	i;

  i = 0;
  if ((data->plan[0]->node = bunny_malloc(sizeof(t_node *) * 4)) == NULL)
    return (-1);
  while (i < 3)
    {
      if ((PLAN->node[i] = bunny_malloc(sizeof(t_node) * 1)) == NULL ||
	  (PLAN->node[i]->way = bunny_malloc(sizeof(int) * 3)) == NULL)
	return (-1);
      i++;
    }
  data->plan[0]->node[3] = NULL;
  return (0);
}

void	load_node_2_1(t_data *data)
{
  data->plan[0]->node[2]->pos.x = 860;
  data->plan[0]->node[2]->pos.y = 691;
  data->plan[0]->node[2]->way[0] = 1;
  data->plan[0]->node[2]->way[1] = -1;
  data->plan[0]->node[2]->way[2] = -1;
  data->plan[0]->node[2]->pos_way = 2;
  data->plan[0]->node[2]->scale = 100;
  data->plan[0]->node[2]->id_cal = 0;
  data->plan[0]->node[2]->type = 0;
}

int	load_node_2(t_data *data)
{
  if (malloc_node_2(data) == -1)
    return (-1);
  data->plan[0]->node[0]->pos.x = 422;
  data->plan[0]->node[0]->pos.y = 616;
  data->plan[0]->node[0]->way[0] = 1;
  data->plan[0]->node[0]->way[1] = -1;
  data->plan[0]->node[0]->way[2] = -1;
  data->plan[0]->node[0]->pos_way = 0;
  data->plan[0]->node[0]->scale = 100;
  data->plan[0]->node[0]->id_cal = 0;
  data->plan[0]->node[0]->type = -1;
  data->plan[0]->node[1]->pos.x = 588;
  data->plan[0]->node[1]->pos.y = 677;
  data->plan[0]->node[1]->way[0] = 1;
  data->plan[0]->node[1]->way[1] = -1;
  data->plan[0]->node[1]->way[2] = -1;
  data->plan[0]->node[1]->pos_way = 1;
  data->plan[0]->node[1]->scale = 100;
  data->plan[0]->node[1]->id_cal = 0;
  data->plan[0]->node[1]->type = -1;
  load_node_2_1(data);
  return (0);
}
