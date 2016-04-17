/*
** free_all.c for gfx_tekadventure in /home/puilla_e/Semestre2/infographie/
**
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
**
** Started on  Tue Mar 29 16:50:20 2016 edouard puillandre
** Last update Sun Apr 17 21:06:03 2016 edouard puillandre
*/

#include "adventure.h"

void	free_obj(t_data *data)
{
  int	i;

  i = - 1;
  if (data->plan[0]->obj == NULL)
    return ;
  while (data->plan[0]->obj[++i] != NULL)
    {
      bunny_delete_clipable(&data->plan[0]->obj[i]->calque->pix->clipable);
      bunny_free(data->plan[0]->obj[i]->calque);
      bunny_free(data->plan[0]->obj[i]->name);
      bunny_free(data->plan[0]->obj[i]->desc);
      bunny_free(data->plan[0]->obj[i]->use);
      bunny_free(data->plan[0]->obj[i]);
      i++;
    }
  bunny_free(data->plan[0]->obj);
}

void	free_pnj(t_data *data)
{
  int	i;

  i = - 1;
  if (data->plan[0]->pnj == NULL)
    return ;
  while (data->plan[0]->pnj[++i] != NULL)
    {
      bunny_delete_clipable(&data->plan[0]->pnj[i]->calque->pix->clipable);
      bunny_free(data->plan[0]->pnj[i]->calque);
      bunny_free(data->plan[0]->pnj[i]->name);
      bunny_free(data->plan[0]->pnj[i]->dial);
      bunny_free(data->plan[0]->pnj[i]->obj);
      bunny_free(data->plan[0]->pnj[i]->desc);
      bunny_free(data->plan[0]->pnj[i]);
      i++;
    }
  bunny_free(data->plan[0]->pnj);
}

void	free_calque(t_data *data)
{
  int	i;

  i = - 1;
  while (data->plan[0]->calque[++i] != NULL)
    {
      bunny_delete_clipable(&data->plan[0]->calque[i]->pix->clipable);
      bunny_free(data->plan[0]->calque[i]);
      i++;
    }
  i = - 1;
  while (data->plan[0]->node[++i] != NULL)
    {
      bunny_free(&data->plan[0]->node[i]->way);
      bunny_free(data->plan[0]->node[i]);
      i++;
    }
  bunny_free(data->plan[0]->calque);
  bunny_free(data->plan[0]->node);
  free_pnj(data);
  free_obj(data);
  bunny_free(data->plan[0]);
  bunny_free(data->plan);
}

void	my_free_player(t_char *player)
{
  int	i;

  i = - 1;
  while (player->mov[++i])
    {
      bunny_delete_clipable(&player->mov[i]->calque[0]->pix->clipable);
      bunny_delete_clipable(&player->mov[i]->calque[1]->pix->clipable);
      bunny_free(player->mov[i]->calque[1]);
      bunny_free(player->mov[i]->calque[0]);
    }
  bunny_free(player->mov);
  bunny_free(player->chemin);
  bunny_free(player);
}

t_bunny_response	my_fct_free(t_data *data, int error_true)
{
  free_calque(data);
  bunny_delete_clipable(&data->pix->clipable);
  bunny_free(data->pos);
  bunny_stop(data->win);
  bunny_free(data);
  if (error_true == 1)
    return (EXIT_ON_ERROR);
  return (EXIT_ON_SUCCESS);
}
