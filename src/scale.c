/*
** scale.c for tekadv in /home/blanch_p/rendu/Infographie/gfx_tekadventure
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Thu Apr  7 12:17:28 2016 Alexandre Blanchard
** Last update Thu Apr  7 12:17:58 2016 Alexandre Blanchard
*/

void		reduit_taille(t_data *data)
{
  int		i;
  /* int                j; */
  t_bunny_position	pos;

  /* j = 0; */
  i = 0;
  pos.x = 0;
  pos.y = 0;
  while (i < data->perso->clipable.clip_width *
         data->perso->clipable.clip_height)
    {
      if (i % 2 == 0 && i / data->perso->clipable.clip_width % 2 == 0)
        {
          tekpixel(data->test, &pos, ((unsigned int *)data->perso->pixels)[i]);
          pos.x++;
          if (pos.x > data->test->clipable.clip_width)
            {
              pos.y++;
              pos.x = 0;
            }
          /* nw_tekpixel(data->test, j, ((unsigned int *)data->perso->pixels)[i\
	     ]); */
          /*           j++; */
        }
      i++;
    }
  printf("taille originale %i\n", data->perso->clipable.clip_width);
  printf("taille originale %i\n", data->perso->clipable.clip_height);

  printf("taille originale %i\n", data->test->clipable.clip_width);
  printf("taille originale %i\n", data->test->clipable.clip_height);
}
