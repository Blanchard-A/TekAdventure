/*
** check_click_bis.c for tekadv in /home/blanch_p/Infographie/gfx_tekadventure
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Sun Apr 17 23:03:24 2016 Alexandre Blanchard
** Last update Sun Apr 17 23:03:55 2016 Alexandre Blanchard
*/

#include "adventure.h"

int	check_click_bis(t_data *data)
{
  int	check;

  if ((check = check_click_button(data)) != - 1)
    data->board->sel = check;
  else
    {
      check = data->board->sel;
      data->board->button[check]->fct(data);
    }
  return (0);
}
