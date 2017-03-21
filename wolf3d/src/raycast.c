/*
** raycast.c for raycast.c in /home/c.ezzedine/delivery/wolf3d/src
**
** Made by Chadi EZZEDINE
** Login   <c.ezzedine@epitech.net>
**
** Started on  Tue Jan  3 10:06:37 2017 Chadi EZZEDINE
** Last update Mon Jan 23 15:29:46 2017 Ezzedine Chadi
*/

#include "../my.h"

float		raycast(sfVector2f pos,
			float direction, char **map,
			sfVector2i mapSize)
{
  float		k;
  float		x;
  float		y;
  float		co;
  float		si;
  k = 0;
  x = pos.x;
  y = pos.y;
  co = cosf((direction * M_PI)/180);
  si = sinf((direction * M_PI)/180);
  while ((x >= 0 && y >= 0) &&
	 ((int)x < mapSize.x &&
	  (int)y < mapSize.y) && map[(int)y][(int)x] != '1')
    {
      k += 0.01;
      x = pos.x + (k * co);
      y = pos.y + (k * si);
    }
  return (k);
}
