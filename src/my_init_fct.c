/*
** my_init_fct.c for gfx_tekadventure in /home/puilla_e/Semestre2/infographie
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Tue Mar 29 16:50:59 2016 edouard puillandre
** Last update Tue Mar 29 16:52:27 2016 edouard puillandre
*/

#include "adventure.h"

void		my_init_pix(t_bunny_pixelarray	*pix)
{
  t_color	*color;
  int		i;

  color = pix->pixels;
  i = - 1;
  while (++i < pix->clipable.buffer.width * pix->clipable.buffer.height)
    color[i].full = INIT_COLOR;
}

t_data		*my_init_data()
{
  t_data	*data;

  if ((data = bunny_malloc(sizeof(t_data))) == NULL ||
      (data->win = bunny_start(WIN_X, WIN_Y, false, WIN_NAME)) == NULL ||
      (data->pos = bunny_malloc(sizeof(t_bunny_position))) == NULL ||
      (data->pix = bunny_new_pixelarray(WIN_X, WIN_Y)) == NULL)
    return (NULL);
  data->pos->x = PIX_X;
  data->pos->x = PIX_Y;
  data->mouse = (t_bunny_position *) bunny_get_mouse_position();
  my_init_pix(data->pix);
#ifdef DEBUG
  write(1, "INIT: OK\n", 9);
#endif
  return (data);
}
