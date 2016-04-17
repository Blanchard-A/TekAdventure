/*
** string.c for gfx_tekadventure in /home/puilla_e/Semestre2/infographie/
**
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
**
** Started on  Sun Apr 17 19:49:02 2016 edouard puillandre
** Last update Sun Apr 17 19:57:19 2016 edouard puillandre
*/

#include "adventure.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}

char	*my_strcpy(char *str)
{
  char	*ptr;
  int	i;

  i = - 1;
  if ((ptr = bunny_malloc(my_strlen(str) + 1)) == NULL)
    return (NULL);
  while (str[++i] != '\0')
    ptr[i] = str[i];
  ptr[i] = '\0';
  return (ptr);
}
