/*
** load.c for tekadv in /home/blanch_p/rendu/Semestre2/Infographie/gfx_tekadventure
**
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
**
** Started on  Fri Apr 15 10:26:38 2016 Alexandre Blanchard
** Last update Sun Apr 17 21:09:49 2016 edouard puillandre
** Last update Sun Apr 17 21:00:09 2016 Alexandre Blanchard
*/

#include "adventure.h"

#include <stdio.h>

t_data	*malloc_and_load_perso(t_data *data)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  if ((data->player = bunny_malloc(sizeof(t_char) * 1)) == NULL ||
      (data->player->mov = bunny_malloc(sizeof(t_move *) * 4)) == NULL)
    return (NULL);
  data->player->cur_node = 1;
  data->player->dest_node = 1;
  data->player->x = 193;
  data->player->y = 409;
  /* data->player->mov[0] = bunny_malloc(sizeof(t_move) * 4); */
  while (i < 4)
    {
      if ((MOVI = bunny_malloc(sizeof(t_move) * 1)) == NULL ||
	  (MOVI->calque = bunny_malloc(sizeof(t_calque *) * 2)) == NULL ||
	  (MOVI->calque[0] = bunny_malloc(sizeof(t_calque ) * 1)) == NULL ||
	  (MOVI->calque[1] = bunny_malloc(sizeof(t_calque ) * 1)) == NULL)
	return (NULL);
      i++;
    }
  data->player->mov[0]->calque[0]->pix = load_bitmap("walk_face_2.bmp");
  data->player->mov[1]->calque[0]->pix = load_bitmap("walk_left_2.bmp");
  data->player->mov[2]->calque[0]->pix = load_bitmap("walk_back_2.bmp");
  data->player->mov[3]->calque[0]->pix = load_bitmap("walk_right_2.bmp");
  data->player->mov[0]->calque[1]->pix = load_bitmap("stand_face.bmp");
  data->player->mov[1]->calque[1]->pix = load_bitmap("stand_left.bmp");
  data->player->mov[2]->calque[1]->pix = load_bitmap("stand_back.bmp");
  data->player->mov[3]->calque[1]->pix = load_bitmap("stand_right.bmp");
  i = 0;
  while (i < 4)
    {
      j = 0;
      change_clipable(data->player->mov[i]->calque[0]->pix, 12);
      while (j < 2)
	{
	  data->player->mov[i]->calque[j]->x = 193;
	  data->player->mov[i]->calque[j]->x_init = 193;
	  data->player->mov[i]->calque[j]->y = 409;
	  data->player->mov[i]->calque[j]->y_init = 409;

	  /* data->player->mov[i]->calque[j]->x = 193 - */
	  /*   ((data->player->mov[i]->calque[j]->WIDTH / 2) * */
	  /*    data->plan[0]->node[1]->scale) / 100; */
	  /* data->player->mov[i]->calque[j]->x_init = 193 - */
	  /*   ((data->player->mov[i]->calque[j]->WIDTH / 2) */
	  /*    * data->plan[0]->node[1]->scale) / 100; */
	  data->player->mov[i]->calque[j]->x_speed = 0;
	  /* data->player->mov[i]->calque[j]->y = 409 - (data->player->mov[i]->calque[j]->HEIGHT * data->plan[0]->node[1]->scale / 100); */
	  /* data->player->mov[i]->calque[j]->y_init = 409; */
	  data->player->mov[i]->calque[j]->y_speed = 0;
	  j++;
	}
      i++;
    }
  return (data);
}

t_data	*load_decor_1(t_data *data)
{
  my_malloc_plan(data, 7);
  if ((PLAN->pnj = bunny_malloc(sizeof(t_pnj *) * 2)) == NULL ||
      (PLAN->pnj[0] = bunny_malloc(sizeof(t_pnj) * 1)) == NULL ||
      (PLAN->pnj[0]->calque = bunny_malloc(sizeof(t_calque) * 1)) == NULL ||
      (PLAN->pnj[0]->dial = bunny_malloc(sizeof(char *) * 4)) == NULL ||
      (PLAN->pnj[0]->calque->pix = load_bitmap("pnj_vieux.bmp")) == NULL ||
      (data->plan[0]->calque[0]->pix =
       load_bitmap("ressource/decor_1/ciel.bmp")) == NULL ||
      (data->plan[0]->calque[1]->pix =
       load_bitmap("ressource/decor_1/nuages.bmp")) == NULL ||
      (data->plan[0]->calque[2]->pix =
       load_bitmap("ressource/decor_1/Montagne.bmp")) == NULL ||
      (data->plan[0]->calque[3]->pix =
       load_bitmap("ressource/decor_1/decor_1.bmp")) == NULL ||
      (data->plan[0]->calque[4]->pix =
       load_bitmap("ressource/decor_1/maison.bmp")) == NULL ||
      (data->plan[0]->calque[5]->pix =
       load_bitmap("ressource/decor_1/poteau1.bmp")) == NULL ||
      (data->plan[0]->calque[6]->pix =
       load_bitmap("ressource/decor_1/Falaise2.bmp")) == NULL)
      /* (data->plan[0]->calque[7]->pix = */
      /*  load_bitmap("ressource/interface/interface_2.0.bmp")) == NULL) */
    return (NULL);
  data->plan[0]->calque[7] = NULL;
  data->plan[0]->pnj[1] = NULL;
  data->plan[0]->obj = NULL;
  /* printf("load ok\n"); */
  make_position_decor_1(data);
  /* printf("position ok\n"); */
  return (data);
}

