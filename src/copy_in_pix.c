
/*
** copy_in_pix.c for tekadv in /home/blanch_p/Infographie/gfx_tekadventure
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Thu Apr  7 17:17:53 2016 Alexandre Blanchard
** Last update Fri Apr 15 14:22:10 2016 Alexandre Blanchard
*/

#include "adventure.h"

#include <stdio.h>

void	tekpixel(t_bunny_pixelarray *pix,
		 t_bunny_position *pos,
		 unsigned int color)
{
  int	position;

  position = (pos->x + ((pos->y) * WIDTH));
  if (position >= 0 && position < (HEIGHT * WIDTH))
    ((unsigned int *)pix->pixels)[position] = color;
}

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

void	copy_in_pix(t_calque *calque, t_data *data)
{
  int	i;
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


void	copy_in_pix_perso(t_calque *calque, t_data *data)
{
  int	i;
  t_bunny_position	pos;
  t_color		*color;

  i = 0;
  color = calque->pix->pixels;
  while (i < calque->pix->clipable.clip_width
	 * calque->pix->clipable.clip_height)
    {
      /* printf("i = %i\n", i); */
      /* printf("width = %i\n", calque->pix->clipable.clip_width); */
      /* printf("height = %i\n", calque->pix->clipable.clip_height); */
      if (i == 90)
	i = i + calque->pix->clipable.clip_width;
      if (compare_to_col(color[i], (t_color)BACK_COLOR) == -1)
	{
	  /* printf("\nPRINT\n"); */
	  /* printf("calc x = %i\n", i % calque->pix->clipable.clip_width); */
	  /* printf("calc y = %i\n", i / calque->pix->clipable.clip_width); */
	  /* printf("width = %i\n", calque->pix->clipable.clip_width); */
	  pos.x = i % calque->pix->clipable.clip_width + calque->x;
	  pos.y = i / calque->pix->clipable.clip_width + calque->y;
	  if (pos.x >= 0 && pos.x <= WIN_X)
	    tekpixel(data->pix, &pos,
		     ((unsigned int *)calque->pix->pixels)[i]);
	}
      i++;
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
      	copy_in_pix_perso(data->player->mov[0]->calque[0], data);
      i++;
    }

}
