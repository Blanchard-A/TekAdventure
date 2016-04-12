/*
** scale.c for tekadv in /home/blanch_p/rendu/Infographie/gfx_tekadventure
**
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
**
** Started on  Thu Apr  7 12:17:28 2016 Alexandre Blanchard
** Last update Tue Apr 12 15:28:44 2016 edouard puillandre
*/

#include "adventure.h"

float			calc_delta(int pos, int tmp)
{
  if (pos > (float) tmp && pos < (float) (tmp + 1))
    return (pos - (float) tmp);
  else if (pos < (float) tmp && pos > (float) (tmp - 1))
    return ((float) tmp - pos);
  return (1);
}

unsigned int		float_to_int(float *tot, float check)
{
  t_color		col;
  int			i;

  i = - 1;
  while (++i < 3)
    if (check != 0)
      col.argb[i] = (char) (tot[i] / check);
    else
      col.argb[i] = (char) tot[i];
  col.argb[i] = 255;
  return (col.full);
}

void			init_data(t_bunny_position	*tmp,
				  float			*tot,
				  float			*check,
				  float			*pos)
{
  tmp->x = (int) pos[0] - 1;
  tot[0] = 0;
  tot[1] = 0;
  tot[2] = 0;
  *check = 0;
}

unsigned int		col_scale(t_bunny_pixelarray	*pix,
				  float			*pos,
				  int			scale)
{
  float			tot[3];
  t_color		col;
  t_bunny_position	tmp;
  float			dx[2];
  float			check;
  int			i;

  init_data(&tmp, tot, &check, pos);
  while (++tmp.x < (int) pos[0] + (int) ((float) 100 / (float) scale))
    {
      tmp.y = (int) pos[1] - 1;
      dx[0] = calc_delta(pos[0], tmp.x);
      while (++tmp.y < (int) pos[1] + (int) ((float) 100 / (float) scale))
	{
	  dx[1] = calc_delta(pos[1], tmp.y);
	  col.full = getpixel(pix, &tmp);
	  i = - 1;
	  check = check + dx[1] * dx[0];
	  while (++i < 3)
	    tot[i] = ((float) col.argb[i] * dx[0] * dx[1]) + tot[i];
	}
    }
  return (float_to_int(tot, check));
}

void			to_pix_scale(t_bunny_pixelarray	*dest,
				     t_bunny_pixelarray	*src,
				     t_bunny_position	*pos,
				     int		scale)
{
  int			width;
  int			height;
  t_bunny_position	drw;
  float			get[2];
  t_bunny_position	tmp;

  width = src->clipable.buffer.width * scale / 100;
  height = src->clipable.buffer.height * scale / 100;
  tmp.x = 0;
  while (++tmp.x < width)
    {
      tmp.y = 0;
      while (++tmp.y < height)
	{
	  drw.x = tmp.x + pos->x;
	  drw.y = tmp.y + pos->y;
	  get[0] = ((float) tmp.x * 100) / (float) scale;
	  get[1] = ((float) tmp.y * 100) / (float) scale;
	  tekpixel(dest, &drw, col_scale(src, get, scale));
	}
    }
}
