/*
** my_getnbr.c for gfx_tekadventure in /home/puilla_e/Semestre2/infographie/rendu/gfx_tekadventure
**
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
**
** Started on  Sun Apr 17 22:36:03 2016 edouard puillandre
** Last update Sun Apr 17 22:38:36 2016 edouard puillandre
*/

int	my_neg_number(const char *str)
{
  int	i;
  int	var_neg;

  i = 0;
  var_neg = 1;
  while (str[i] != '\0')
    {
      if (str[i] == '-')
	{
	  var_neg = var_neg * - 1;
	}
      else if (str[i] != '+' && str[i] != 32)
	{
	  return (var_neg);
	}
      i = i + 1;
    }
  return (var_neg);
}

int	my_check_nb(const char *str, int nb, int i, int nb_true)
{
  if (str[i] < 48 || str[i] > 57)
    {
      if (str[i] == 32 && nb_true == 0)
	{
	  return (0);
	}
      else if (((str[i] < 48 || str[i] > 57) && str[i] != '+' && str[i] != '-')
	       || (nb_true == 1 && (str[i] == '+' || str[i] == '-')))
	{
	  return (1);
	}
    }
  else
    {
      if ((nb == 214748364 && str[i] - 48 > (15 - my_neg_number(str)) / 2)
	  || nb >= 214748365)
	{
	  return (1);
	}
    }
  return (0);
}

int	my_getnbr(const char *str)
{
  int	nb;
  int	i;
  int	nb_true;

  i = 0;
  nb = 0;
  nb_true = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 48 && str[i] <= 57)
	{
	  if (my_check_nb(str, nb, i, nb_true) == 1)
	    {
	      return (0);
	    }
	  nb = nb * 10 + str[i] - 48;
	  nb_true = 1;
	}
      else if (my_check_nb(str, nb, i, nb_true) == 1)
	{
	  return (nb * my_neg_number(str));
	}
      i = i + 1;
    }
  return (nb * my_neg_number(str));
}
