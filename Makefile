###############
## Variables ##
###############

NAME		=	cub3D

VPATH		=	src src/hook src/engine src/utils src/platform
OBJDIR		=	obj
LIBDIR		=	libft
INCLDIR		=	incld

SRC			=	main.c \
				raycaster.c \
				raycaster2.c \
				cam_move.c \
				cam_move2.c \
				map.c \
				flag.c \
				keyboard.c \
				image.c
LIB			=	libft.a
OBJ			=	$(SRC:%.c=$(OBJDIR)/%.o)

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -fsanitize=address -g3
INCFLAGS	=	-I./$(INCLDIR)
LFLAGS		=	-L./$(LIBDIR) -lft
RM			=	/bin/rm -rf
UNAME		:=	$(shell uname -s)

ifeq ($(UNAME),Linux)
	SRC += linux.c
	INCFLAGS += -I/usr/include -Imlx-linux -O3
	LFLAGS += -Lmlx_Linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
endif
ifeq ($(UNAME),Darwin)
	SRC += mac.c
	INCFLAGS += -Imlx
	LFLAGS += -lmlx -framework OpenGL -framework AppKit
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
