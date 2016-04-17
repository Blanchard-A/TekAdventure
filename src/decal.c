/*
** decal.c for tekadv in /home/blanch_p/Semestre2/Infographie/gfx_tekadventure
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Tue Apr 12 11:31:00 2016 Alexandre Blanchard
** Last update Sun Apr 17 22:44:01 2016 Voyevoda
*/

#include "adventure.h"

void	change_perso_bord_neg(t_data *data, const t_bunny_position *pos)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (i < 4)
    {
      j = 0;
      while (j < 2)
	{
	  data->player->mov[i]->calque[j]->x =
	    data->player->mov[i]->calque[j]->x_init + (22 - pos->x);
	  j++;
	}
      i++;
    }
}

void	on_the_bord(t_data *data, const t_bunny_position *pos)
{
  if (pos->x < 22)
    {
      /* change_perso_bord_neg(data, pos); */
      PLAN->calque[3]->x = PLAN->calque[3]->x_init + (22 - pos->x);
      PLAN->calque[4]->x = PLAN->calque[4]->x_init + (22 - pos->x);
      PLAN->calque[5]->x = PLAN->calque[5]->x_init + (22 - pos->x);
    }
  else if (pos->x > data->WIDTH - 22)
    {
      CAL[3]->x = CAL[3]->x_init +((data->WIDTH - 22) - pos->x);
      CAL[4]->x = CAL[4]->x_init + ((data->WIDTH - 22) - pos->x);
      CAL[5]->x = CAL[5]->x_init + ((data->WIDTH - 22) - pos->x);
    }
  else
    {
      data->plan[0]->calque[3]->x = data->plan[0]->calque[3]->x_init;
      data->plan[0]->calque[4]->x = data->plan[0]->calque[4]->x_init;
      data->plan[0]->calque[5]->x = data->plan[0]->calque[5]->x_init;
    }
}

void	have_pos(t_data *data)
{
  /* const t_bunny_position	*pos; */
  /* pos = bunny_get_mouse_position(); */
  on_the_bord(data, data->mouse);
  
}
