/*
** check_click.c for tekadv in /home/blanch_p/rendu/Semestre2/Infographie/gfx_tekadventure
**
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
**
** Started on  Fri Apr 15 16:31:12 2016 Alexandre Blanchard
** Last update Sun Apr 17 15:56:42 2016 Alexandre Blanchard
*/

#include "adventure.h"
#include <stdio.h>

int	check_click_pnj(t_data *data)
{
  int	i;
  int	j;

  i =  - 1;
  j = data->id_plan;
  while (data->plan[j]->pnj[++i] != NULL)
    if (data->mouse->x >= data->plan[j]->pnj[i]->calque->x &&
	data->mouse->x <= data->plan[j]->pnj[i]->calque->x +
	data->plan[j]->pnj[i]->calque->pix->clipable.clip_width &&
	data->mouse->y >= data->plan[j]->pnj[i]->calque->y &&
	data->mouse->y <= data->plan[j]->pnj[i]->calque->y +
	data->plan[j]->pnj[i]->calque->pix->clipable.clip_height)
      return (i);
  return (- 1);
}

int	check_click_obj(t_data *data)
{
  int	i;
  int	j;

  i =  - 1;
  j = data->id_plan;
  while (data->plan[j]->obj[++i] != NULL)
    if (data->mouse->x >= data->plan[j]->obj[i]->calque->x &&
	data->mouse->x <= data->plan[j]->obj[i]->calque->x +
	data->plan[j]->obj[i]->calque->pix->clipable.clip_width &&
	data->mouse->y >= data->plan[j]->obj[i]->calque->y &&
	data->mouse->y <= data->plan[j]->obj[i]->calque->y +
	data->plan[j]->obj[i]->calque->pix->clipable.clip_height)
      return (i);
  return (- 1);
}

int	check_click_button(t_data *data)
{
  int	i;

  i =  - 1;
  while (data->board->button[++i] != NULL)
    if (data->mouse->x >= data->board->button[i]->pos.x &&
	data->mouse->x <= data->board->button[i]->pos.x + W_BUTTON &&
	data->mouse->y >= data->board->button[i]->pos.y &&
	data->mouse->y <= data->board->button[i]->pos.y + H_BUTTON)
      return (i);
  return (- 1);
}

int	check_click_node(t_data *data)
{
  int	i;
  int	j;
  int	scale;

  i = -1;
  j = 0;
  while (data->plan[j]->node[++i] != NULL)
    {
      scale = data->plan[j]->node[i]->scale / 2;
      printf("i = %i\n", i);
      if (data->mouse->x >= data->plan[j]->node[i]->pos.x - scale &&
	  data->mouse->x <= data->plan[j]->node[i]->pos.x + scale &&
	  data->mouse->y >= data->plan[j]->node[i]->pos.y - scale &&
	  data->mouse->y <= data->plan[j]->node[i]->pos.y + scale)
	return (i);
    }
  return (-1);
}

int	check_click(t_data *data)
{
  int	i;

  i = 0;
  while (data->plan[0]->node[i] != NULL)
    {
      if (data->mouse->x >= data->plan[0]->node[i]->pos.x - 30
	  && data->mouse->x <= data->plan[0]->node[i]->pos.x + 30 &&
	  data->mouse->y >= data->plan[0]->node[i]->pos.y - 30
	  && data->mouse->y <= data->plan[0]->node[i]->pos.y + 30)
	{
	  return (i);
	}
      i++;
    }
  return (-1);
  /* if ((data->mouse->x > 42 && data->mouse->x < 207) && */
  /*     (data->mouse->y > 733 && data->mouse->y < 807)) */
  /*   { */
  /*     printf("UTILISER\n"); */
  /*   } */
}

int	check_click_bis(t_data *data)
{
  int	check;

  if ((check = check_click_button(data)) != - 1)
    data->board->sel = check;
  else
    {
      check = data->board->sel;
      data->board->button[check]->fct(data);
    }
  return (0);
}
