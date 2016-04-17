/*
** load.c for tekadv in /home/blanch_p/rendu/Semestre2/Infographie/gfx_tekadventure
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Fri Apr 15 10:26:38 2016 Alexandre Blanchard
** Last update Sun Apr 17 23:05:17 2016 Voyevoda
*/

#include "adventure.h"

void	free_calque(t_data *data)
{
  int	i;

  i = 0;
  while (data->plan[0]->calque[i] != NULL)
    {
      bunny_delete_clipable(&data->plan[0]->calque[i]->pix->clipable);
      bunny_free(data->plan[0]->calque[i]);
      i++;      
    }
  bunny_free(data->plan[0]->calque);
  bunny_free(data->plan[0]);  
  bunny_free(data->plan);
}

t_data	*malloc_and_load_perso(t_data *data)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  data->player = bunny_malloc(sizeof(t_char) * 1);
  data->player->mov = bunny_malloc(sizeof(t_move *) * 4);
  data->player->cur_node = 1;
  data->player->dest_node = 1;
  data->player->x = 193;
  data->player->y = 409;
  while (i < 4)
    {
      data->player->mov[i] = bunny_malloc(sizeof(t_move) * 1);
      data->player->mov[i]->calque = bunny_malloc(sizeof(t_calque *) * 2);
      data->player->mov[i]->calque[0] = bunny_malloc(sizeof(t_calque ) * 1);
      data->player->mov[i]->calque[1] = bunny_malloc(sizeof(t_calque ) * 1);
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
	  data->player->mov[i]->calque[j]->x_speed = 0;
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
  data->plan[0]->pnj = malloc(sizeof(t_pnj *) * 2);
  data->plan[0]->pnj[0] = malloc(sizeof(t_pnj) * 1);
  data->plan[0]->pnj[0]->calque = malloc(sizeof(t_calque) * 1);
  data->plan[0]->pnj[0]->dial = malloc(sizeof(char *) * 4);
  data->plan[0]->pnj[0]->calque->pix = load_bitmap("pnj_vieux.bmp");
  if ((data->plan[0]->calque[0]->pix =
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
    return (NULL);
  data->plan[0]->calque[7] = NULL;
  make_position_decor_1(data);
  return (data);
}

void	make_position_decor_1(t_data *data)
{
  data->plan[0]->calque[0]->x = 0;
  data->plan[0]->calque[0]->y = 0;
  data->plan[0]->calque[1]->x = 0;
  data->plan[0]->calque[1]->y = -20;
  data->plan[0]->calque[2]->x = 558;
  data->plan[0]->calque[2]->y = 10;
  data->plan[0]->calque[3]->x = -22;
  data->plan[0]->calque[3]->y = 0;
  data->plan[0]->calque[4]->x = 234;
  data->plan[0]->calque[4]->y = 3;
  data->plan[0]->calque[5]->x = 165;
  data->plan[0]->calque[5]->y = 302;
  data->plan[0]->calque[6]->x = -27;
  data->plan[0]->calque[6]->y = 560;
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
  data->plan[0]->pnj[0]->name = "Le Vieux";
  data->plan[0]->pnj[0]->desc = "desc de robin";
  data->plan[0]->pnj[0]->cur_dial = 0;
  data->plan[0]->pnj[0]->obj = "clef";
  data->plan[0]->pnj[0]->close = 0;
}

t_data	*load_decor_2(t_data *data)
{
  my_malloc_plan(data, 3);
  data->plan[0]->obj = malloc(sizeof(t_obj *) * 2);
  data->plan[0]->obj[0] = malloc(sizeof(t_obj) * 1);
  data->plan[0]->obj[0]->calque = malloc(sizeof(t_calque) * 1);
  data->plan[0]->obj[0]->calque->pix = load_bitmap("clef.bmp");
  if ((data->plan[0]->calque[0]->pix =
       load_bitmap("ressource/decor_2/decor2.bmp")) == NULL ||
      (data->plan[0]->calque[1]->pix =
       load_bitmap("ressource/decor_2/poutre2.bmp")) == NULL ||
      (data->plan[0]->calque[2]->pix =
       load_bitmap("ressource/decor_2/poteau.bmp")) == NULL)
    return (NULL);
  data->plan[0]->calque[3] = NULL;
   make_position_decor_2(data);
   return (data);
}

void	make_position_decor_2(t_data *data)
{  
  data->plan[0]->calque[0]->x = 0;
  data->plan[0]->calque[0]->y = 0;
  data->plan[0]->calque[1]->x = 705;
  data->plan[0]->calque[1]->y = 580;
  data->plan[0]->calque[2]->x = -40;
  data->plan[0]->calque[2]->y = 0;
  data->plan[0]->obj[0]->name = "clef";
  data->plan[0]->obj[0]->desc = "desc de robin";
  data->plan[0]->obj[0]->use = "desc d'edouard";
  data->plan[0]->obj[0]->erase = 0;
  data->plan[0]->obj[0]->close = 0;
}
