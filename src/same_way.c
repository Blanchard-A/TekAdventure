/*
** same_way.c for main in /home/blanch_p/rendu/Semestre2/Infographie/test/search_way
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Wed Apr 13 13:47:01 2016 Alexandre Blanchard
** Last update Sun Apr 17 21:59:08 2016 Alexandre Blanchard
*/

#include "adventure.h"

int	find_next(int dep, t_node **nod, int ways)
{
  int	i;
  int	j;

  i = dep + 1;
  j = 0;
  while (i < 11)
    {
      j = 0;
      while (j < 3)
        {
          if (nod[i]->way[j] == ways)
            {
              return (nod[i]->pos_way);
            }
          j++;
        }
      i++;

    }
  return (0);
}

int	find_prev(int dep, t_node **nod, int ways)
{
  int	i;
  int	j;

  i = dep - 1;
  j = 0;

  while (i > 0)
    {
      j = 0;
      while (j < 3)
        {
          if (nod[i]->way[j] == ways)
            {
              return (nod[i]->pos_way);
            }
          j++;
        }
      i--;
    }
  return (0);
}

int	nouveau_depart(int ways, int res, t_node **nod)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (i < 11)
    {
      j = 0;
      while (j < 3)
        {
          if (nod[i]->way[j] == ways && nod[i]->pos_way == res)
            return (i);

          j++;
        }
      i++;
    }
  return (0);

}

int	find_same_way(int way, int dep, int arr, t_node **nod)
{
  int	res;

  res = nod[dep]->pos_way;
  if (nod[arr]->pos_way - res > 0)
    {
      res = find_next(dep, nod, way);
      dep = nouveau_depart(way, res, nod);
      return (dep);
    }
  else
    {
      res = find_prev(dep, nod, way);
      dep = nouveau_depart(way, res, nod);
      return (dep);
    }
}
