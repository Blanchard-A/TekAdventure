
/*
** copy_in_pix.c for tekadv in /home/blanch_p/Infographie/gfx_tekadventure
**
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
**
** Started on  Thu Apr  7 17:17:53 2016 Alexandre Blanchard
** Last update Fri Apr 15 17:21:48 2016 edouard puillandre
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
  int			i;
  t_bunny_position	pos;
  t_color		*color;

  i = 0;
  color = calque->pix->pixels;
  while (i < calque->pix->clipable.clip_width
	 * calque->pix->clipable.clip_height)
    {
      if (compare_to_col(color[i], (t_color)BACK_COLOR) == -1)
	{
	  pos.x = i % calque->pix->clipable.clip_width + calque->x;
	  pos.y = i / calque->pix->clipable.clip_width + calque->y;
	  if (pos.x >= 0 && pos.x <= WIN_X)
	    tekpixel(data->pix, &pos,
		     ((unsigned int *)calque->pix->pixels)[i]);
	}
      i++;
    }
}

void			copy_in_pix_bis(t_calque *calque, t_data *data)
{
  t_bunny_position	tmp;
  t_bunny_position	get;
  t_bunny_position	put;
  t_color		col;

  tmp.x = - 1;
  while (++tmp.x < calque->pix->clipable.clip_width)
    {
      tmp.y = - 1;
      while (++tmp.y < calque->pix->clipable.clip_height)
	{
	  get.x = tmp.x + calque->pix->clipable.clip_x_position;
	  get.y = tmp.y + calque->pix->clipable.clip_y_position;
	  put.x = tmp.x + (int) calque->x;
	  put.y = tmp.y + (int) calque->y;
	  col.full = getpixel(calque->pix, &get);
	  if (compare_to_col(col, (t_color)BACK_COLOR) == - 1)
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
      copy_in_pix(data->plan[0]->calque[i], data);
      if (i == 5)
      	copy_in_pix_bis(data->player->mov[0]->calque[0], data);
      i++;
    }

}