void	make_position_decor_1(t_data *data)
{
  /* CIEL */
  data->plan[0]->calque[0]->x = 0;
  data->plan[0]->calque[0]->y = 0;
  /* NUAGES */
  data->plan[0]->calque[1]->x = 0;
  data->plan[0]->calque[1]->y = -20;
  /* FALAISE */
  data->plan[0]->calque[2]->x = 558;
  data->plan[0]->calque[2]->y = 10;
  /* DECOR */
  data->plan[0]->calque[3]->x = -22;
  data->plan[0]->calque[3]->y = 0;
  /* MAISON */
  data->plan[0]->calque[4]->x = 234;
  data->plan[0]->calque[4]->y = 3;
  /* POTEAU */
  data->plan[0]->calque[5]->x = 165;
  data->plan[0]->calque[5]->y = 302;
  /* MONTAGNE */
  data->plan[0]->calque[6]->x = -27;
  data->plan[0]->calque[6]->y = 560;
  /* INTERFACE */
  /* data->plan[0]->calque[7]->x = 0; */
  /* data->plan[0]->calque[7]->y = 720; */

  data->plan[0]->calque[0]->x_init = 0;
  data->plan[0]->calque[0]->y_init = 0;
  data->plan[0]->calque[1]->x_init = 0;
  data->plan[0]->calque[1]->y_init = -20;
  data->plan[0]->calque[2]->x_init = 558;
  data->plan[0]->calque[2]->y_init = 10;
  data->plan[0]->calque[3]->x_init = -22;
  data->plan[0]->calque[3]->y_init = 0;
  data->plan[0]->calque[4]->x_init = 234;
  data->plan[0]->calque[4]->y_init = 3;
  data->plan[0]->calque[5]->x_init = 165;
  data->plan[0]->calque[5]->y_init = 302;
  data->plan[0]->calque[6]->x_init = -27;
  data->plan[0]->calque[6]->y_init = 560;
  /* data->plan[0]->calque[7]->x_init = 0; */
  /* data->plan[0]->calque[7]->y_init = 720; */

  data->plan[0]->calque[0]->x_speed = 0;
  data->plan[0]->calque[0]->y_speed = 0;
  data->plan[0]->calque[1]->x_speed = -1;
  data->plan[0]->calque[1]->y_speed = 0.01;
  data->plan[0]->calque[2]->x_speed = -0.2;
  data->plan[0]->calque[2]->y_speed = 0.1;
  data->plan[0]->calque[3]->x_speed = 0;
  data->plan[0]->calque[3]->y_speed = 0;
  data->plan[0]->calque[4]->x_speed = 0;
  data->plan[0]->calque[4]->y_speed = 0;
  data->plan[0]->calque[5]->x_speed = 0;
  data->plan[0]->calque[5]->y_speed = 0;
  data->plan[0]->calque[6]->x_speed = -0.5;
  data->plan[0]->calque[6]->y_speed = 0.5;
  /* data->plan[0]->calque[7]->x_speed = 0; */
  /* data->plan[0]->calque[7]->y_speed = 0; */

  data->plan[0]->pnj[0]->name = my_strcpy("Le Vieux");;
  /* data->plan[0]->pnj[0]->dial = "Dialogue"; */
  data->plan[0]->pnj[0]->desc = my_strcpy("desc de robin");
  data->plan[0]->pnj[0]->cur_dial = 0;
  data->plan[0]->pnj[0]->obj = my_strcpy("clef");
  data->plan[0]->pnj[0]->close = 0;
}

t_data	*load_decor_2(t_data *data)
{
  my_malloc_plan(data, 3);
  if ((PLAN->obj = bunny_malloc(sizeof(t_obj *) * 2)) == NULL ||
      (PLAN->obj[0] = bunny_malloc(sizeof(t_obj) * 1)) == NULL ||
      (PLAN->obj[0]->calque = bunny_malloc(sizeof(t_calque) * 1)) == NULL ||
      (PLAN->obj[0]->calque->pix = load_bitmap("clef.bmp")) == NULL ||
      (data->plan[0]->calque[0]->pix =
       load_bitmap("ressource/decor_2/decor2.bmp")) == NULL ||
      (data->plan[0]->calque[1]->pix =
       load_bitmap("ressource/decor_2/poutre2.bmp")) == NULL ||
      (data->plan[0]->calque[2]->pix =
       load_bitmap("ressource/decor_2/poteau.bmp")) == NULL)
      /* (data->plan[0]->calque[3]->pix = */
      /*  load_bitmap("clef.bmp")) == NULL) */
    return (NULL);
  data->plan[0]->calque[3] = NULL;
  data->plan[0]->obj[1] = NULL;
  /* printf("load ok\n"); */
  make_position_decor_2(data);
  /* printf("position ok\n"); */
  return (data);
}

int	make_position_decor_2(t_data *data)
{
  data->plan[0]->calque[0]->x = 0;
  data->plan[0]->calque[0]->y = 0;
  data->plan[0]->calque[1]->x = 705;
  data->plan[0]->calque[1]->y = 580;
  data->plan[0]->calque[2]->x = -40;
  data->plan[0]->calque[2]->y = 0;
  if ((PLAN->obj[0]->name = my_strcpy("clef")) == NULL ||
      (PLAN->obj[0]->desc = my_strcpy("desc de robin")) == NULL ||
      (data->plan[0]->obj[0]->use = my_strcpy("desc d'edouard")) == NULL)
      return (-1);
  data->plan[0]->obj[0]->erase = 0;
  data->plan[0]->obj[0]->close = 0;
  return (0);
}
