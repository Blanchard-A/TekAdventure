/*
** put_line.c for gfx_tekpaint in /home/puilla_e/Infographie/gfx_tekpaint
**
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
**
** Started on  Tue Jan 26 09:53:14 2016 edouard puillandre
** Last update Tue Jan 26 20:13:11 2016 beche_f
*/

#include <lapin.h>
#include "my.h"

void	my_put_form(t_bunny_position	*pos,
		    t_data		*data)
{
  if (data->form == UI_CIRCLE)
    tekdisk(data->mask_slct, pos, data->color, data->size);
  else if (data->form == UI_SQUARE)
    teksquare(data->mask_slct, pos, data->color, data->size);
}

void			tekline_to_y(t_bunny_pixelarray	*pix,
				     t_bunny_position	*pos,
				     t_data		*data,
				     int		sgn)
{
  int			a;
  int			b;
  t_bunny_position	pos_c;
  (void) *pix;
  a = (pos[1].y - pos[0].y);
  b = pos[0].x * pos[1].y - pos[1].x * pos[0].y;
  pos_c.y = pos[0].y;
  while (pos_c.y != pos[1].y + sgn)
    {
      pos_c.x = (pos_c.y * (pos[1].x - pos[0].x) + b) / a;
      my_put_form(&pos_c, data);
      pos_c.y = pos_c.y + sgn;
    }
}

void			tekline_to_x(t_bunny_pixelarray	*pix,
				     t_bunny_position	*pos,
				     t_data		*data,
				     int		sgn)
{
  int			a;
  int			b;
  t_bunny_position	pos_c;

  (void) *pix;
  a = (pos[1].x - pos[0].x);
  b = pos[0].y * pos[1].x - pos[1].y * pos[0].x;
  pos_c.x = pos[0].x;
  while (pos_c.x != pos[1].x + sgn)
    {
      pos_c.y = (pos_c.x * (pos[1].y - pos[0].y) + b) / a;
      my_put_form(&pos_c, data);
      pos_c.x = pos_c.x + sgn;
    }
}

void	tekline(t_data	*data)
{
  int	sgn_x;
  int	sgn_y;

  if (data->click->x == data->mouse->x &&
      data->click->y == data->mouse->y)
    my_put_form(data->click, data);
  else
    {
      if (data->mouse[0].x < data->mouse[1].x)
	sgn_x = + 1;
      else
	sgn_x = - 1;
      if (data->mouse[0].y < data->mouse[1].y)
	sgn_y = + 1;
      else
	sgn_y = - 1;
      if ((data->mouse[1].x - data->mouse[0].x) *
	  sgn_x < (data->mouse[1].y - data->mouse[0].y) *
	  sgn_y)
	tekline_to_y(data->mask_slct, data->mouse, data, sgn_y);
      else
	tekline_to_x(data->mask_slct, data->mouse, data, sgn_x);
    }
}
