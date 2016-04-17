/*
** diff_way.c for main in /home/blanch_p/rendu/Semestre2/Infographie/test/search_way
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Wed Apr 13 14:06:34 2016 Alexandre Blanchard
** Last update Thu Apr 14 09:21:36 2016 Alexandre Blanchard
*/

#include "adventure.h"
#include <stdio.h>

int	find_node_inter(int dep, int arr, t_node **nod)
{
  int	i;
  int	j;
  int	first;
  int	sec;
  int	max;
  
  j = 0;
  i = 0;
  /* (void)arr; */
  max = 0;
  while (nod[i] != NULL)
    {
      j = 0;
      first = 0;
      sec = 0;
      /* printf("ZERO\n"); */
      while (j < 3)
	{
	  /* printf("nod[%i]->way[%i] = %i\n", i, j, nod[i]->way[j]); */
	  /* printf("dep[%i]->way[%i] = %i\n", dep, 0, nod[dep]->way[0]); */
	  /* printf("dep[%i]->way[%i] = %i\n", dep, 1, nod[dep]->way[1]); */
	  /* printf("dep[%i]->way[%i] = %i\n", dep, 2, nod[dep]->way[2]); */
	  /* printf("arr[%i]->way[%i] = %i\n", arr, 0, nod[arr]->way[0]); */
	  /* printf("arr[%i]->way[%i] = %i\n", arr, 1, nod[arr]->way[1]); */
	  /* printf("arr[%i]->way[%i] = %i\n", arr, 2, nod[arr]->way[2]); */
	  /* printf("\n"); */
	  if ((nod[i]->way[j] == nod[dep]->way[0] ||
	       nod[i]->way[j] == nod[dep]->way[1] ||
	       nod[i]->way[j] == nod[dep]->way[2]) &&
	      nod[i]->way[j] > -1)
	    {
	      first = 1;
	      /* printf("FIRST\n"); */
	      /* printf("TROUVE\n"); */
	      /* printf("i first = %i\n", i); */
	      /* printf("way first = %i\n", nod[i]->way[j]); */
	      /* while (j < 3) */
	      /* 	{ */
	    }
	  if ((nod[i]->way[j] == nod[arr]->way[0] ||
	       nod[i]->way[j] == nod[arr]->way[1] ||
	       nod[i]->way[j] == nod[arr]->way[2]) &&
	      nod[i]->way[j] > -1)
	    {
	      sec = 1;
	      /* printf("SEC\n"); */
	      /* printf("i sec = %i\n", i); */
	      /* printf("way sec = %i\n\n", nod[i]->way[j]); */
	      /* printf("i = %i\n\n", i); */
	      /* return (nod[i]->way[j]); */
	    }
	  j++;
	}
      if (sec == 1 && first == 1 && nod[max]->pos_way <= nod[i]->pos_way)
	{
	  /* printf("MAX\n"); */
	  /* printf("%i\n%i\n", nod[max]->pos_way, nod[i]->pos_way); */
	  max = i;
	}
      i++;
    }
  /* printf("max = %i\n", max); */
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
  /* (void)arr; */
  max = 0;
  while (nod[i] != NULL)
    {
      j = 0;
      first = 0;
      sec = 0;
      /* printf("ZERO\n"); */
      while (j < 3)
	{
	  /* printf("nod[%i]->way[%i] = %i\n", i, j, nod[i]->way[j]); */
	  /* printf("dep[%i]->way[%i] = %i\n", dep, 0, nod[dep]->way[0]); */
	  /* printf("dep[%i]->way[%i] = %i\n", dep, 1, nod[dep]->way[1]); */
	  /* printf("dep[%i]->way[%i] = %i\n", dep, 2, nod[dep]->way[2]); */
	  /* printf("arr[%i]->way[%i] = %i\n", arr, 0, nod[arr]->way[0]); */
	  /* printf("arr[%i]->way[%i] = %i\n", arr, 1, nod[arr]->way[1]); */
	  /* printf("arr[%i]->way[%i] = %i\n", arr, 2, nod[arr]->way[2]); */
	  /* printf("\n"); */
	  if ((nod[i]->way[j] == nod[dep]->way[0] ||
	       nod[i]->way[j] == nod[dep]->way[1] ||
	       nod[i]->way[j] == nod[dep]->way[2]) &&
	      nod[i]->way[j] > -1)
	    {
	      first = 1;
	      /* printf("FIRST\n"); */
	      /* printf("TROUVE\n"); */
	      /* printf("i first = %i\n", i); */
	      /* printf("way first = %i\n", nod[i]->way[j]); */
	      /* while (j < 3) */
	      /* 	{ */
	    }
	  if ((nod[i]->way[j] == nod[arr]->way[0] ||
	       nod[i]->way[j] == nod[arr]->way[1] ||
	       nod[i]->way[j] == nod[arr]->way[2]) &&
	      nod[i]->way[j] > -1)
	    {
	      sec = 1;
	      /* printf("SEC\n"); */
	      /* printf("i sec = %i\n", i); */
	      /* printf("way sec = %i\n\n", nod[i]->way[j]); */
	      /* printf("i = %i\n\n", i); */
	      /* return (nod[i]->way[j]); */
	    }
	  j++;
	}
      if (sec == 1 && first == 1 && nod[max]->pos_way <= nod[i]->pos_way)
	{
	  /* printf("MAX\n"); */
	  /* printf("%i\n%i\n", nod[max]->pos_way, nod[i]->pos_way); */
	  max = i;
	}
      i++;
    }
  /* printf("max = %i\n", max); */
  return (max);  
}


int	find_diff_way(int dep, int arr, t_node **nod)
{
  int	inter;
  /* int	way; */

  inter = find_node_inter(dep, arr, nod);
  /* printf("inter = %i\n", inter); */
  /* way = find_way_inter(dep, arr, nod); */
  /* printf("way = %i\n", way); */

  /* printf("way %i\n", nod[dep]->way[0]); */
  /* printf("way %i\n", nod[dep]->way[1]); */
  /* printf("way %i\n", nod[dep]->way[2]); */

  /* printf("way %i\n", nod[arr]->way[0]); */
  /* printf("way %i\n", nod[arr]->way[1]); */
  /* printf("way %i\n", nod[arr]->way[2]); */
  
  return (inter);
  
}
