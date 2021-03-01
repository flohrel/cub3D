###############
## Variables ##
###############

NAME		=	cub3D

VPATH		=	src src/hook src/engine src/utils src/platform src/parser
OBJDIR		=	obj
LIBDIR		=	lib
INCLDIR		=	incld

SRC			=	main.c \
				parse.c \
				parse2.c \
				parse_map.c \
				parse_map2.c \
				raycaster.c \
				raycaster2.c \
				sprite.c \
				cam_move.c \
				cam_move2.c \
				flag.c \
				keyboard.c \
				image.c \
				utils.c \
				init.c
LIB			=	libft.a
OBJ			=	$(SRC:%.c=$(OBJDIR)/%.o)

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -g3
INCFLAGS	=	-I./$(INCLDIR) -I./$(LIBDIR)/libft/incld
LFLAGS		=	-L./$(LIBDIR)/libft -lft
RM			=	/bin/rm -rf
UNAME		:=	$(shell uname -s)

ifeq ($(UNAME),Linux)
	INCFLAGS += -I/usr/include -I./$(LIBDIR)/mlx_Linux -O3
	LFLAGS += -L./$(LIBDIR)/mlx_Linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
	SRC += linux.c
endif
ifeq ($(UNAME),Darwin)
	INCFLAGS += -I./$(LIBDIR)/mlx
	LFLAGS += -L./$(LIBDIR)/mlx -lmlx -framework OpenGL -framework AppKit
	SRC += mac.c
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
