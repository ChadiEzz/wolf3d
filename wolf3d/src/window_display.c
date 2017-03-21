/*
** window_display.c for window_display.c in /home/c.ezzedine/delivery/wolf3d/src
**
** Made by Chadi EZZEDINE
** Login   <c.ezzedine@epitech.net>
**
** Started on  Tue Jan 10 15:07:29 2017 Chadi EZZEDINE
** Last update Mon Jan 23 17:47:33 2017 Ezzedine Chadi
*/

#include "../my.h"

void    moving(sfVector2f *pos, float *direction, char **map)
{
	t_init	init;
	if (sfKeyboard_isKeyPressed(sfKeyRight))
	*direction += 0.5;
	if (sfKeyboard_isKeyPressed(sfKeyLeft))
	*direction -= 0.5;
	if (sfKeyboard_isKeyPressed(sfKeyUp))
	*pos = moveforward(*pos, *direction, 0.01, map);
	if (sfKeyboard_isKeyPressed(sfKeyDown))
	*pos = moveforward(*pos, *direction, -0.01, map);
	else if (sfKeyboard_isKeyPressed(sfKeySpace))
		{
		  pos->x = 3;
		  pos->y = 1.5;
		  *direction = 90;
		}
}

t_init    init_window()
{
	t_init	init;

	init.mode.width = SCREEN_WIDTH;
	init.mode.height = SCREEN_HEIGHT;
	init.mamen = sfMusic_createFromFile("Nyan_Cat.ogg");
	init.window = sfRenderWindow_create(init.mode,
		"Wolf3D", sfResize | sfClose, NULL);
	init.framebuffer = my_framebuffer_create();
	init.sprite = sfSprite_create();
	init.texture = sfTexture_create(SCREEN_WIDTH, SCREEN_HEIGHT);
	sfSprite_setTexture(init.sprite, init.texture, sfTrue);
	return (init);
}

int			window_display(char **map,
				       sfVector2i mapSize,
				       sfVector2f pos, float direction)
{
  t_init	init;

  init = init_window();
  sfMusic_play(init.mamen);
  sfMusic_setLoop(init.mamen, sfTrue);
  while (sfRenderWindow_isOpen(init.window))
    {
      sfRenderWindow_clear(init.window, sfBlack);
      draw_environement(init.framebuffer);
      my_draw_environment(init.framebuffer, pos, direction, map);
      sfTexture_updateFromPixels(init.texture, init.framebuffer->pixels,
				 SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
      sfRenderWindow_drawSprite(init.window, init.sprite, NULL);
			moving(&pos, &direction, map);
      while (sfRenderWindow_pollEvent(init.window, &init.event))
	{
	  if (init.event.type == sfEvtClosed)
	    {
	      free(init.framebuffer);
	      sfRenderWindow_close(init.window);
	    }
	}
      sfRenderWindow_display(init.window);
    }
  sfRenderWindow_destroy(init.window);
  sfMusic_destroy(init.mamen);
  return (0);
}
