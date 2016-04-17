/*
** next_node.c for tekadv in /home/blanch_p/rendu/Semestre2/Infographie/gfx_tekadventure
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Sun Apr 17 13:09:04 2016 Alexandre Blanchard
** Last update Sun Apr 17 17:58:58 2016 Alexandre Blanchard
*/

#include "adventure.h"

#include <stdio.h>

int	check_node(t_data *data)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  printf("blablabla = %i\n", PLAN->node[data->player->cur_node]->type);
  if (PLAN->node[data->player->cur_node]->type == 1)
    {
      data->id_plan = 1;
      free_calque(data);
      load_decor_2(data);
      load_node_2(data);
      data->player->x = data->plan[0]->node[1]->pos.x;
      data->player->y = data->plan[0]->node[1]->pos.y;
      while (i < 4)
	{
	  j = 0;
	  while (j < 2)
	    {
	      data->player->mov[i]->calque[j]->x =
		data->plan[0]->node[1]->pos.x;
	      data->player->mov[i]->calque[j]->x_init =
		data->plan[0]->node[1]->pos.x;
	      data->player->mov[i]->calque[j]->y =
		data->plan[0]->node[1]->pos.y;
	      data->player->mov[i]->calque[j]->y_init =
		data->plan[0]->node[1]->pos.y;
	      j++;
	    }
	  i++;
	}
      data->player->cur_node = 1;
      /* data->player->next_node = 1; */
      data->player->dest_node = 1;
    }
  if (PLAN->node[data->player->cur_node]->type == 0)
    {
      data->id_plan = 0;
      free_calque(data);
      load_decor_1(data);
      load_node_1(data);
      data->player->x = data->plan[0]->node[1]->pos.x;
      data->player->y = data->plan[0]->node[1]->pos.y;
      while (i < 4)
	{
	  j = 0;
	  while (j < 2)
	    {
	      data->player->mov[i]->calque[j]->x =
		data->plan[0]->node[1]->pos.x;
	      data->player->mov[i]->calque[j]->x_init =
		data->plan[0]->node[1]->pos.x;
	      data->player->mov[i]->calque[j]->y =
		data->plan[0]->node[1]->pos.y;
	      data->player->mov[i]->calque[j]->y_init =
		data->plan[0]->node[1]->pos.y;
	      j++;
	    }
	  i++;
	}
      data->player->cur_node = 1;
      /* data->player->next_node = 1; */
      data->player->dest_node = 1;

    }
  
  
  return (0);
}

void	to_next_node(t_data *data)
{
  int	i;

  i = 0;
  if (data->player->cur_node == data->player->dest_node)
    {
      data->player->mov[CUR]->cur_pos = 1;
      check_node(data);
      data->player->chemin[0] = -1;
      return ;
    }
  while (data->player->chemin[i] != data->player->cur_node)
    {
      i++;
    }
  data->player->next_node = data->player->chemin[i + 1];
  /* printf("player est a %f, %f\n", data->player->x, data->player->y); */
  /* printf("pos %i, %i\n", data->plan[data->id_plan]->node[i + 1]->pos.x, data->plan[data->id_plan]->node[i + 1]->pos.y); */

  calc_coef(data->player->x, data->player->y,
	    &data->plan[0]->
	    node[data->player->next_node]->pos, data);
  
}
