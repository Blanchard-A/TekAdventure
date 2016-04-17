/*
** my_init_fct.c for gfx_tekadventure in /home/puilla_e/Semestre2/infographie
**
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
**
** Started on  Tue Mar 29 16:50:59 2016 edouard puillandre
** Last update Sun Apr 17 17:23:00 2016 Alexandre Blanchard
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

int		my_malloc_plan(t_data *data, int nb_calc)
{
  /* int		i; */
  int		j;

  j = 0;
  /* i = 0; */
  data->plan = bunny_malloc(sizeof(t_plan *) * 1);
  /* while (i < 2) */
  /*   { */
  data->plan[0] = bunny_malloc(sizeof(t_plan) * 1);
  data->plan[0]->calque = bunny_malloc(sizeof(t_calque *) * (nb_calc + 1));
    /*   i++; */
    /* } */
  /* data->plan->calque = bunny_malloc(sizeof(t_calque *) * 1); */
  /* i = 0; */
  /* while (i < 2) */
  /*   { */
  j = 0;
  while (j < nb_calc)
    {
      data->plan[0]->calque[j] = bunny_malloc(sizeof(t_calque) * 1);
      j++;
    }
      /* i++; */
    /* } */
  return (0);
}

#include <stdio.h>

t_data		*my_init_data()
{
  t_data	*data;

  set_max_heap_size(50);
  if ((data = bunny_malloc(sizeof(t_data))) == NULL ||
      (my_malloc_plan(data, 8) != 0) ||
      (data->pix = bunny_new_pixelarray(WIN_X, WIN_Y)) == NULL ||
      (data->win = bunny_start(WIN_X, WIN_Y, false, WIN_NAME)) == NULL ||
      (data->pos = bunny_malloc(sizeof(t_bunny_position))) == NULL ||
      (data->board = my_init_board()) == NULL)
    {
      printf("%p\n", data->plan[0]->calque[0]->pix);
      printf("%p\n", data->plan[0]->calque[1]->pix);
      printf("%p\n", data->plan[0]->calque[2]->pix);
      printf("%p\n", data->plan[0]->calque[3]->pix);
      printf("%p\n", data->plan[0]->calque[4]->pix);
      printf("%p\n", data->plan[0]->calque[5]->pix);
      return (NULL);
    }
  data->id_plan = 0;
  if (data->id_plan == 0)
    {
      load_decor_1(data);
      load_node_1(data);
    }
  if (data->id_plan == 1)
    {
      load_decor_2(data);
      load_node_2(data);
    }
  malloc_and_load_perso(data);
  data->player->vec[0] = 0;
  data->player->vec[1] = 0;
  data->player->coef[0] = 0;
  data->player->coef[1] = 0;
  data->loop = 0;
  data->player->chemin = bunny_malloc(sizeof(int) * 11);
  data->player->chemin[0] = -1;
  CUR = 0;
  MOV = 1;
  data->pos->x = PIX_X;
  data->pos->x = PIX_Y;
  data->mouse = (t_bunny_position *) bunny_get_mouse_position();
#ifdef DEBUG
  write(1, "INIT: OK\n", 9);
#endif
  return (data);
}
