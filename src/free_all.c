/*
** free_all.c for gfx_tekadventure in /home/puilla_e/Semestre2/infographie/
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Tue Mar 29 16:50:20 2016 edouard puillandre
** Last update Tue Mar 29 16:52:20 2016 edouard puillandre
*/

#include "adventure.h"

t_bunny_response	my_fct_free(t_data *data, int error_true)
{
  bunny_delete_clipable(&data->pix->clipable);
  bunny_free(data->pos);
  bunny_stop(data->win);
  bunny_free(data);
  if (error_true == 1)
    return (EXIT_ON_ERROR);
  return (EXIT_ON_SUCCESS);
}
