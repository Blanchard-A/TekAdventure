/*
** adventure.h for gfx_tekadventure in /home/puilla_e/Semestre2/infographie/
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Tue Mar 29 16:51:22 2016 edouard puillandre
** Last update Tue Mar 29 16:51:57 2016 edouard puillandre
*/

#ifndef ADVENTURE_H_
# define ADVENTURE_H_

# define WIN_X (1280)
# define WIN_Y (1024)
# define INIT_COLOR (0x00000000)
# define WIN_NAME "Window"
# define PIX_X (0)
# define PIX_Y (0)

# include <stdlib.h>
# include <lapin.h>
# include <math.h>
# include <unistd.h>

typedef	struct		s_data
{
  t_bunny_window       	*win;
  t_bunny_position	*pos;
  t_bunny_pixelarray	*pix;
  t_bunny_position	*mouse;
}			t_data;

t_bunny_response	my_fct_free(t_data *data, int error_true);
t_data			*my_init_data();

#endif /* !ADVENTURE_H_ */
