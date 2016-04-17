/*
** next_node.c for tekadv in /home/blanch_p/rendu/Semestre2/gfx_tekadventure
**
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
**
** Started on  Sun Apr 17 13:09:04 2016 Alexandre Blanchard
** Last update Sun Apr 17 23:25:20 2016 Alexandre Blanchard
*/

#include "adventure.h"

int	init_check_node(t_data *data)
{
  data->id_plan = PLAN->node[data->player->cur_node]->type;
  free_calque(data);
  if (PLAN->node[data->player->cur_node]->type == 1)
    {
      if (load_decor_2(data) == NULL ||
	  load_node_2(data) == - 1)
	return (- 1);
    }
  else if (PLAN->node[data->player->cur_node]->type == 0)
    {
      if (load_decor_1(data) == NULL ||
	  load_node_1(data) == - 1)
	return (- 1);
    }
  data->player->x = data->plan[0]->node[1]->pos.x;
  data->player->y = data->plan[0]->node[1]->pos.y;
  return (0);
}

int	check_node(t_data *data)
{
  int	i;
  int	j;

  i = - 1;
  if (init_check_node(data) == - 1)
    return (- 1);
  while (++i < 4)
    {
      j = - 1;
      while (++j < 2)
	{
	  data->player->mov[i]->calque[j]->x =
	    data->plan[0]->node[1]->pos.x;
	  data->player->mov[i]->calque[j]->x_init =
	    data->plan[0]->node[1]->pos.x;
	  data->player->mov[i]->calque[j]->y =
	    data->plan[0]->node[1]->pos.y;
	  data->player->mov[i]->calque[j]->y_init =
	    data->plan[0]->node[1]->pos.y;
	}
    }
  data->player->cur_node = 1;
  data->player->dest_node = 1;
  return (0);
}

int	to_next_node(t_data *data)
{
  int	i;

  i = 0;
  if (data->player->cur_node == data->player->dest_node)
    {
      data->player->mov[CUR]->cur_pos = 1;
      if (PLAN->node[data->player->cur_node]->type >= 0)
	if (check_node(data) == - 1)
	  return (- 1);
      data->player->chemin[0] = -1;
      return (0);
    }
  while (data->player->chemin[i] != data->player->cur_node)
    {
      i++;
    }
  data->player->next_node = data->player->chemin[i + 1];
  calc_coef(data->player->x, data->player->y,
	    &data->plan[0]->
	    node[data->player->next_node]->pos, data);
  return (0);
}
