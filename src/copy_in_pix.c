
/*
** copy_in_pix.c for tekadv in /home/blanch_p/Infographie/gfx_tekadventure
**
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
**
** Started on  Thu Apr  7 17:17:53 2016 Alexandre Blanchard
** Last update Sun Apr 17 12:01:44 2016 Alexandre Blanchard
*/

#include "adventure.h"

#include <stdio.h>

/* void	tekpixel(t_bunny_pixelarray *pix, */
/* 		 t_bunny_position *pos, */
/* 		 unsigned int color) */
/* { */
/*   int	position; */

/*   position = (pos->x + ((pos->y) * WIDTH)); */
/*   if (position >= 0 && position < (HEIGHT * WIDTH)) */
/*     ((unsigned int *)pix->pixels)[position] = color; */
/* } */

int	compare_to_col(t_color color, t_color back_color)
{
  int	i;

  i = 0;
  while (i <= 3)
    {
      if (color.argb[i] <= back_color.argb[i] - 25 ||
	  color.argb[i] >= back_color.argb[i] + 25)
	return (-1);
      i++;
    }
  return (0);
}

void			copy_in_pix(t_calque *calque, t_data *data)
{
  t_bunny_position	tmp;
  t_bunny_position	get;
  t_bunny_position	put;
  t_color		col;

  tmp.y = - 1;
  if (calque->scale < 100)
    to_pix_scale(data, calque);
  else
    while (++tmp.y < calque->pix->clipable.clip_height)
      {
	tmp.x = - 1;
	while (++tmp.x < calque->pix->clipable.clip_width)
	  {
	    get.x = tmp.x + calque->pix->clipable.clip_x_position;
	    get.y = tmp.y + calque->pix->clipable.clip_y_position;
	    put.x = tmp.x + (int) calque->x;
	    put.y = tmp.y + (int) calque->y;
	    col.full = getpixel(calque->pix, &get);
	    if (compare_to_col(col, (t_color)BACK_COLOR) == - 1)
	      if (put.x >= 0 && put.x <= WIN_X)
		tekpixel(data->pix, &put, col.full);
	  }
      }
}

void	envoi_to_copy(t_data *data)
{
  int	i;

  i = 0;
  /* while (data->plan[data->id_plan]->calque[i] != NULL) */
  /*   { */
  /*     copy_in_pix(data->plan[data->id_plan]->calque[i], data); */
  /*     i++; */
  /*   } */
  while (data->plan[0]->calque[i] != NULL)
    {
      data->plan[0]->calque[i]->scale = 100;
      copy_in_pix(data->plan[0]->calque[i], data);
      draw_board(data);
      data->player->mov[CUR]->calque[MOV]->scale = 25;
      /* printf("%d\n", i); */
      if (i == 4)
	copy_in_pix(data->player->mov[CUR]->calque[MOV], data);
      i++;
    }

}
