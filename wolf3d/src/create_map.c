/*
** create_map.c for create_map.c in /home/c.ezzedine/delivery/wolf3d
**
** Made by Chadi EZZEDINE
** Login   <c.ezzedine@epitech.net>
**
** Started on  Tue Jan 10 13:40:42 2017 Chadi EZZEDINE
** Last update Mon Jan 23 15:19:22 2017 Ezzedine Chadi
*/

#include "../my.h"

int		my_strlen(char *tab)
{
  int		i;

  i = 0;
  while (tab[i] != '\n' && tab[i] != '\0')
    i = i + 1;
  return (i);
}

char		**tab_malloc(char *tab)
{
  char		**map;
  int		i;
  int		i2;
  int		countt;

  i = 0;
  countt = 1;
  while (tab[i] != '\0')
    {
      if (tab[i] == '\n')
	countt = countt + 1;
      i = i + 1;
    }
  map = malloc(sizeof(char *) * (countt + 1));
  map[countt] = NULL;
  i2 = 0;
  i = 0;
  while (i2 != countt)
    {
      map[i2] = malloc(sizeof(char) * (my_strlen(tab + i) + 2));
      i = i + my_strlen(tab + i) + 1;
      i2 = i2 + 1;
    }
  return (map);
}

char		**my_str_to_wordtab(char **map, char *tab)
{
  int		i;
  int		j;
  int		k;

  i = 0;
  j = 0;
  while (tab[i] != '\0')
    {
      k = 0;
      while (tab[i] != '\n' && tab[i] != '\0')
	{
	  map[j][k] = tab[i];
	  i = i + 1;
	  k = k + 1;
	}
      map[j][k] = '\n';
      map[j][k + 1] = '\0';
      if (tab[i] != '\0')
	i = i + 1;
      j = j + 1;
    }
  return (map);
}
