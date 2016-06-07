
#include		<lapin.h>
#include		<unistd.h>

static size_t		dstrlen(const char	*str)
{
  const char		*s = str;

  while (*str++);
  return (str - s);
}

int			main(void)
{
  const char		*str;
  t_bunny_ini		*ini;
  t_bunny_ini_scope	*scope;
  int			i;

  i = 0;
  if ((ini = bunny_load_ini("blob.ini")) == NULL)
    return (EXIT_FAILURE);
  while ((str = bunny_ini_get_field(ini, "section", "field", i++)) != NULL)
    {
      write(1, str, dstrlen(str));
      write(1, "\n", 1);
    }
  write(1, "\n", 1);
  for (scope = bunny_ini_first(ini); scope != LAST_SCOPE; scope = bunny_ini_next(ini, scope))
    {
      write(1, bunny_ini_scope_name(ini, scope), dstrlen(bunny_ini_scope_name(ini, scope)));
      write(1, "\n", 1);
    }

  write(1, "Dumping : \n", 11);
  bunny_save_ini(ini, "/dev/stdout");

  bunny_delete_ini(ini);
  return (EXIT_SUCCESS);
}
