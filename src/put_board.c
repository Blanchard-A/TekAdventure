/*
** put_board.c for gfxtekadventure in /home/puilla_e/Semestre2/infographie
**
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
**
** Started on  Sun Apr 17 10:44:41 2016 edouard puillandre
** Last update Sun Apr 17 23:57:21 2016 Voyevoda
*/

#include "adventure.h"

void			draw_square(t_button *button, t_data *data)
{
  t_bunny_position	tmp;
  int			width;
  int			height;

  tmp.x = button->pos.x - 1;
  width = button->pos.x + W_BUTTON;
  height = button->pos.y + H_BUTTON;
  while (++tmp.x < width)
    {
      tmp.y = button->pos.y - 1;
      while (++tmp.y < height)
	if ((tmp.x <= button->pos.x + 10 || tmp.x >= width - 10) ||
	    (tmp.y <= button->pos.y + 10 || tmp.y >= height - 10))
	  tekpixel(data->pix, &tmp, BLACK);
    }

}

void	draw_board(t_data *data)
{
  int	i;

  i = - 1;
  copy_in_pix(data->board->calque, data, 0);
  while (data->board->obj[++i] != NULL)
    if (data->board->obj[i]->name != NULL)
      copy_in_pix(data->board->obj[i]->calque, data, 0);
  draw_square(data->board->button[data->board->sel], data);
}
