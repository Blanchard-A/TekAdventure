/*
** next_node.c for tekadv in /home/blanch_p/rendu/Semestre2/Infographie/gfx_tekadventure
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Sun Apr 17 13:09:04 2016 Alexandre Blanchard
** Last update Sun Apr 17 15:23:39 2016 Alexandre Blanchard
*/

#include "adventure.h"

#include <stdio.h>

void	to_next_node(t_data *data)
{
  int	i;

  i = 0;
  if (data->player->cur_node == data->player->dest_node)
    {
      data->player->mov[CUR]->cur_pos = 1;
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
	    &data->plan[data->id_plan]->
	    node[data->player->next_node]->pos, data);
  
}
