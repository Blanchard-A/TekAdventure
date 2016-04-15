/*
** load.c for tekadv in /home/blanch_p/rendu/Semestre2/Infographie/gfx_tekadventure
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Fri Apr 15 10:26:38 2016 Alexandre Blanchard
** Last update Fri Apr 15 16:42:03 2016 Alexandre Blanchard
*/

#include "adventure.h"

#include <stdio.h>

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
  data->player = bunny_malloc(sizeof(t_char) * 1);

  data->player->mov = bunny_malloc(sizeof(t_move *) * 1);
  data->player->mov[0] = bunny_malloc(sizeof(t_move) * 1);
  data->player->mov[0]->calque = bunny_malloc(sizeof(t_calque *) * 1);
  data->player->mov[0]->calque[0] = bunny_malloc(sizeof(t_calque ) * 1);
  data->player->mov[0]->calque[0]->pix = load_bitmap("walk_face_2.bmp");

  change_clipable(data->player->mov[0]->calque[0]->pix, 12);

  data->player->mov[0]->calque[0]->x = 0;
  data->player->mov[0]->calque[0]->x_init = 0;
  data->player->mov[0]->calque[0]->x_speed = 0;
  data->player->mov[0]->calque[0]->y = 0;
  data->player->mov[0]->calque[0]->y_init = 0;
  data->player->mov[0]->calque[0]->y_speed = 0;



  return (data);
}

t_data	*load_decor_1(t_data *data)
{
  my_malloc_plan(data, 8);
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
       load_bitmap("ressource/decor_1/Falaise2.bmp")) == NULL ||
      (data->plan[0]->calque[7]->pix =
       load_bitmap("ressource/interface/interface_2.0.bmp")) == NULL)
    return (NULL);
  data->plan[0]->calque[8] = NULL;
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
  data->plan[0]->calque[7]->x = 0;
  data->plan[0]->calque[7]->y = 720;

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
  data->plan[0]->calque[7]->x_init = 0;
  data->plan[0]->calque[7]->y_init = 720;

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
  data->plan[0]->calque[7]->x_speed = 0;
  data->plan[0]->calque[7]->y_speed = 0;

}

t_data	*load_decor_2(t_data *data)
{
  my_malloc_plan(data, 4);
  if ((data->plan[0]->calque[0]->pix =
       load_bitmap("ressource/decor_2/decor2.bmp")) == NULL ||
      (data->plan[0]->calque[1]->pix =
       load_bitmap("ressource/decor_2/poutre2.bmp")) == NULL ||
      (data->plan[0]->calque[2]->pix =
       load_bitmap("ressource/decor_2/poteau.bmp")) == NULL ||
      (data->plan[0]->calque[3]->pix =
       load_bitmap("ressource/interface/interface_2.0.bmp")) == NULL)
    return (NULL);
  data->plan[0]->calque[4] = NULL;
  /* printf("load ok\n"); */
  make_position_decor_2(data);
  /* printf("position ok\n"); */
  return (data);
}

void	make_position_decor_2(t_data *data)
{  
  data->plan[0]->calque[0]->x = 0;
  data->plan[0]->calque[0]->y = 0;
  data->plan[0]->calque[1]->x = 665;
  data->plan[0]->calque[1]->y = 580;
  data->plan[0]->calque[2]->x = -40;
  data->plan[0]->calque[2]->y = 0;
  data->plan[0]->calque[3]->x = 0;
  data->plan[0]->calque[3]->y = 720; 
}
