/*
** moveforward.c for moveforward.c in /home/c.ezzedine/delivery/wolf3d/src
** 
** Made by Chadi EZZEDINE
** Login   <c.ezzedine@epitech.net>
** 
** Started on  Sun Jan 15 17:28:53 2017 Chadi EZZEDINE
** Last update Sun Jan 15 17:51:09 2017 Chadi EZZEDINE
*/

#include "../my.h"

sfVector2f		moveforward(sfVector2f pos,
				    float direction,
				    float distance, char **map)
{
  float			y;
  float			x;

  y = pos.y;
  x = pos.x;
  if (map[(int)(y + distance)][(int)(x + distance)] != '1')
    {
      pos.x = pos.x + (distance * cosf((M_PI * direction)/180));
      pos.y = pos.y + (distance * sinf((M_PI * direction)/180));
      x = pos.x;
      y = pos.y;
    }
  return (pos);
}
