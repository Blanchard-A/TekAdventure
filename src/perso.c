/*
** perso.c for tekadv in /home/blanch_p/rendu/gfx_tekadventure
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Sun Apr 17 23:09:56 2016 Alexandre Blanchard
** Last update Sun Apr 17 23:19:34 2016 Alexandre Blanchard
*/

#include "adventure.h"

int	malloc_perso(t_data *data)
{
  int   i;

  i = 0;
  if ((data->player = bunny_malloc(sizeof(t_char) * 1)) == NULL ||
      (data->player->mov = bunny_malloc(sizeof(t_move *) * 4)) == NULL)
    return (-1);
  data->player->cur_node = 1;
  data->player->dest_node = 1;
  data->player->x = 193;
  data->player->y = 409;
  while (i < 4)
    {
      if ((MOVI = bunny_malloc(sizeof(t_move) * 1)) == NULL ||
          (MOVI->calque = bunny_malloc(sizeof(t_calque *) * 2)) == NULL ||
          (MOVI->calque[0] = bunny_malloc(sizeof(t_calque ) * 1)) == NULL ||
          (MOVI->calque[1] = bunny_malloc(sizeof(t_calque ) * 1)) == NULL)
        return (-1);
      i++;
    }
  return (0);
}

int	load_perso(t_data *data)
{
  if ((PLAYER->mov[0]->calque[0]->pix =
       load_bitmap("ressource/char/walk_face_2.bmp")) == NULL ||
      (data->player->mov[1]->calque[0]->pix =
       load_bitmap("ressource/char/walk_left_2.bmp")) == NULL ||
      (data->player->mov[2]->calque[0]->pix =
       load_bitmap("ressource/char/walk_back_2.bmp")) == NULL ||
      (data->player->mov[3]->calque[0]->pix =
       load_bitmap("ressource/char/walk_right_2.bmp")) == NULL ||
      (data->player->mov[0]->calque[1]->pix =
       load_bitmap("ressource/char/stand_face.bmp")) == NULL ||
      (data->player->mov[1]->calque[1]->pix =
       load_bitmap("ressource/char/stand_left.bmp")) == NULL ||
      (data->player->mov[2]->calque[1]->pix =
       load_bitmap("ressource/char/stand_back.bmp")) == NULL ||
      (data->player->mov[3]->calque[1]->pix =
       load_bitmap("ressource/char/stand_right.bmp")) == NULL)
    return (-1);
  return (0);
}

t_data	*malloc_and_load_perso(t_data *data)
{
  int	i;
  int	j;

  malloc_perso(data);
  load_perso(data);
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
