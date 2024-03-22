# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siroulea <siroulea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/08 13:59:02 by siroulea          #+#    #+#              #
#    Updated: 2024/03/08 14:00:41 by siroulea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



G = \033[0;32m
RT = \033[0m

# NAME_OF_THE_PROGRAM (exemple:   a.out    )
NAME	= cub3D

# COMPILER
CC		= gcc

# COMPILER FLAGS
CFLAGS	= -Wextra -Wall -Werror -Wunreachable-code -Ofast -g
#LFLAGS  = -fsanitize=address

# LIBRARY
LIBMLX	= MLX42
LIBS	= MLX42/libmlx42.a MLX42/libglfw3.a 

# DIRECTORY FOR HEADER FILE
HEADERS	= -I ./include -I $(LIBMLX)/include

SRCS	=	src/main.c		\
		src/hook.c		\
		src/extract_map.c	\
		src/flood_fill.c	\
		src/creat_image.c	\
		src/utils.c		\
		src/get_next_line.c	\
		src/map_chekup.c	\
		src/ft_strjoin.c 	\
		src/ft_itoa.c


OBJDIR	=	bin/

SRCDIR	=	src/

OBJS	=	$(patsubst $(SRCDIR)%.c,$(OBJDIR)%.o,$(SRCS))

all: mk_bin libs_make $(NAME)
	
	
mk_bin:
	@mkdir -p $(OBJDIR)
	
libs_make:
	@$(MAKE) -C $(LIBMLX)

$(OBJS): $(OBJDIR)%.o : $(SRCDIR)%.c $(INC) | $(OBJDIR)
	@$(CC)  $(CFLAGS)$(LFLAGS) -c $< -o $@ $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME) -framework Cocoa -framework OpenGL -framework IOKit

	@echo "$(G)\n ║ MAKE COMPLETE  ║$(RT)"
	@echo "\nMAKE PLAY  \ RUN...$(RT)"
	@echo "MAKE LEAKS   \\ RUN + LEAKS CHECK $(RT)"

bonus: CFLAGS += -D BONUS

bonus: re
	
clean:
	@echo "\n$(R)Cleaning...$(RT)"
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBMLX) clean
	@echo "$(G)MLX42 Cleaned$(RT)"

fclean: clean rm_bin
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBMLX) fclean
	@echo "$(G)MLX42  Cleaned$(RT)"

rm_bin:
	@rm -rf $(OBJDIR)

re: fclean all

leaks: all
	leaks -atExit -- ./so_long map/map01.ber

play: all
	./cub3D map/map01.ber

