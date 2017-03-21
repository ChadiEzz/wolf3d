/*
** move_forward.c for move_forward.c in /home/c.ezzedine/delivery/wolf3d/src
** 
** Made by Chadi EZZEDINE
** Login   <c.ezzedine@epitech.net>
** 
** Started on  Tue Jan  3 09:56:20 2017 Chadi EZZEDINE
** Last update Sun Jan 15 17:30:40 2017 Chadi EZZEDINE
*/

#include "../my.h"

sfVector2f		move_forward(sfVector2f pos,
				     float direction, float distance)
{
  pos.x = pos.x + (distance * cosf((M_PI * direction)/180));
  pos.y = pos.y + (distance * sinf((M_PI * direction)/180));
  return (pos);
}
