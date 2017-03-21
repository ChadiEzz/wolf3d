##
## Makefile for Makefile in /home/c.ezzedine/delivery/wolf3d
## 
## Made by Chadi EZZEDINE
## Login   <c.ezzedine@epitech.net>
## 
## Started on  Thu Jan 12 17:22:10 2017 Chadi EZZEDINE
## Last update Fri Jan 20 12:09:07 2017 Ezzedine Chadi
##

CC	=	gcc

SRCS	=	src/*.c

OBJ	=	$(SRCS:.c=.o)

LIB	=	-lcsfml-audio -lcsfml-graphics -lcsfml-window -lcsfml-system -lm

RM	=	rm -rf

NAME	=	wolf3d

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(SRCS) $(CFLAGS) $(LIB) -o $(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
