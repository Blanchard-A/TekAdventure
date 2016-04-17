/*
** parsing.c for tekadventure in /home/voyevoda/rendu/infographie/gfx_tekadventure
** 
** Made by Voyevoda
** Login   <ustarr_r@epitech.net>
** 
** Started on  Sun Apr 17 16:38:50 2016 Voyevoda
** Last update Sun Apr 17 17:04:40 2016 Voyevoda
*/

#include <lapin.h>

int	main(int ac, char **av)
{
  (void) ac;

  t_bunny_ini	*buffer;
  char		*s;
  int		j;

  j = -1;  
  if ((buffer = bunny_load_ini(av[1])) == NULL)
    return (-1);
  while ((s = bunny_ini_get_field(buffer, "MAP1", "", ++j)) != NULL)
    
}
