/*
** change_pos.c for tekadv in /home/blanch_p/rendu/Infographie/gfx_tekadventure
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Mon Apr 11 10:29:23 2016 Alexandre Blanchard
** Last update Sun Apr 17 22:43:44 2016 Voyevoda
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
	  data->plan[0]->calque[i]->x = data->plan[0]->calque[i]->x +
	    data->plan[0]->calque[i]->x_speed;
	  data->plan[0]->calque[i]->y = data->plan[0]->calque[i]->y +
	    data->plan[0]->calque[i]->y_speed / 4;
      
	  if (data->plan[0]->calque[i]->y <=
	      data->plan[0]->calque[i]->y_init - 4)
	    data->plan[0]->calque[i]->y_speed =
	      -data->plan[0]->calque[i]->y_speed;
	  if (data->plan[0]->calque[i]->y >=
	      data->plan[0]->calque[i]->y_init + 3)
	    data->plan[0]->calque[i]->y_speed =
	      -data->plan[0]->calque[i]->y_speed;
	  
	  if (data->plan[0]->calque[i]->x <=
	      data->plan[0]->calque[i]->x_init - 10)
	    data->plan[0]->calque[i]->x_speed =
	      -data->plan[0]->calque[i]->x_speed;
	  if (data->plan[0]->calque[i]->x >=
	      data->plan[0]->calque[i]->x_init + 10)
	    data->plan[0]->calque[i]->x_speed =
	      -data->plan[0]->calque[i]->x_speed;
	}
      i++;
    }

  /* data->plan[0]->calque[5]->x = data->plan[0]->calque[5]->x + */
  /*   data->plan[0]->calque[5]->x_speed; */
  /* data->plan[0]->calque[5]->y = data->plan[0]->calque[5]->y + */
  /*   data->plan[0]->calque[5]->y_speed / 4; */

  /* if (data->plan[0]->calque[5]->y <= 555 - rand() % 10) */
  /*   data->plan[0]->calque[5]->y_speed = -data->plan[0]->calque[5]->y_speed; */
  /* if (data->plan[0]->calque[5]->y >= 565 + rand() % 10) */
  /*   data->plan[0]->calque[5]->y_speed = -data->plan[0]->calque[5]->y_speed; */

  /* if (data->plan[0]->calque[5]->x <= -20 /\* + rand() % 5 *\/) */
  /*   data->plan[0]->calque[5]->x_speed = -data->plan[0]->calque[5]->x_speed; */
  /* if (data->plan[0]->calque[5]->x >= -5 /\* + rand() % 5 *\/) */
  /*   data->plan[0]->calque[5]->x_speed = -data->plan[0]->calque[5]->x_speed; */


}
