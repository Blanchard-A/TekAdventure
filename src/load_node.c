/*
** load_node.c for tekadv in /home/blanch_p/rendu/Semestre2/Infographie/gfx_tekadventure
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Sun Apr 17 10:24:01 2016 Alexandre Blanchard
** Last update Sun Apr 17 21:41:59 2016 Voyevoda
*/

#include "adventure.h"

void	malloc_node_1(t_data *data)
{
  int	i;

  i = 0;
  data->plan[0]->node = malloc(sizeof(t_node *) * 11);
  while (i < 10)
    {
      data->plan[0]->node[i] = malloc(sizeof(t_node) * 1);
      data->plan[0]->node[i]->way = malloc(sizeof(int) * 3);
      i++;
    }
  data->plan[0]->node[10] = NULL;
}

void	load_node_1(t_data *data)
{
  malloc_node_1(data);
  
  data->plan[0]->node[0]->pos.x = 338;
  data->plan[0]->node[0]->pos.y = 367;
  data->plan[0]->node[0]->way[0] = 1;
  data->plan[0]->node[0]->way[1] = 2;
  data->plan[0]->node[0]->way[2] = 3;
  data->plan[0]->node[0]->pos_way = 0;

  data->plan[0]->node[1]->pos.x = 193;
  data->plan[0]->node[1]->pos.y = 409;
  data->plan[0]->node[1]->way[0] = 1;
  data->plan[0]->node[1]->way[1] = 2;
  data->plan[0]->node[1]->way[2] = 3;
  data->plan[0]->node[1]->pos_way = 1;

  data->plan[0]->node[2]->pos.x = 294;
  data->plan[0]->node[2]->pos.y = 450;
  data->plan[0]->node[2]->way[0] = 1;
  data->plan[0]->node[2]->way[1] = 3;
  data->plan[0]->node[2]->way[2] = -1;
  data->plan[0]->node[2]->pos_way = 2;

  data->plan[0]->node[3]->pos.x = 180;
  data->plan[0]->node[3]->pos.y = 485;
  data->plan[0]->node[3]->way[0] = 1;
  data->plan[0]->node[3]->way[1] = -1;
  data->plan[0]->node[3]->way[2] = -1;
  data->plan[0]->node[3]->pos_way = 3;

  data->plan[0]->node[4]->pos.x = 131;
  data->plan[0]->node[4]->pos.y = 334;
  data->plan[0]->node[4]->way[0] = 2;
  data->plan[0]->node[4]->way[1] = -1;
  data->plan[0]->node[4]->way[2] = -1;
  data->plan[0]->node[4]->pos_way = 2;

  data->plan[0]->node[5]->pos.x = 126;
  data->plan[0]->node[5]->pos.y = 174;
  data->plan[0]->node[5]->way[0] = 2;
  data->plan[0]->node[5]->way[1] = -1;
  data->plan[0]->node[5]->way[2] = -1;
  data->plan[0]->node[5]->pos_way = 3;

  data->plan[0]->node[6]->pos.x = 618;
  data->plan[0]->node[6]->pos.y = 161;
  data->plan[0]->node[6]->way[0] = 2;
  data->plan[0]->node[6]->way[1] = -1;
  data->plan[0]->node[6]->way[2] = -1;
  data->plan[0]->node[6]->pos_way = 4;

  data->plan[0]->node[7]->pos.x = 460;
  data->plan[0]->node[7]->pos.y = 420;
  data->plan[0]->node[7]->way[0] = 3;
  data->plan[0]->node[7]->way[1] = -1;
  data->plan[0]->node[7]->way[2] = -1;
  data->plan[0]->node[7]->pos_way = 3;

  data->plan[0]->node[8]->pos.x = 678;
  data->plan[0]->node[8]->pos.y = 386;
  data->plan[0]->node[8]->way[0] = 3;
  data->plan[0]->node[8]->way[1] = -1;
  data->plan[0]->node[8]->way[2] = -1;
  data->plan[0]->node[8]->pos_way = 4;

  data->plan[0]->node[9]->pos.x = 989;
  data->plan[0]->node[9]->pos.y = 447;
  data->plan[0]->node[9]->way[0] = 3;
  data->plan[0]->node[9]->way[1] = -1;
  data->plan[0]->node[9]->way[2] = -1;
  data->plan[0]->node[9]->pos_way = 5;  
}
