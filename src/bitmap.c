/*
** bitmap.c for gfx_tekadventure in /home/puilla_e/Semestre2/infographie/
**
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
**
** Started on  Thu Mar 31 14:46:56 2016 edouard puillandre
** Last update Sun Apr 17 22:27:41 2016 Voyevoda
*/

#include "adventure.h"

t_bunny_pixelarray	*fill_bitmap(unsigned int *file, t_infoheader *buffer2)
{
  t_bunny_pixelarray	*bitmap;
  unsigned int		i;
  unsigned int 		j;
  unsigned int		width;
  t_color		*color;
  char			mem;

  width = buffer2->width;
  if ((bitmap = bunny_new_pixelarray(buffer2->width, buffer2->height)) == NULL)
    return (NULL);
  color = bitmap->pixels;
  i = 0;
  while (i < (buffer2->width * buffer2->height))
    {
      j = i % width + (buffer2->height - 1 - (i / width))  * width;
      color[j].full = file[i];
      mem = color[j].argb[0];
      color[j].argb[0] = color[j].argb[2];
      color[j].argb[2] = mem;
      color[j].argb[3] = 255;
      i++;
    }
  return (bitmap);
}

t_bunny_pixelarray	*load_bitmap(char *filepath)
{
  int			fd;
  t_header		*buffer;
  t_infoheader		*buffer2;
  unsigned int		*file;
  t_bunny_pixelarray	*bitmap;

  if ((buffer = bunny_malloc(14)) == NULL ||
      (buffer2 = bunny_malloc(40)) == NULL ||
      (fd = open(filepath, O_RDONLY)) == -1 ||
      (read(fd, buffer, 14)) < 0 ||
      (read(fd, buffer2, 40)) < 0)
    return (NULL);
  file = bunny_malloc(sizeof(*file) * (buffer2->width * buffer2->height));
  if (file == NULL || (read(fd, file, buffer->size_file)) < 0 ||
      (bitmap = fill_bitmap(file, buffer2)) == NULL)
    return (NULL);
  bunny_free(file);
  bunny_free(buffer);
  bunny_free(buffer2);
  close(fd);
  return (bitmap);
}
