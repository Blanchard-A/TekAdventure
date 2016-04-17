/*
** same_way.c for main in /home/blanch_p/rendu/Semestre2/Infographie/test/search_way
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Wed Apr 13 13:47:01 2016 Alexandre Blanchard
** Last update Wed Apr 13 14:10:46 2016 Alexandre Blanchard
*/

#include "adventure.h"

#include <stdio.h>

int     find_next(int dep, int arr, t_node **nod, int ways)
{
  int   i;
  int   j;

  i = dep + 1;
  j = 0;
  /* printf("Je pars de %i\n", dep); */
  /* (void)arr; */
  /* printf("zdojzdoajdozjdoaidjzaiojd %i\n", nod[dep + 9]->pos_way); */

  while (i < 11)
    {
      j = 0;
      while (j < 3)
        {
          if (nod[i]->way[j] == ways)
            {
              /* printf("pos = %i\n", nod[i]->pos_way); */
              return (nod[i]->pos_way);
              /* return (nod[i]->pos_way); */
              /* printf("way = %i\n", ways); */
              /* printf("%i\n", nod[i]->way[j]); */
            }
          j++;
        }
      i++;

    }
  /* printf("\n\n"); */
  (void)arr;

  return (0);
}

int     find_prev(int dep, int arr, t_node **nod, int ways)
{
  int   i;
  int   j;

  i = dep - 1;
  j = 0;
  /* printf("Je pars de %i\n", dep); */
  /* (void)arr; */
  /* printf("zdojzdoajdozjdoaidjzaiojd %i\n", nod[dep + 9]->pos_way); */

  while (i > 0)
    {
      j = 0;
      while (j < 3)
        {
          if (nod[i]->way[j] == ways)
            {
              /* printf("pos = %i\n", nod[i]->pos_way); */
              return (nod[i]->pos_way);
              /* return (nod[i]->pos_way); */
              /* printf("way = %i\n", ways); */
              /* printf("%i\n", nod[i]->way[j]); */
            }
          j++;
        }
      i--;

    }
  (void)arr;

  return (0);
}

int     nouveau_depart(int ways, int res, t_node **nod)
{
  int   i;
  int   j;

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

int    find_same_way(int way, int dep, int arr, t_node **nod)
{
  int   res;

  res = nod[dep]->pos_way;
  /* while (dep != arr) */
  /*   { */
      if (nod[arr]->pos_way - res > 0)
        {
          res = find_next(dep, arr, nod, way);
          /* printf("Je vais à %i\n", res); */

          dep = nouveau_depart(way, res, nod);
          /* printf("Je vais à %i\n\n", dep); */
	  return (dep);
        }
      else
        {
          res = find_prev(dep, arr, nod, way);

          dep = nouveau_depart(way, res, nod);
	  return (dep);
          /* printf("Je vais à %i\n\n", dep); */
	}
    /* } */

}
