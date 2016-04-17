/*
** coef.c for tekadv in /home/blanch_p/rendu/Semestre2/Infographie/gfx_tekadventure
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Sat Apr 16 14:37:00 2016 Alexandre Blanchard
** Last update Sun Apr 17 13:42:15 2016 Alexandre Blanchard
*/

#include "adventure.h"

#include <stdio.h>

void	have_perso(t_data *data)
{
  if (fabs(data->player->coef[1]) > fabs(data->player->coef[0]))
    {
      if (data->player->coef[1] < 0)
	{
	  data->player->cur_mov = 2;
	  
	}
      else
	{
	  data->player->cur_mov = 0;
	}
      
    }
  else
    {
      if (data->player->coef[0] > 0)
	{
	  data->player->cur_mov = 3;

	}
      else
	{
	  data->player->cur_mov = 1;
	}
    }
  
}

void	pos_perso(t_data *data)
{
  int	i;

  i = 0;
  while (i < 4)
    {
      data->player->mov[i]->calque[0]->x = data->player->x;
      data->player->mov[i]->calque[0]->y = data->player->y;
      
      data->player->mov[i]->calque[1]->x = data->player->x;
      data->player->mov[i]->calque[1]->y = data->player->y;
      i++;
    }
}

void	move_perso(t_data *data)
{
  /* if (data->player->coef[0] != 0 || data->player->coef[1] != 0) */
  data->loop++;
  if (data->loop == 12)
    data->loop = 0;
  data->player->vec[0] = data->player->vec[0] + data->player->coef[0];
  data->player->vec[1] = data->player->vec[1] + data->player->coef[1];

  data->player->x = data->player->mov[CUR]->calque[MOV]->x
    + (int) data->player->vec[0];
  data->player->vec[0] = data->player->vec[0] - (int)data->player->vec[0];
  data->player->y = data->player->mov[CUR]->calque[MOV]->y
    + (int) data->player->vec[1];
  data->player->vec[1] = data->player->vec[1] - (int)data->player->vec[1];

  if ((data->player->x >=
       data->plan[data->id_plan]->node[data->player->next_node]->pos.x &&
       data->player->coef[0] > 0) ||
      (data->player->x <=
       data->plan[data->id_plan]->node[data->player->next_node]->pos.x &&
       data->player->coef[0] < 0) ||
       (data->player->y >=
  	data->plan[data->id_plan]->node[data->player->next_node]->pos.y &&
       data->player->coef[1] > 0) ||
      (data->player->y <=
       data->plan[data->id_plan]->node[data->player->next_node]->pos.y &&
       data->player->coef[1] < 0))
    {
      data->player->cur_node = data->player->next_node;
      data->player->vec[0] = 0;
      data->player->coef[0] = 0;
      data->player->coef[1] = 0;
      data->player->vec[1] = 0;
    }

  pos_perso(data);
  /* data->player->mov[CUR]->calque[MOV]->x = data->player->x; */
  /* data->player->mov[CUR]->calque[MOV]->y = data->player->y; */
}

void	calc_coef(float x_perso, float y_perso, t_bunny_position *dest,
		  t_data *data)
{
  data->player->coef[0] = (dest->x - x_perso) /
    sqrt(pow(dest->x - x_perso, 2) + pow(dest->y - y_perso, 2)) * 10;
  printf("coef x = %f\n", data->player->coef[0]);
  data->player->coef[1] = (dest->y - y_perso) /
    sqrt(pow(dest->x - x_perso, 2) + pow(dest->y - y_perso, 2)) * 10;
  printf("coef y = %f\n", data->player->coef[1]);
  data->player->vec[0] = 0;
  printf("vec x = %f\n", data->player->vec[0]);
  data->player->vec[1] = 0;
  printf("vec y = %f\n", data->player->vec[1]);
  have_perso(data);
  data->player->mov[CUR]->cur_pos = 0;

}
