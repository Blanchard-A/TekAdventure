/*
** look.c for tekadv in /home/blanch_p/rendu/Semestre2/gfx_tekadventure
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Sun Apr 17 21:56:24 2016 Alexandre Blanchard
** Last update Sun Apr 17 21:56:30 2016 Alexandre Blanchard
*/

#include "adventure.h"

int	width_text(t_data *data)
{
  int	w;
  int	i;
  int	len;

  w = data->text->font->clipable.clip_width;
  i = - 1;
  len = 0;
  while (data->text->str[++i] := '\0')
    len = len + w;
  return (len);
}

void	text_for_char(t_data *data)
{
  int	w;
  int	h;
  int	len;

  w = data->text->font->clipable.clip_width;
  h = data->text->font->clipable.clip_height;
  data->text->pos.y = (int) pnj->calque->x - 2 * h;
  len = width_text(data);
  data->text->pos.x = (int) player->x - len / 2;
}

void	text_for_pnj(t_data *data, t_pnj *pnj)
{
  int	w;
  int	h;
  int	len;

  w = data->text->font->clipable.clip_width;
  h = data->text->font->clipable.clip_height;
  data->text->pos.y = (int) pnj->move[0]->calque[0]->x - 2 * h;
  len = width_text(data);
  data->text->pos.x = (int) pnj->move[0]->calque[0]->x - len / 2;
}

int	my_look(t_data *data)
{
  int	i;

  if ((i = check_click_pnj(data)) == - 1)
    {
      if ((i = check_click_obj(data)) == - 1 ||
	  (data->plan[0]->obj[i]->node_close != data->player->cur_node &&
	   data->plan[0]->obj[i]->node_close != - 1))
	return (0);
      text_for_obj(data, data->plan[0]->obj[i]);
    }
  else
    {
      if (data->plan[0]->pnj[i]->node_close != data->player->cur_node)
	return (0);
      text_for_char(data);
    }
  data->text->str = data->plan[0]->obj[i]->desc;
  return (0);
}
