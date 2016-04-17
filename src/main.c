/*
** main.c for gfx_tekadventure in /home/puilla_e/Semestre2/infographie/
**
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
**
** Started on  Tue Mar 29 16:50:38 2016 edouard puillandre
** Last update Sun Apr 17 15:15:50 2016 edouard puillandre
*/

#include "adventure.h"

#include <stdio.h>

t_bunny_response	mainloop(t_data *data)
{
  /* load_decor_1(data);   */
  /* data->id_plan = 0; */
  /* envoi_to_copy(data); */
  if (data->player->coef[0] == 0 && data->player->coef[1] == 0)
    {
      to_next_node(data);

    }
  if (data->player->coef[0] != 0 && data->player->coef[1] != 0)
    {
      move_perso(data);
    }
  if (data->id_plan == 0)
    {
      change_pos(data);
      change_pos_nuages(data);
      have_pos(data);
    }
  envoi_to_copy(data);


  /* printf("ok\n"); */
  /* have_pos(data); */
  change_pos_perso(data->player->mov[CUR]->calque[0]->pix, data->loop);
  bunny_blit(&data->win->buffer, &data->pix->clipable, data->pos);
  /* data->loop++; */
  /* if (data->loop == 12) */
  /*   data->loop = 0; */
  /* bunny_blit(&data->win->buffer, */
  /* 	     &data->player->mov[0]->calque[0]->pix->clipable, data->pos); */
  bunny_display(data->win);
  /* return (0); */
  return (GO_ON);
}

t_bunny_response	escape(t_bunny_event_state	state,
			       t_bunny_keysym		key,
			       t_data			*data)
{
  if (state == GO_UP && key == BKS_ESCAPE)
    return (my_fct_free(data, 0));
  return (GO_ON);
}

t_bunny_response	click(t_bunny_event_state	state,
			      t_bunny_mousebutton     	key,
			      t_data			*data)
{
  /* const t_bunny_position	*pos; */

  (void) data;
  (void) state;
  (void) key;

  /* pos = bunny_get_mouse_position(); */

  if (state == GO_DOWN)
    {
      /* calc_coef(data->player->mov[0]->calque[0]->x, */
      /* 		data->player->mov[0]->calque[0]->y, */
      /* 		data->mouse, */
      /* 		data); */

      my_go(data);

      /* move_perso(data); */

      /* printf("YEAH\n"); */
      check_click_bis(data);
      /* check_click(data); */
      /* pos = bunny_get_mouse_position(); */
      /* printf("x = %i\ty = %i\n", data->mouse->x, data->mouse->y); */
      /* if (data->id_plan == 0) */
      /* 	{ */
      /* 	  free_calque(data); */

      /* 	  data->id_plan = 1; */
      /* 	  if (load_decor_2(data) == NULL) */
      /* 	    return (0); */
      /* 	  return (GO_ON); */
      /* 	} */
      /* if (data->id_plan == 1) */
      /* 	{ */
      /* 	  free_calque(data); */
      /* 	  data->id_plan = 0; */
      /* 	  if (load_decor_1(data) == NULL) */
      /* 	    return (0); */
      /* 	  return (GO_ON); */
      /* 	} */
    }
  return (GO_ON);
}

t_bunny_response	move(const t_bunny_position	*relative,
			     t_data			*data)
{
  (void) data;
  (void) relative;
  return (GO_ON);
}

int	main(int ac, char **av, char **env)
{
  t_data	*data;

  (void) ac;
  (void) av;
#ifdef	DEBUG
  memory_check = 1;
#endif
  if (*env == NULL)
    return (1);
  if ((data = my_init_data()) == NULL)
    return (1);
  my_init_board();
  bunny_set_loop_main_function((t_bunny_loop)mainloop);
  bunny_set_key_response((t_bunny_key)escape);
  bunny_set_move_response((t_bunny_move)move);
  bunny_set_click_response((t_bunny_click)click);
  if (bunny_loop(data->win, 90, data) == EXIT_ON_ERROR)
    return (1);
#ifdef	DEBUG
  write(1, "STATUS: OK\n", 11);
#endif
  return (0);
}
