/*
** init_board.c for tekadventure.h in /home/puilla_e/Semestre2/infographie/
**
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
**
** Started on  Sat Apr 16 10:16:07 2016 edouard puillandre
** Last update Sun Apr 17 21:30:46 2016 edouard puillandre
*/

#include "adventure.h"

void	def_pos_button(t_button **button)
{
  button[ID_USE]->pos.x = X_USE;
  button[ID_USE]->pos.y = Y_USE;
  button[ID_GO]->pos.x = X_GO;
  button[ID_GO]->pos.y = Y_GO;
  button[ID_PICK]->pos.x = X_PICK;
  button[ID_PICK]->pos.y = Y_PICK;
  button[ID_GIVE]->pos.x = X_GIVE;
  button[ID_GIVE]->pos.y = Y_GIVE;
  button[ID_TALK]->pos.x = X_TALK;
  button[ID_TALK]->pos.y = Y_TALK;
  button[ID_LOOK]->pos.x = X_LOOK;
  button[ID_LOOK]->pos.y = Y_LOOK;
}

int	init_button(t_button **button)
{
  int	i;

  i = - 1;
  while (++i < NB_BUTTON)
    if ((button[i] = bunny_malloc(sizeof(*button[i]))) == NULL)
      return (- 1);
  button[i] = NULL;
  def_pos_button(button);
  button[ID_USE]->fct = &(my_use);
  button[ID_GO]->fct = &(my_go);
  button[ID_PICK]->fct = &(my_pick);
  button[ID_GIVE]->fct = &(my_give);
  button[ID_TALK]->fct = &(my_talk);
  button[ID_LOOK]->fct = &(my_look);
  return (0);
}

int	init_obj(t_obj **obj)
{
  int	i;

  i = - 1;
  while (++i < NB_OBJ)
    {
      if ((obj[i] = bunny_malloc(sizeof(*obj[i]))) == NULL ||
	  (obj[i]->calque = bunny_malloc(sizeof(*obj[i]->calque))) == NULL)
	return (- 1);
      obj[i]->calque->x = X_OBJ + (i % (NB_OBJ / 2)) * (OBJ_WIDTH + OBJ_STEP);
      obj[i]->calque->y = Y_OBJ + (i / (NB_OBJ / 2)) * (OBJ_HEIGHT + OBJ_STEP);
      obj[i]->name = NULL;
      obj[i]->desc = NULL;
      obj[i]->close = 0;
    }
  obj[i] = NULL;
  return (0);
}

t_board		*my_init_board()
{
  t_board	*board;

  if ((board = bunny_malloc(sizeof(*board))) == NULL ||
      (board->button =
       bunny_malloc(sizeof(*board->button) * (NB_BUTTON + 1))) == NULL ||
      (board->obj =
       bunny_malloc(sizeof(*board->obj) * (NB_OBJ + 1))) == NULL ||
      init_button(board->button) == - 1 || init_obj(board->obj) == - 1 ||
      (board->calque = bunny_malloc(sizeof(*board->calque))) == NULL ||
      (board->calque->pix = load_bitmap(BOARD_BMP)) == NULL)
    return (NULL);
  board->calque->x_speed = 0;
  board->calque->y_speed = 0;
  board->calque->x_init = 0;
  board->calque->y_init = 0;
  board->calque->x = 0;
  board->calque->y = 720;
  board->calque->scale = 100;
  board->sel = ID_GO;
  return (board);
}

void	my_free_board(t_board *board)
{
  int	i;

  i = - 1;
  while (board->button[++i] != NULL)
    bunny_free(board->button[i]);
  i = - 1;
  while (board->obj[++i] != NULL)
    {
      bunny_free(board->obj[i]->calque);
      bunny_free(board->obj[i]);
    }
  bunny_delete_clipable(&board->calque->pix->clipable);
  bunny_free(board->calque);
  bunny_free(board->button);
  bunny_free(board->obj);
  bunny_free(board);
}
