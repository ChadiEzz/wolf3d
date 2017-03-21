/*
** game_execution.c for game_execution.c in /home/c.ezzedine/delivery/wolf3d/src
** 
** Made by Chadi EZZEDINE
** Login   <c.ezzedine@epitech.net>
** 
** Started on  Tue Jan 10 13:53:46 2017 Chadi EZZEDINE
** Last update Sat Jan 14 22:59:57 2017 Chadi EZZEDINE
*/

#include "../my.h"

int			game_execution(char *av)
{
  char			*tab;
  char			**map;
  sfVector2f		P1;
  //int			y_map;
  int			i;
  float			direction;
  sfVector2i		mapSize;

  tab = malloc(sizeof(char) * 20001);
  i = my_open_read("map", tab);
  if (i == 84)
    return (84);
  mapSize.x = SCREEN_WIDTH;
  mapSize.y = SCREEN_HEIGHT;
  map = tab_malloc(tab);
  my_str_to_wordtab(map, tab);
  P1.x = 3;
  P1.y = 1.5;
  direction = 90.;
  window_display(map, mapSize, P1, direction);
  free(tab);
  free(map);
  return (0);
}
