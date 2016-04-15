/*
** check_click.c for tekadv in /home/blanch_p/rendu/Semestre2/Infographie/gfx_tekadventure
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Fri Apr 15 16:31:12 2016 Alexandre Blanchard
** Last update Fri Apr 15 17:21:36 2016 Alexandre Blanchard
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

void	check_click(t_data *data)
{
  if ((data->mouse->x > 42 && data->mouse->x < 207) &&
      (data->mouse->y > 733 && data->mouse->y < 807))
    {
      printf("UTILISER\n");
    }
  
  
  
}
