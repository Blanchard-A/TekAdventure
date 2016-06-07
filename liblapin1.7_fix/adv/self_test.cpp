// Jason Brillante "Damdoshi"
// Epitech 1999-2042
//
// Lapin library

#include		<unistd.h>
#include		<signal.h>
#include		"lapin_private.h"

void			bunny_self_test(void)
{
  // Do things
  kill(getpid(), SIGINT);
}
