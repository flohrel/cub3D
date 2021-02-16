###############
## Variables ##
###############

NAME		=	cub3D

VPATH		=	src src/hook src/engine
OBJDIR		=	obj
LIBDIR		=	lib
INCLDIR		=	incld

SRC			=	main.c \
				raycaster.c \
				raycaster2.c \
				cam_move.c \
				cam_move2.c \
				map.c \
				flag.c \
				keyboard.c \
				img_utils.c
LIB			=	libft.a
OBJ			=	$(SRC:%.c=$(OBJDIR)/%.o)

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
INCFLAGS	=	-I$(INCLDIR)
LFLAGS		=	-L$(LIBDIR)/libft -lft
RM			=	/bin/rm -rf
UNAME		:=	$(shell uname -s)

ifeq ($(UNAME),Linux)
	INCFLAGS += -I/usr/include -Imlx-linux -O3
	LFLAGS += -L$(LIBDIR)/mlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
endif
ifeq ($(UNAME),Darwin)
	INCFLAGS += -I$(LIBDIR)/mlx
	LFLAGS += -l$(LIBDIR)/mlx -framework OpenGL -framework AppKit
endif


###########
## Rules ##
###########

.PHONY:			all bonus clean fclean re

all:			$(NAME)

$(OBJDIR)/%.o:	%.c | $(OBJDIR)
				$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

$(NAME):		$(OBJ)
				make -C $(LIBDIR)/libft
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
