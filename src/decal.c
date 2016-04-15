/*
** decal.c for tekadv in /home/blanch_p/Semestre2/Infographie/gfx_tekadventure
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Tue Apr 12 11:31:00 2016 Alexandre Blanchard
** Last update Tue Apr 12 14:54:51 2016 Alexandre Blanchard
*/

#include "adventure.h"

#include <stdio.h>

void	on_the_bord(t_data *data, const t_bunny_position *pos)
{
  if (pos->x < 22)
    {
      /* data->plan[0]->calque[2]->x = data->plan[0]->calque[2]->x_init + ((22 - pos->x) / 4); */
      data->plan[0]->calque[3]->x = data->plan[0]->calque[3]->x_init + (22 - pos->x);
      data->plan[0]->calque[4]->x = data->plan[0]->calque[4]->x_init + (22 - pos->x);
      data->plan[0]->calque[5]->x = data->plan[0]->calque[5]->x_init + (22 - pos->x);
      /* data->plan[0]->calque[6]->x = data->plan[0]->calque[6]->x_init + (22 - pos->x); */
      
    }

  else if (pos->x > data->WIDTH - 22)
    {
      /* data->plan[0]->calque[2]->x = data->plan[0]->calque[2]->x_init + ((22 - pos->x) / 4); */
      data->plan[0]->calque[3]->x = data->plan[0]->calque[3]->x_init + ((data->WIDTH - 22) - pos->x);
      data->plan[0]->calque[4]->x = data->plan[0]->calque[4]->x_init + ((data->WIDTH - 22) - pos->x);
      data->plan[0]->calque[5]->x = data->plan[0]->calque[5]->x_init + ((data->WIDTH - 22) - pos->x);
      /* data->plan[0]->calque[6]->x = data->plan[0]->calque[6]->x_init + (22 - pos->x); */
      
    }

  else
    {
      /* data->plan[0]->calque[2]->x = data->plan[0]->calque[2]->x_init; */
      data->plan[0]->calque[3]->x = data->plan[0]->calque[3]->x_init;
      data->plan[0]->calque[4]->x = data->plan[0]->calque[4]->x_init;
      data->plan[0]->calque[5]->x = data->plan[0]->calque[5]->x_init;
      /* data->plan[0]->calque[6]->x = data->plan[0]->calque[6]->x_init; */
    }

  
}

void	have_pos(t_data *data)
{
  /* const t_bunny_position	*pos; */
  /* pos = bunny_get_mouse_position(); */
  on_the_bord(data, data->mouse);
  
}
