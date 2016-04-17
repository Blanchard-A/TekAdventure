/*
** tektext.c for gfx_tekadventure in /home/puilla_e/Semestre2/infographie/
**
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
**
** Started on  Sun Apr 17 18:28:08 2016 edouard puillandre
** Last update Sun Apr 17 23:24:53 2016 edouard puillandre
*/

#include "adventure.h"

void	tekletter(t_bunny_pixelarray	*pix,
		  char			c)
{
  int	width;
  int	height;
  int	w;
  int	h;

  width = pix->clipable.buffer.width;
  height = pix->clipable.buffer.height;
  w =  width / COL_FONT;
  h = height / ROW_FONT;
  if (c < 0)
    return ;
  pix->clipable.clip_x_position = (c * w) % width - 2;
  pix->clipable.clip_y_position = (c * w) / width * h;
  pix->clipable.clip_width = w;
  pix->clipable.clip_height = h;
}

int	check_plot(t_bunny_pixelarray		*out,
		   t_bunny_pixelarray		*fontpng,
		   t_bunny_position		*pos,
		   t_bunny_position		*pos_c)
{
  int	width;
  int	height;

  width = fontpng->clipable.buffer.width / COL_FONT;
  height = fontpng->clipable.buffer.height / ROW_FONT;
  if (pos_c->x + width > out->clipable.buffer.width)
    {
      pos_c->x = pos->x;
      if ((pos_c->y = pos_c->y + height) > out->clipable.buffer.height)
	return (- 1);
    }
  if (pos_c->y + height > out->clipable.buffer.height)
    return (- 1);
  return (0);
}

void			cpyletter(t_bunny_pixelarray	*out,
				  t_bunny_pixelarray	*fontpng,
				  t_bunny_position	*pos,
				  char			c)
{
  int			beg_outy;
  int			begy;
  int			begx;
  t_bunny_position	pos_c;

  tekletter(fontpng, c);
  pos_c.x = fontpng->clipable.clip_x_position;
  beg_outy = pos->y;
  begx = pos_c.x;
  begy = fontpng->clipable.clip_y_position;
  while (++pos_c.x < fontpng->clipable.clip_width + begx)
    {
      pos_c.y = begy - 1;
      while (++pos_c.y < fontpng->clipable.clip_height + begy)
	{
	  if (getpixel(fontpng, &pos_c) == (unsigned int) WHITE)
	    tekpixel(out, pos, WHITE);
	  pos->y = pos->y + 1;
	}
      pos->x = pos->x + 1;
      pos->y = beg_outy;
    }
}

void			tektext(t_bunny_pixelarray	*out,
				t_text			*text)
{
  t_bunny_position	pos_c;
  int			i;
  int			height;

  if (text->str == NULL)
    return ;
  i = - 1;
  pos_c = text->pos;
  height = text->font->clipable.buffer.height / ROW_FONT;
  while (text->str[++i] != '\0')
    if (text->str[i] >= 32)
      {
	if (check_plot(out, text->font, &text->pos, &pos_c) == - 1)
	  return ;
	cpyletter(out, text->font, &pos_c, text->str[i]);
      }
    else if (text->str[i] == '\n' || text->str[i] == '\r')
      {
	pos_c.x = text->pos.x;
	if ((pos_c.y = pos_c.y + height) > out->clipable.buffer.height)
	  return ;
      }
}

t_text		*init_text()
{
  t_text	*text;

  if ((text = bunny_malloc(sizeof(*text))) == NULL ||
      (text->font = load_bitmap(FONT_BMP)) == NULL)
    return (NULL);
  text->str = NULL;
  return (text);
}
