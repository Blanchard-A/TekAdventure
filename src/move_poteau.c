/*
** move_poteau.c for tekadv in /home/blanch_p/rendu/gfx_tekadventure
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Sun Apr 17 19:03:05 2016 Alexandre Blanchard
** Last update Sun Apr 17 23:06:15 2016 Alexandre Blanchard
*/

#include "adventure.h"

void	move_poteau(t_data *data)
{
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
}
