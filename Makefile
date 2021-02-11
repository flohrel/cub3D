###############
## Variables ##
###############

NAME		=	cub3D

VPATH		=	src src/hook src/engine
OBJDIR		=	obj
LIBDIR		=	libft
INCLDIR		=	incld

SRC			=	main.c \
				raycaster.c \
				cam_move.c \
				cam_move2.c \
				map.c \
				img_utils.c
LIB			=	libft.a
OBJ			=	$(SRC:%.c=$(OBJDIR)/%.o)

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
INCFLAGS	=	-I./$(INCLDIR)
LFLAGS		=	-L./$(LIBDIR) -lft
RM			=	/bin/rm -rf
UNAME		:=	$(shell uname -s)

ifeq ($(UNAME),Linux)
	INCFLAGS += -I/usr/include -Imlx-linux -O3
	LFLAGS += -Lmlx_Linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
endif
ifeq ($(UNAME),Darwin)
	INCFLAGS += -Imlx
	LFLAGS += -framework OpenGL -framework AppKit
endif


###########
## Rules ##
###########

.PHONY:			all bonus clean fclean re

all:			$(NAME)

$(OBJDIR)/%.o:	%.c | $(OBJDIR)
				$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

$(NAME):		$(OBJ)
				make -C $(LIBDIR)
				$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

$(OBJDIR):
				mkdir $(OBJDIR)

bonus:
				@make all

clean:
				$(RM) $(OBJ)

fclean:			clean
				$(RM) $(NAME) $(OBJDIR)

re:				fclean all
