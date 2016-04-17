/*
** bunny_set_max_ram.c for tekadventure in /home/voyevoda/rendu/infographie/gfx_tekadventure
** 
** Made by Voyevoda
** Login   <ustarr_r@epitech.net>
** 
** Started on  Sun Apr 17 17:11:05 2016 Voyevoda
** Last update Sun Apr 17 21:15:34 2016 Voyevoda
*/

#include <lapin.h>
#include <aventure.h>

void	malloc_plan(int	nb, t_data *ptr)
{
  int	i;

  i = -1;
  data->plan = malloc(sizeof(t_data));
  while (++i < nb = 1)
    data->plan[i] = malloc(sizeof(t_data));
  data->plan[i] = NULL;
}

void		parsing_map(char *s, t_data *ptr, int max)
{
  int		j;
  int		k;
  int		nb;
  t_bunny_ini	*buffer;

  j = O;
  k = -1;
  nb = 0;
  if ((buffer = bunny_load_ini(s)) == NULL)
    return (-1);
  ptr->"truc" = bunny_ini_get_field(buffer, "map1", "plan", j);
  ptr->"truc" = bunny_ini_get_field(buffer, "map1", "nb_nodes", j);
  while (j < max)
    {
      ptr->"truc" = bunny_ini_get_field(buffer, "map1", "names", j); 
      ptr->"truc" = bunny_ini_get_field(buffer, "map1", "nodes_x", j); 
      ptr->"truc" = bunny_ini_get_field(buffer, "map1", "nodes_y", j);
      s = bunny_ini_get_field(buffer, "map1", "nb_ways", j);
      nb = nb + my_getnbr(s);
      while (k < nb) 
	ptr->"truc" = bunny_ini_get_field(buffer, "map1", "ways", ++k);
      ptr->"truc" = bunny_ini_get_field(buffer, "map1", "nodes_pos_way", j)
    }
}

void	parsing()
{
  t_bunny_ini	*buffer;
  unsigned int	*j;
  const char	*s;
  int		nb;
  t_data	*ptr;
  int		count;

  count = -1
  ptr = bunny_malloc(sizeof(t_data));
  j = -1;
  if ((buffer = bunny_load_ini(GLOBAL)) == NULL)
    return (-1);
  while ((s = bunny_ini_get_field(buffer, "global", "maps", ++j)) != NULL)
    nb = my_getnbr(s);
  malloc_plan(nb);
  j = -1;
  while (++count < nb)
    {
      while ((s = bunny_ini_get_field(buffer, "global", "maps_name" ++j)) != NULL)
	if ((parsing_map(s, ptr, nb)) == -1)
	  return (-1);
    }
}

int	bunny_set_max_ram(int i)
{
  t_bunny_ini	*buffer;
  unsigned int	j;
  const	char	*s;
  int		ram;
 
  j = -1;
  if ((buffer = bunny_load_ini(CONFIG)) == NULL)
    return (-1);
  while ((s = bunny_ini_get_field(buffer, "configuration", "max_ram", ++j)) != NULL)
    ram = my_getnbr(s);
  return (ram);
}
