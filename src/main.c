/*
** main.c for gfx_tekadventure in /home/puilla_e/Semestre2/infographie/
**
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
**
** Started on  Tue Mar 29 16:50:38 2016 edouard puillandre
** Last update Sun Apr 17 22:57:23 2016 Voyevoda
*/

#include "adventure.h"

t_bunny_response	mainloop(t_data *data)
{
  if (data->player->coef[0] == 0 && data->player->coef[1] == 0)
    to_next_node(data);
  if (data->player->coef[0] != 0 && data->player->coef[1] != 0)
    move_perso(data);
  if (data->id_plan == 0)
    {
      change_pos(data);
      change_pos_nuages(data);
      have_pos(data);
    }
  else if (data->id_plan == 1)
    move_poteau(data);
  envoi_to_copy(data);
  tektext(data->pix, data->text);
  change_pos_perso(data->player->mov[CUR]->calque[0]->pix, data->loop);
  bunny_blit(&data->win->buffer, &data->pix->clipable, data->pos);
  bunny_display(data->win);
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
  (void) data;
  (void) state;
  (void) key;

  if (state == GO_DOWN)
    {
      my_go(data);
      check_click_bis(data);
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
