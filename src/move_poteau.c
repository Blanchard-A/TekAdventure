/*
** move_poteau.c for tekadv in /home/blanch_p/rendu/Semestre2/Infographie/gfx_tekadventure
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Sun Apr 17 19:03:05 2016 Alexandre Blanchard
** Last update Sun Apr 17 19:20:54 2016 Alexandre Blanchard
*/

#include "adventure.h"

#include <stdio.h>

void	move_poteau(t_data *data)
{
  printf("coef x = %f\n", data->player->coef[0]);

  if (data->player->coef[0] < 0)
    {
      data->plan[0]->calque[1]->x = data->plan[0]->calque[1]->x + 1.5;
      data->plan[0]->calque[2]->x = data->plan[0]->calque[2]->x + 1.5;
      data->plan[0]->calque[0]->x = data->plan[0]->calque[0]->x + 0.5;
    }
  if (data->player->coef[0] > 0)
    {
      data->plan[0]->calque[1]->x = data->plan[0]->calque[1]->x - 1.5;
      data->plan[0]->calque[2]->x = data->plan[0]->calque[2]->x - 1.5;
      data->plan[0]->calque[0]->x = data->plan[0]->calque[0]->x - 0.5;
    }


  /* if (data->player->x % 2 == 0 && data->player->x < 58 && */
  /*     data->player->coef[0] < 0) */
  /*   { */
  /*     data->plan[0]->calque[1]->x = data->plan[0]->calque[1]->x - 1; */
  /*     data->plan[0]->calque[1]->x = data->plan[0]->calque[1]->x - 1; */
  /*   } */

  
}