/*
** change_clipable.c for tekadv in /home/blanch_p/rendu/Semestre2/Infographie/gfx_tekadventure
**
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
**
** Started on  Fri Apr 15 11:21:40 2016 Alexandre Blanchard
** Last update Fri Apr 15 18:25:50 2016 edouard puillandre
*/

#include "adventure.h"

#include <stdio.h>

void    change_clipable(t_bunny_pixelarray *perso, int div)
{
  perso->clipable.clip_width = perso->clipable.clip_width / div;
  /* printf("%i\n", perso->clipable.clip_width); */
}

void    change_pos_perso(t_bunny_pixelarray *perso, int loop)
{
  perso->clipable.clip_x_position = loop * perso->clipable.clip_width;
}