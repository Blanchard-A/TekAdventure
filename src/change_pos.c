/*
** change_pos.c for tekadv in /home/blanch_p/rendu/Infographie/gfx_tekadventure
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Mon Apr 11 10:29:23 2016 Alexandre Blanchard
** Last update Sun Apr 17 22:14:24 2016 Alexandre Blanchard
*/

#include "adventure.h"

void	change_pos_nuages(t_data *data)
{
  if (data->plan[0]->calque[1]->x == -1000)
    data->plan[0]->calque[1]->x = 1000;
  data->plan[0]->calque[1]->x = data->plan[0]->calque[1]->x +
    data->plan[0]->calque[1]->x_speed;
  data->plan[0]->calque[1]->y = data->plan[0]->calque[1]->y +
    data->plan[0]->calque[1]->y_speed;
}

void	change_pos(t_data *data)
{
  int	i;

  i = 0;
  while (data->plan[0]->calque[i] != NULL)
    {
      if (i != 1)
	{
	  PLAN->calque[i]->x = PLAN->calque[i]->x + PLAN->calque[i]->x_speed;
	  PLAN->calque[i]->y = PLAN->calque[i]->y +
	    PLAN->calque[i]->y_speed / 4;
	  if (PLAN->calque[i]->y <=PLAN->calque[i]->y_init - 4)
	    PLAN->calque[i]->y_speed = -PLAN->calque[i]->y_speed;
	  if (PLAN->calque[i]->y >= PLAN->calque[i]->y_init + 3)
	    PLAN->calque[i]->y_speed = -PLAN->calque[i]->y_speed;
	  if (PLAN->calque[i]->x <= PLAN->calque[i]->x_init - 10)
	    PLAN->calque[i]->x_speed = -PLAN->calque[i]->x_speed;
	  if (PLAN->calque[i]->x >= PLAN->calque[i]->x_init + 10)
	    PLAN->calque[i]->x_speed = -PLAN->calque[i]->x_speed;
	}
      i++;
    }
}
