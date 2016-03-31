/*
** adventure.h for gfx_tekadventure in /home/puilla_e/Semestre2/infographie/
**
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
**
** Started on  Tue Mar 29 16:51:22 2016 edouard puillandre
** Last update Thu Mar 31 14:51:49 2016 edouard puillandre
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
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
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

typedef struct s_header
{
  unsigned short int	magic_number;
  unsigned int		size_file;
  unsigned int		reserved;
  unsigned int		offset;
} __attribute__((packed)) t_header;

typedef struct s_infoheader
{
  unsigned int		size_header;
  unsigned int		width;
  unsigned int	       	height;
  unsigned short int	planes;
  unsigned short int	bits;
  unsigned int		compression;
  unsigned int		imagesize;
  unsigned int	       	xresolution;
  unsigned int	       	yresolution;
  unsigned int		ncolours;
  unsigned int		importantcolours;
} __attribute__((packed)) t_infoheader;

t_bunny_response	my_fct_free(t_data *data, int error_true);
t_data			*my_init_data();
t_bunny_pixelarray	*load_bitmap(char *filepath);

#endif /* !ADVENTURE_H_ */
