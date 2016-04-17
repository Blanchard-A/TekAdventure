/*
** set_ram.c for gfx_tekadventure in /home/puilla_e/Semestre2/infographie/
**
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
**
** Started on  Sun Apr 17 22:30:06 2016 edouard puillandre
** Last update Sun Apr 17 23:22:02 2016 edouard puillandre
*/

#include "adventure.h"

int		bunny_set_max_ram()
{
  t_bunny_ini	*buffer;
  unsigned int	j;
  const	char	*s;
  int		ram;

  j = - 1;
  if ((buffer = bunny_load_ini(CONFIG)) == NULL)
    return (- 1);
  while ((s = bunny_ini_get_field
	  (buffer, "configuration", "max_ram", ++j)) != NULL)
    ram = my_getnbr(s);
  return (ram);
}
