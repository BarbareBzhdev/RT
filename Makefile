# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 11:25:08 by rlambert          #+#    #+#              #
#    Updated: 2015/11/03 21:08:25 by roblabla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RT

PRINTF_PATH ?= ft_printf/

LIBFT_PATH ?= ft_printf/libft/

ifeq ($(shell uname), Linux)
MLX_PATH ?= mlx_x11/
else
MLX_PATH ?= mlx_mac/
endif

CFLAGS += -Wall -Wextra -Werror

SRCS = src/main.c \
       src/ft_env.c \
       src/framework_collision/fk_collision.c \
       src/framework_collision/fk_ray.c \
       src/framework_collision/fk_sphere.c \
       src/framework_collision/fk_vector.c \
       src/framework_collision/fk_rgb.c \
       src/framework_collision/fk_vectoriel.c \
       src/framework_collision/fk_vectoriel_math.c \
       src/framework_collision/fk_vectoriel_transformation.c \
       src/framework_collision/fk_vertex_math.c

INC_FILES = include/ft_env.h \
			include/framework/fk_collision.h \
			include/framework/fk_math.h \
			include/framework/fk_objects.h \
			include/framework/fk_ray.h \
			include/framework/fk_rgb.h \
			include/framework/fk_sphere.h \
			include/framework/fk_type.h \
			include/framework/fk_vectoriel.h \
			include/framework/fk_vertexiel.h


C_INCLUDE_PATH += $(LIBFT_PATH)/include/ include/ $(PRINTF_PATH)/include/ $(MLX_PATH)

CFLAGS += $(foreach d, $(C_INCLUDE_PATH), -I$d)

OBJS = $(patsubst src/%.c,obj/%.o,$(SRCS))

CP = cp

RM = rm -f

ifeq ($(shell uname), Linux)
LDFLAGS += $(shell pkg-config xext x11 --libs)
else
LDFLAGS += -framework OpenGL -framework AppKit
endif

LDFLAGS += -L$(PRINTF_PATH) -lftprintf -L$(MLX_PATH) -lmlx -lm

all: $(NAME)

MKDIR ?= mkdir

obj/%.o: src/%.c $(INC_FILES)
	$(MKDIR) -p $(dir $@)
	$(CC) -c $(CFLAGS) $< -o $@

$(MLX_PATH)/libmlx.a:
	$(MAKE) -C $(MLX_PATH)

$(PRINTF_PATH)/libftprintf.a:
	$(MAKE) -C $(PRINTF_PATH)

$(NAME): $(PRINTF_PATH)/libftprintf.a $(MLX_PATH)/libmlx.a $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(PRINTF_PATH) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(MAKE) -C $(PRINTF_PATH) fclean

re: fclean all


.PHONY: all clean fclean re $(PRINTF_PATH)/libftprintf.a $(MLX_PATH)/libmlx.a
