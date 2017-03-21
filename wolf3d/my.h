/*
** my.h for my.h in /home/c.ezzedine/delivery/wolf3d
**
** Made by Chadi EZZEDINE
** Login   <c.ezzedine@epitech.net>
**
** Started on  Tue Jan  3 10:29:37 2017 Chadi EZZEDINE
** Last update Mon Jan 23 17:47:01 2017 Ezzedine Chadi
*/

#ifndef MY_H_
# define MY_H_

#include <SFML/Graphics/RenderWindow.h>
#include <stdlib.h>
#include <unistd.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <SFML/Window/Export.h>
#include <math.h>
#include <SFML/Audio.h>

#define SCREEN_WIDTH  800
#define SCREEN_HEIGHT 600

typedef	struct        s_my_framebuffer
{
  sfUint8		          *pixels;
  int			            width;
  int			            height;
}			                t_my_framebuffer;

typedef	struct        s_init
{
  sfVideoMode		      mode;
  sfRenderWindow	    *window;
  sfEvent		          event;
  sfSprite		        *sprite;
  t_my_framebuffer	  *framebuffer;
  sfTexture		        *texture;
  sfMusic             *mamen;
}                     t_init;

void			            my_put_pixel(t_my_framebuffer *, int, int, sfColor);
void			            my_draw_line(t_my_framebuffer *, sfVector2i,
   sfVector2i, sfColor);
sfVector2f		        move_forward(sfVector2f, float, float);
float			            raycast(sfVector2f, float, char **, sfVector2i);
int			              my_strlen(char *);
char			            **tab_malloc(char *);
char			            **my_str_to_wordtab(char **, char *);
void			            my_draw_environment(t_my_framebuffer *,
   sfVector2f, float, char **);
void			            draw_environement(t_my_framebuffer *);
t_my_framebuffer	    *my_framebuffer_create();
int			              game_execution(char *);
int			              my_open_read(char *, char *);
int			              window_display(char **, sfVector2i, sfVector2f, float);
sfVector2f		        moveforward(sfVector2f pos, float direction,
   float distance, char **map);

#endif /* !MY_H_ */
