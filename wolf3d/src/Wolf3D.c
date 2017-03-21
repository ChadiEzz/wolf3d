/*
** Wolf3D.c for Wolf3D.c in /home/c.ezzedine/delivery/wolf3d
** 
** Made by Chadi EZZEDINE
** Login   <c.ezzedine@epitech.net>
** 
** Started on  Tue Jan 10 13:21:31 2017 Chadi EZZEDINE
** Last update Fri Jan 13 16:39:19 2017 Chadi EZZEDINE
*/

#include "../my.h"

t_my_framebuffer		*my_framebuffer_create()
{
  int				i;
  t_my_framebuffer		*buff;

  buff = malloc(sizeof(t_my_framebuffer));
  buff->pixels = malloc(SCREEN_WIDTH * SCREEN_HEIGHT * 4 * sizeof(int));
  buff->width = SCREEN_WIDTH;
  buff->height = SCREEN_HEIGHT;
  if (buff->pixels == NULL)
    {
      return (NULL);
    }
  i = 0;
  while (i < SCREEN_WIDTH * SCREEN_HEIGHT * 4)
    {
      buff->pixels[i] = 0;
      i = i + 1;
    }
  return (buff);
}

int				main(int argc, char **argv)
{
  game_execution(argv[1]);
  return (0);
}
