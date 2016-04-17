/*
** check_click.c for tekadv in /home/blanch_p/rendu/Semestre2/Infographie/gfx_tekadventure
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Fri Apr 15 16:31:12 2016 Alexandre Blanchard
** Last update Sun Apr 17 12:15:33 2016 Alexandre Blanchard
*/

#include "adventure.h"
#include <stdio.h>

void	print_square(int x_min, int x_max, int y_min, int y_max, t_data *data)
{
  t_bunny_position	pos;
  /* int			i; */

  pos.x = x_min;
  pos.y = y_min;
  while (pos.x < x_max)
    {
      tekpixel(data->pix, &pos, RED);
      pos.y++;
      tekpixel(data->pix, &pos, RED);
      pos.y--;
      pos.x++;
    }
  (void)y_min;
  (void)y_max;
}

int	check_click(t_data *data)
{
  int	i;

  i = 0;
  while (data->plan[0]->node[i] != NULL)
    {
      if (data->mouse->x >= data->plan[0]->node[i]->pos.x - 30
	  && data->mouse->x <= data->plan[0]->node[i]->pos.x + 30 &&
	  data->mouse->y >= data->plan[0]->node[i]->pos.y - 30
	  && data->mouse->y <= data->plan[0]->node[i]->pos.y + 30)
	{
	  return (i);
	}
      i++;
    }
  return (-1);
  /* if ((data->mouse->x > 42 && data->mouse->x < 207) && */
  /*     (data->mouse->y > 733 && data->mouse->y < 807)) */
  /*   { */
  /*     printf("UTILISER\n"); */
  /*   } */
  
  
  
}
