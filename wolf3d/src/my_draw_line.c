/*
** my_draw_line.c for my_draw_line.c in /home/c.ezzedine/delivery/wireframe
**
** Made by Chadi EZZEDINE
** Login   <c.ezzedine@epitech.net>
**
** Started on  Sun Dec 11 22:54:48 2016 Chadi EZZEDINE
** Last update Mon Jan 23 17:23:53 2017 Ezzedine Chadi
*/

#include "../my.h"

void			my_draw_line(t_my_framebuffer *framebuffer,
				     sfVector2i from,
				     sfVector2i to, sfColor color)
{
  int			dx;
  int			sx;
  int			dy;
  int			sy;
  int			err;
  int			err2;

  dx = abs(to.x - from.x);
  sx = from.x < to.x ? 1 : -1;
  dy = abs(to.y - from.y);
  sy = from.y < to.y ? 1 : -1;
  err = dx > dy ? dx : -dy;
  err = err / 2;
  while (from.y != to.y)
    {
      my_put_pixel(framebuffer, from.x, from.y, color);
      err2 = err;
      if (err2 > -dx)
	{
	  err = err - dy;
	  from.x = from.x + sx;
	}
      else if (err2 < dx)
	{
	  err = err + dx;
	  from.y = from.y + sy;
	}
    }
}
