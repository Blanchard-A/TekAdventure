/*
** tekpixel.c for fdf1 in /home/sauvau_m/rendu/gfx_fdf1/src
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Wed Nov 18 19:39:56 2015 Mathieu Sauvau
** Last update Sun Apr 17 22:45:12 2016 Voyevoda
*/

#include "lapin.h"

void		tekpixel(t_bunny_pixelarray *pix_ar,
			 t_bunny_position *pos,
			 unsigned int color)
{
  t_color	*col;
  int		new_pos;

  col = pix_ar->pixels;
  new_pos = pix_ar->clipable.buffer.width * pos->y  + pos->x;
  if (new_pos >= 0 &&
      new_pos < pix_ar->clipable.buffer.width * pix_ar->clipable.buffer.height)
    col[new_pos].full = color;
}

unsigned int	getpixel(t_bunny_pixelarray	*pix_ar,
			 t_bunny_position	*pos)
{
  t_color	*col;
  int		new_pos;

  col = pix_ar->pixels;
  new_pos = pix_ar->clipable.buffer.width * pos->y  + pos->x;
  if (new_pos >= 0 &&
      new_pos < pix_ar->clipable.buffer.width * pix_ar->clipable.buffer.height)
    return (col[new_pos].full);
  return (0);
}
