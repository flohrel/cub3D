###############
## Variables ##
###############

NAME		=	cub3D

VPATH		=	src
OBJDIR		=	obj
LIBDIR		=	libft
INCLDIR		=	includes

SRC			=	main.c
LIB			=	libft.a
OBJ			=	$(SRC:%.c=$(OBJDIR)/%.o)

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
INCFLAGS	=	-I./$(INCLDIR)
LFLAGS		=	-L./$(LIBDIR) -lft -lmlx
RM			=	/bin/rm -rf
UNAME		:=	$(shell uname -s)

ifeq ($(UNAME_S),Linux)
	LFLAGS += -lXext -lX11
endif
ifeq ($(UNAME_S),Darwin)
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
				cp $(LIBDIR)/$(LIB) ./$(NAME)
				$(AR) $(ARFLAGS) $@ $^

$(OBJDIR):
				mkdir $(OBJDIR)

bonus:
				@make all

clean:
				$(RM) $(OBJ)
				make -C $(LIBDIR) clean

fclean:			clean
				$(RM) $(NAME) $(OBJDIR)
				make -C $(LIBDIR) fclean

re:				fclean all
