/*
** coef.c for tekadv in /home/blanch_p/Semestre2/Infographie/gfx_tekadventure
**
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
**
** Started on  Sat Apr 16 14:37:00 2016 Alexandre Blanchard
** Last update Fri Apr 22 20:21:23 2016 Alexandre Blanchard
*/

#include "adventure.h"

void	have_perso(t_data *data)
{
  if (fabs(data->player->coef[1]) > fabs(data->player->coef[0]))
    {
      if (data->player->coef[1] < 0)
	data->player->cur_mov = 2;
      else
	data->player->cur_mov = 0;
    }
  else
    {
      if (data->player->coef[0] > 0)
	data->player->cur_mov = 3;
      else
	data->player->cur_mov = 1;
    }
}

void		pos_perso(t_data *data)
{
  int		i;

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
  data->loop++;
  if (data->loop == 12)
    data->loop = 0;
  PLAYER->vec[0] = PLAYER->vec[0] + PLAYER->coef[0];
  PLAYER->vec[1] = PLAYER->vec[1] + PLAYER->coef[1];
  PLAYER->x = PLAYER->mov[CUR]->calque[MOV]->x + (int)PLAYER->vec[0];
  PLAYER->vec[0] = PLAYER->vec[0] - (int)PLAYER->vec[0];
  PLAYER->y = PLAYER->mov[CUR]->calque[MOV]->y + (int) PLAYER->vec[1];
  PLAYER->vec[1] = PLAYER->vec[1] - (int)PLAYER->vec[1];
  if ((PLAYER->x >=
       data->plan[0]->node[PLAYER->next_node]->pos.x && PLAYER->coef[0] > 0) ||
      (PLAYER->x <=
       data->plan[0]->node[PLAYER->next_node]->pos.x && PLAYER->coef[0] < 0) ||
      (PLAYER->y >=
       data->plan[0]->node[PLAYER->next_node]->pos.y && PLAYER->coef[1] > 0) ||
      (PLAYER->y <=
       data->plan[0]->node[PLAYER->next_node]->pos.y && PLAYER->coef[1] < 0))
    {
      PLAYER->cur_node = PLAYER->next_node;
      PLAYER->vec[0] = 0;
      PLAYER->coef[0] = 0;
      PLAYER->coef[1] = 0;
      PLAYER->vec[1] = 0;
    }
  pos_perso(data);
}

void	calc_coef(float x_perso, float y_perso, t_bunny_position *dest,
		  t_data *data)
{
  data->player->coef[0] = (dest->x - x_perso) /
    sqrt(pow(dest->x - x_perso, 2) + pow(dest->y - y_perso, 2)) * 10;
  data->player->coef[1] = (dest->y - y_perso) /
    sqrt(pow(dest->x - x_perso, 2) + pow(dest->y - y_perso, 2)) * 10;
  data->player->vec[0] = 0;
  data->player->vec[1] = 0;
  have_perso(data);
  data->player->mov[CUR]->cur_pos = 0;
}
