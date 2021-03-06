/*
** load_node_1.c for tek_adv in /home/blanch_p/Infographie/gfx_tekadventure
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Sun Apr 17 22:43:02 2016 Alexandre Blanchard
** Last update Sun Apr 17 23:01:11 2016 Alexandre Blanchard
*/

#include "adventure.h"

void	load_node_1_4(t_data *data)
{
  data->plan[0]->node[9]->way[2] = -1;
  data->plan[0]->node[9]->pos_way = 5;
  data->plan[0]->node[9]->scale = 25;
  data->plan[0]->node[9]->id_cal = 4;
  data->plan[0]->node[9]->type = -1;
}

void	load_node_1_3(t_data *data)
{
  data->plan[0]->node[7]->way[1] = -1;
  data->plan[0]->node[7]->way[2] = -1;
  data->plan[0]->node[7]->pos_way = 3;
  data->plan[0]->node[7]->scale = 25;
  data->plan[0]->node[7]->id_cal = 4;
  data->plan[0]->node[7]->type = -1;
  data->plan[0]->node[8]->pos.x = 678;
  data->plan[0]->node[8]->pos.y = 386;
  data->plan[0]->node[8]->way[0] = 3;
  data->plan[0]->node[8]->way[1] = -1;
  data->plan[0]->node[8]->way[2] = -1;
  data->plan[0]->node[8]->pos_way = 4;
  data->plan[0]->node[8]->scale = 25;
  data->plan[0]->node[8]->id_cal = 4;
  data->plan[0]->node[8]->type = -1;
  data->plan[0]->node[9]->pos.x = 989;
  data->plan[0]->node[9]->pos.y = 447;
  data->plan[0]->node[9]->way[0] = 3;
  data->plan[0]->node[9]->way[1] = -1;
  load_node_1_4(data);
}

void	load_node_1_2(t_data *data)
{
  data->plan[0]->node[4]->id_cal = 4;
  data->plan[0]->node[4]->type = -1;
  data->plan[0]->node[5]->pos.x = 126;
  data->plan[0]->node[5]->pos.y = 204;
  data->plan[0]->node[5]->way[0] = 2;
  data->plan[0]->node[5]->way[1] = -1;
  data->plan[0]->node[5]->way[2] = -1;
  data->plan[0]->node[5]->pos_way = 3;
  data->plan[0]->node[5]->scale = 25;
  data->plan[0]->node[5]->id_cal = 3;
  data->plan[0]->node[5]->type = -1;
  data->plan[0]->node[6]->pos.x = 618;
  data->plan[0]->node[6]->pos.y = 171;
  data->plan[0]->node[6]->way[0] = 2;
  data->plan[0]->node[6]->way[1] = -1;
  data->plan[0]->node[6]->way[2] = -1;
  data->plan[0]->node[6]->pos_way = 4;
  data->plan[0]->node[6]->scale = 25;
  data->plan[0]->node[6]->id_cal = 3;
  data->plan[0]->node[6]->type = -1;
  data->plan[0]->node[7]->pos.x = 460;
  data->plan[0]->node[7]->pos.y = 420;
  data->plan[0]->node[7]->way[0] = 3;
  load_node_1_3(data);
}

void	load_node_1_1(t_data *data)
{
  data->plan[0]->node[2]->way[1] = 3;
  data->plan[0]->node[2]->way[2] = -1;
  data->plan[0]->node[2]->pos_way = 2;
  data->plan[0]->node[2]->scale = 25;
  data->plan[0]->node[2]->id_cal = 4;
  data->plan[0]->node[2]->type = -1;
  data->plan[0]->node[3]->pos.x = 180;
  data->plan[0]->node[3]->pos.y = 485;
  data->plan[0]->node[3]->way[0] = 1;
  data->plan[0]->node[3]->way[1] = -1;
  data->plan[0]->node[3]->way[2] = -1;
  data->plan[0]->node[3]->pos_way = 3;
  data->plan[0]->node[3]->scale = 25;
  data->plan[0]->node[3]->id_cal = 4;
  data->plan[0]->node[3]->type = -1;
  data->plan[0]->node[4]->pos.x = 111;
  data->plan[0]->node[4]->pos.y = 334;
  data->plan[0]->node[4]->way[0] = 2;
  data->plan[0]->node[4]->way[1] = -1;
  data->plan[0]->node[4]->way[2] = -1;
  data->plan[0]->node[4]->pos_way = 2;
  data->plan[0]->node[4]->scale = 25;
  load_node_1_2(data);
}

int	load_node_1(t_data *data)
{
  if (malloc_node_1(data) == -1)
    return (-1);
  data->plan[0]->node[0]->pos.x = 372;
  data->plan[0]->node[0]->pos.y = 350;
  data->plan[0]->node[0]->way[0] = 1;
  data->plan[0]->node[0]->way[1] = 2;
  data->plan[0]->node[0]->way[2] = 3;
  data->plan[0]->node[0]->pos_way = 0;
  data->plan[0]->node[0]->scale = 25;
  data->plan[0]->node[0]->id_cal = 4;
  data->plan[0]->node[0]->type = 1;
  data->plan[0]->node[1]->pos.x = 193;
  data->plan[0]->node[1]->pos.y = 409;
  data->plan[0]->node[1]->way[0] = 1;
  data->plan[0]->node[1]->way[1] = 2;
  data->plan[0]->node[1]->way[2] = 3;
  data->plan[0]->node[1]->pos_way = 1;
  data->plan[0]->node[1]->scale = 25;
  data->plan[0]->node[1]->id_cal = 4;
  data->plan[0]->node[1]->type = -1;
  data->plan[0]->node[2]->pos.x = 294;
  data->plan[0]->node[2]->pos.y = 450;
  data->plan[0]->node[2]->way[0] = 1;
  load_node_1_1(data);
  return (0);
}
