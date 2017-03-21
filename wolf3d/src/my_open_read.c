/*
** my_open_read.c for my_open_read.c in /home/c.ezzedine/delivery/PSU_2016_my_popup
** 
** Made by Chadi EZZEDINE
** Login   <c.ezzedine@epitech.net>
** 
** Started on  Tue Dec 13 10:09:33 2016 Chadi EZZEDINE
** Last update Thu Jan 12 13:59:39 2017 Chadi EZZEDINE
*/

#include "../my.h"

int		my_open_read(char *filepath, char *map)
{
  int		op;

  op = open(filepath, O_RDONLY);
  if (op <= 0)
    return (84);
  else
    read(op, map, 10000);
  return (0);
}
