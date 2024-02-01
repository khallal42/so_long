NAME = so_long
NAME_BONUS = so_long_bonus
CFILES = so_long.c \
		 ft_split.c \
		 number_line.c \
		 wall.c \
		 put_image_colone.c \
		 get_next_line.c \
		 check_map.c \
		 check_arg.c \
		 key_hook.c \
		 position_player.c \
		 check_coin.c \
		 check_path.c \
		 colection.c\
		 ft_itoa.c 

CFILES_BONUS = bonus/so_long_bonus.c \
			bonus/ft_split_bonus.c \
		  bonus/number_line_bonus.c \
		  bonus/wall_bonus.c \
		  bonus/put_image_colone_bonus.c \
		  bonus/get_next_line_bonus.c \
		  bonus/check_map_bonus.c \
		  bonus/check_arg_bonus.c \
		  bonus/key_hook_bonus.c \
		  bonus/position_player_bonus.c \
		  bonus/check_coin_bonus.c \
		  bonus/check_path_bonus.c \
		  bonus/colection_bonus.c\
		  bonus/ft_itoa_bonus.c \
		  bonus/position_enemy_bonus.c 

FLAG = -Wall -Werror -Wextra -lmlx -framework OpenGL -framework AppKit
CC = cc
LI = ar rc
RM = rm -rf

all : ${NAME}

${NAME} :
	${CC} ${FLAG} ${CFILES} -o ${NAME}

bonus : ${NAME_BONUS}

${NAME_BONUS} :
	${CC} ${FLAG} ${CFILES_BONUS} -o ${NAME_BONUS}
clean :
	${RM}

fclean : clean
	${RM} ${NAME} ${NAME_BONUS}

re : fclean all

.PHONY: all bonus clean fclean re