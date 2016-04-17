/*
** go.c for tekadv in /home/blanch_p/rendu/Semestre2/Infographie/gfx_tekadventure
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Sun Apr 17 12:10:27 2016 Alexandre Blanchard
** Last update Sun Apr 17 15:29:56 2016 Alexandre Blanchard
*/

#include "adventure.h"

#include <stdio.h>

int     my_go(t_data *data)
{
  int	node;
  int	i;

  i = 0;
  if (data->player->chemin[0] != -1)
    return (0);
  if ((node = check_click(data)) >= 0)
    {      
      data->player->chemin = search_way(data->player->cur_node,
					node, data->plan[0]->node, data->player->chemin);
      while (data->player->chemin[i] >= 0)
	{
	  i++;
	}
      data->player->dest_node = data->player->chemin[i - 1];
    }  
  return (0);
}

int     find_way(t_node *dep, t_node *arr)
{
  int   i;
  int   j;

  j = 0;
  i = 0;
  while (dep->way[i] && i < 3)
    {
      j = 0;
      while (j < 3)
        {
          /* printf("dep = %i\narr = %i\n", dep->way[i], arr->way[j]); */
          if (dep->way[i] == arr->way[j])
            return (dep->way[i]);
          j++;
        }
      /* printf("\n\n"); */
      i++;
    }
  return (-1);
}

int     *search_way(int depart, int arrivee, t_node **nod, int *chemin)
{
  int   i;
  int   inter;
  /* int   *chemin; */
  int   j;
  /* int        way; */
  /* int        res; */

  /* i = depart; */
  j = 0;
  /* chemin = bunny_malloc(sizeof(int) * 10); */
  if ((i = find_way(nod[depart], nod[arrivee])) > 0)
    {
      /* printf("Meme chemin\n"); */
      while (depart != arrivee)
        {
          chemin[j++] = depart;
          /* printf("Je pars à %i\n", depart); */
          /* printf("Meme chemin\n"); */
          depart = find_same_way(i, depart, arrivee, nod);
          /* printf("J'arrive à %i\n\n", depart); */
        }
    }
  else
    {
      /* printf("PAS Meme chemin\n"); */
      inter = find_diff_way(depart, arrivee, nod);
      while (depart != inter)
        {
          chemin[j++] = depart;
          /* printf("Je pars à %i\n", depart); */
          inter = find_diff_way(depart, arrivee, nod);
          /* printf("inter = %i\n", inter); */
          i = find_way(nod[depart], nod[inter]);
          depart = find_same_way(i, depart, inter, nod);

          /* printf("i = %i\n", i); */

          /* printf("J'arrive à %i\n\n", depart); */
          /* break; */
          /* (void)inter; */
        }
      while (depart != arrivee)
        {
          /* break; */
          chemin[j++] = depart;
          i = find_way(nod[depart], nod[arrivee]);
          /* printf("Je pars à %i\n", depart); */
          depart = find_same_way(i, depart, arrivee, nod);
          /* printf("J'arrive à %i\n\n", depart); */
        }
    }
  chemin[j++] = depart;
  chemin[j] = -1;
  return (chemin);
}
