/*
** go.c for tekadv in /home/blanch_p/rendu/Semestre2/Infographie/gfx_tekadventure
**
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
**
** Started on  Sun Apr 17 12:10:27 2016 Alexandre Blanchard
** Last update Sun Apr 17 22:41:24 2016 Alexandre Blanchard
*/

#include "adventure.h"

int	my_go(t_data *data)
{
  int	node;
  int	i;

  i = 0;
  if (data->player->chemin[0] != -1)
    return (0);
  if ((node = check_click_node(data)) >= 0)
    {
      if (node != 10)
	{
	  data->player->chemin = search_way(data->player->cur_node,
					    node, data->plan[0]->node,
					    data->player->chemin);
	  while (data->player->chemin[i] >= 0)
	    {
	      i++;
	    }
	  data->player->dest_node = data->player->chemin[i - 1];
	}
    }
  return (0);
}

int	find_way(t_node *dep, t_node *arr)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (dep->way[i] && i < 3)
    {
      j = 0;
      while (j < 3)
        {
          if (dep->way[i] == arr->way[j])
            return (dep->way[i]);
          j++;
        }
      i++;
    }
  return (-1);
}

int	*pas_meme_chemin(int *chemin, int depart, int arrivee, t_node **nod)
{
  int	inter;
  int	i;
  int	j;

  j = 0;
  inter = find_diff_way(depart, arrivee, nod);
  while (depart != inter)
    {
      chemin[j++] = depart;
      inter = find_diff_way(depart, arrivee, nod);
      i = find_way(nod[depart], nod[inter]);
      depart = find_same_way(i, depart, inter, nod);
    }
  while (depart != arrivee)
    {
      chemin[j++] = depart;
      i = find_way(nod[depart], nod[arrivee]);
      depart = find_same_way(i, depart, arrivee, nod);
    }
  chemin[j++] = depart;
  chemin[j] = -1;
  return (chemin);
}

int	*search_way(int depart, int arrivee, t_node **nod, int *chemin)
{
  int	i;
  int	j;

  j = 0;
  if ((i = find_way(nod[depart], nod[arrivee])) > 0)
    {
      while (depart != arrivee)
        {
          chemin[j++] = depart;
	  depart = find_same_way(i, depart, arrivee, nod);
	}
    }
  else
    {
      chemin = pas_meme_chemin(chemin, depart, arrivee, nod);
      return (chemin);
    }
  chemin[j++] = depart;
  chemin[j] = -1;
  return (chemin);
}
