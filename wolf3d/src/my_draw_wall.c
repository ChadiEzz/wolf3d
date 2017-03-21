/*
** my_draw_wall.c for my_draw_wall.c in /home/c.ezzedine/delivery/wolf3d/src
**
** Made by Chadi EZZEDINE
** Login   <c.ezzedine@epitech.net>
**
** Started on  Tue Jan 10 17:05:19 2017 Chadi EZZEDINE
** Last update Mon Jan 23 17:13:31 2017 Ezzedine Chadi
*/

#include "../my.h"

void		draw_environement(t_my_framebuffer *framebuffer)
{
  int	i;
  unsigned int *pixel;

  i = 0;
  while (i < SCREEN_HEIGHT * SCREEN_WIDTH * 2.5)
    {
      pixel = (void*) &framebuffer->pixels[i];
      *pixel = *(int*)(void*)&(sfColor){251, 192, 93, 255};
      i += 4;
    }
  while (i >= SCREEN_HEIGHT * SCREEN_WIDTH * 2.5 &&
	 i <= SCREEN_HEIGHT * SCREEN_WIDTH * 4)
    {
      pixel = (void*) &framebuffer->pixels[i];
      *pixel = *(int*)(void*)&(sfColor){128, 0, 0, 255};
      i += 4;
    }
  while (i < SCREEN_HEIGHT * SCREEN_WIDTH * 4)
    {
      framebuffer->pixels[i] = 0;
      i += 4;
    }
}

void			my_draw_wall(float raycast,
				     sfVector2f *wall_from,
				     sfVector2f *wall_to)
{
  wall_from->y = (SCREEN_WIDTH / 2.) -
    ((((SCREEN_HEIGHT / 2.) / tanf (30 * M_PI / 180)) / raycast) / 2.);
  wall_to->y = (SCREEN_WIDTH / 2.) +
    ((((SCREEN_HEIGHT / 2.) / tanf (30 * M_PI / 180)) / raycast) / 2.);
}

void			norme(sfVector2f wall_from,
			      sfVector2f wall_to,
			      t_my_framebuffer *framebuffer)
{
  sfColor		wall;
  sfVector2i		wall_from2;
  sfVector2i		wall_to2;
  wall.a = 255;
  wall.r = 128;
  wall.g = 128;
  wall.b = 128;
  wall_from2.x = (int)wall_from.x;
  wall_from2.y = (int)wall_from.y;
  wall_to2.x = (int)wall_to.x;
  wall_to2.y = (int)wall_to.y;
  my_draw_line(framebuffer, wall_from2, wall_to2, wall);
}

void			my_draw_environment(t_my_framebuffer *framebuffer,
					    sfVector2f pos, float direction,
					    char **map)
{
  sfVector2f		wall_from;
  sfVector2f		wall_to;
  sfVector2i		mapSize;
  float			dist;
  float			angle;
  float			correction;
  int			i;

  i = -1;
  mapSize.x = 11;
  mapSize.y = 5;
  angle = direction - 30.;
  wall_from.x = -1.;
  wall_to.x = -1.;
  while (++i < SCREEN_WIDTH)
    {
      wall_from.x += 1.;
      wall_to.x += 1.;
      dist = raycast(pos, angle, map, mapSize);
      dist = (float)((double)dist *
		     cosf(M_PI * ((double)direction - (double)angle) / 180));
      angle += 60. / SCREEN_WIDTH;
      my_draw_wall(dist, &wall_from, &wall_to);
      norme(wall_from, wall_to, framebuffer);
    }
}
