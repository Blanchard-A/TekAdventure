/*
** diff_way.c for main in /home/blanch_p/rendu/Semestre2/Infographie/test/search_way
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Wed Apr 13 14:06:34 2016 Alexandre Blanchard
** Last update Sun Apr 17 22:34:47 2016 Voyevoda
*/

#include "adventure.h"

int	find_node_inter(int dep, int arr, t_node **nod)
{
  int	i;
  int	j;
  int	first;
  int	sec;
  int	max;
  
  j = 0;
  i = 0;
  max = 0;
  while (nod[i] != NULL)
    {
      j = 0;
      first = 0;
      sec = 0;
      while (j < 3)
	{
	  if ((nod[i]->way[j] == nod[dep]->way[0] ||
	       nod[i]->way[j] == nod[dep]->way[1] ||
	       nod[i]->way[j] == nod[dep]->way[2]) &&
	      nod[i]->way[j] > -1)
	    first = 1;
	  if ((nod[i]->way[j] == nod[arr]->way[0] ||
	       nod[i]->way[j] == nod[arr]->way[1] ||
	       nod[i]->way[j] == nod[arr]->way[2]) &&
	      nod[i]->way[j] > -1)
	    sec = 1;
	  j++;
	}
      if (sec == 1 && first == 1 && nod[max]->pos_way <= nod[i]->pos_way)
	max = i;
      i++;
    }
  return (max);
}

int	find_way_inter(int dep, int arr, t_node **nod)
{
  int	i;
  int	j;
  int	first;
  int	sec;
  int	max;
  
  j = 0;
  i = 0;
  max = 0;
  while (nod[i] != NULL)
    {
      j = 0;
      first = 0;
      sec = 0;
      while (j < 3)
	{
	  if ((nod[i]->way[j] == nod[dep]->way[0] ||
	       nod[i]->way[j] == nod[dep]->way[1] ||
	       nod[i]->way[j] == nod[dep]->way[2]) &&
	      nod[i]->way[j] > -1)
	    first = 1;
	  if ((nod[i]->way[j] == nod[arr]->way[0] ||
	       nod[i]->way[j] == nod[arr]->way[1] ||
	       nod[i]->way[j] == nod[arr]->way[2]) &&
	      nod[i]->way[j] > -1)
	    sec = 1;
	  j++;
	}
      if (sec == 1 && first == 1 && nod[max]->pos_way <= nod[i]->pos_way)
	max = i;
      i++;
    }
  return (max);  
}

int	find_diff_way(int dep, int arr, t_node **nod)
{
  int	inter;

  inter = find_node_inter(dep, arr, nod); 
  return (inter);  
}
