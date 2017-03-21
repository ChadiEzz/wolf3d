/*
** my_put_pixel.c for my_put_pixel.c in /home/c.ezzedine/delivery/wireframe
** 
** Made by Chadi EZZEDINE
** Login   <c.ezzedine@epitech.net>
** 
** Started on  Sun Dec 11 22:53:20 2016 Chadi EZZEDINE
** Last update Fri Jan 13 13:25:44 2017 Chadi EZZEDINE
*/

#include "../my.h"

void                    my_put_pixel(t_my_framebuffer *framebuffer,
				       int x, int y, sfColor color)
{
if (x < framebuffer->width && x >= 0 &&
      y < framebuffer->height && y >= 0)
   {
framebuffer->pixels[(SCREEN_WIDTH * y + x) * 4 + 0] = color.r;
framebuffer->pixels[(SCREEN_WIDTH * y + x) * 4 + 1] = color.g;
framebuffer->pixels[(SCREEN_WIDTH * y + x) * 4 + 2] = color.b;
framebuffer->pixels[(SCREEN_WIDTH * y + x) * 4 + 3] = color.a;
   }
}
