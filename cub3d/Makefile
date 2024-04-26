# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: beeren <beeren@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/12 02:37:51 by beeren            #+#    #+#              #
#    Updated: 2024/03/24 00:47:33 by beeren           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g

UTILITIES	= src/utilities/lib_utils.c \
			src/utilities/lib_utils2.c \
			src/utilities/lib_utils3.c \
			src/utilities/ft_split.c \

CONFIG		= src/mandatory/config/get_next_line.c \
			src/mandatory/config/init_config.c \
			src/mandatory/config/init_free_map.c \
			src/mandatory/config/ceiling_color.c \
			src/mandatory/config/config.c \
			src/mandatory/config/elements.c \
			src/mandatory/config/floor_color.c \
			src/mandatory/config/map_characters.c \
			src/mandatory/config/map_spaces.c \
			src/mandatory/config/map_walls.c \
			src/mandatory/config/map.c \
			src/mandatory/config/xpm_files.c

GAME		= src/mandatory/game/init_free_game.c \
			src/mandatory/game/init_free_mlx.c \
			src/mandatory/game/init_free_player.c \
			src/mandatory/game/init_free_xpm_images.c \
			src/mandatory/game/key_handler.c \
			src/mandatory/game/key_handler2.c \
			src/mandatory/game/mlx_loop_handler.c \
			src/mandatory/game/player_move.c \
			src/mandatory/game/player_move2.c \
			src/mandatory/game/ray_fill_screen.c \
			src/mandatory/game/raycasting.c

MAIN		= src/mandatory/main.c

OBJS		= $(UTILITIES:%.c=%.o) $(CONFIG:%.c=%.o) $(GAME:%.c=%.o) $(MAIN:%.c=%.o)

MLX			= mlx/libmlx.a
MLX_FLAGS	= -Lmlx -lmlx -framework OpenGL -framework AppKit


RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m
NC=\033[0m

all: $(NAME) 

fast: 
	@make -s && ./cub3D maps/cub3dbest.cub

progress_eng:
	@for i in $$(seq 12 29 100); do \
        echo "$(RED)\n\n										< --- > Game Starting: $$i%  < --- > $(NC)"; \
        sleep 0.4; \
    done
	@sleep 1;

finished_eng:
	@echo "$(GREEN)	\n\n										 < --- >   Game Started!   < --- > $(NC)";
	@echo "\n\n	 ####  #####  ######   ##   ##### ###### #####     #####  #   #    #####  ###### ###### #####  ###### #    #     #  #    #  #      #    # ###### #    # #    # #   # # #      #####     "
	@echo "	#    # #    # #       #  #    #   #      #    #    #    #  # #     #    # #      #      #    # #      ##   #      ##      ##       ##  ## #      #    # ##  ##  # #  # #      #    # $(RED)██╗$(END)"
	@echo "	#      #    # #####  #    #   #   #####  #    #    #####    #      #####  #####  #####  #    # #####  # #  #     ###     ###       # ## # #####  ###### # ## #   #   # #      #    # $(RED)╚═╝$(END)"
	@echo "	#      #####  #      ######   #   #      #    #    #    #   #      #    # #      #      #####  #      #  # #    #   # # #   # #    #    # #      #    # #    #   #   # #      #    # $(RED)██╗$(END)"
	@echo "	#    # #   #  #      #    #   #   #      #    #    #    #   #      #    # #      #      #   #  #      #   ##    #    #  #    #     #    # #      #    # #    #   #   # #      #    # $(RED)╚═╝$(END)"
	@echo "	 ####  #    # ###### #    #   #   ###### #####     #####    #      #####  ###### ###### #    # ###### #    #     ###  #  ###  #    #    # ###### #    # #    #   #   # ###### #####     \n\n$(END)"

	@sleep 1;
	@./cub3D maps/cub3dbest.cub

progress_tr:
	@for i in $$(seq 12 29 100); do \
        echo "$(RED)\n\n										< --- > Oyun başlatılıyor: $$i%  < --- > $(NC)"; \
        sleep 0.2; \
    done
	@sleep 1;

finished_tr:
	@echo "$(GREEN)\n\n										   < --- > Oyun başlatıldı! $$i  < --- > $(NC)";
	@sleep 1;
	@echo "\n\n	 ####  #####  ######   ##   ##### ###### #####     #####  #   #    #####  ###### ###### #####  ###### #    #     #  #    #  #      #    # ###### #    # #    # #   # # #      #####     "
	@echo "	#    # #    # #       #  #    #   #      #    #    #    #  # #     #    # #      #      #    # #      ##   #      ##      ##       ##  ## #      #    # ##  ##  # #  # #      #    # $(RED)██╗$(END)"
	@echo "	#      #    # #####  #    #   #   #####  #    #    #####    #      #####  #####  #####  #    # #####  # #  #     ###     ###       # ## # #####  ###### # ## #   #   # #      #    # $(RED)╚═╝$(END)"
	@echo "	#      #####  #      ######   #   #      #    #    #    #   #      #    # #      #      #####  #      #  # #    #   # # #   # #    #    # #      #    # #    #   #   # #      #    # $(RED)██╗$(END)"
	@echo "	#    # #   #  #      #    #   #   #      #    #    #    #   #      #    # #      #      #   #  #      #   ##    #    #  #    #     #    # #      #    # #    #   #   # #      #    # $(RED)╚═╝$(END)"
	@echo "	 ####  #    # ###### #    #   #   ###### #####     #####    #      #####  ###### ###### #    # ###### #    #     ###  #  ###  #    #    # ###### #    # #    #   #   # ###### #####     \n\n$(END)"

	@sleep 1;
	@./cub3D maps/cub3dbest.cub

$(NAME): $(MLX) $(OBJS)
	@echo "$(RED)Procces still continue...$(NC)"
	@$(CC) $(OBJS) $(CFLAGS) $(MLX_FLAGS) $(MLX) -o $(NAME)
	@sleep 1.5;
	@echo "$(GREEN)Done! [✓]$(NC)"

clean:
	@rm -rf $(OBJS)
	@clear

fclean: clean
	@rm -rf $(NAME)

re: fclean all

start_tr: $(NAME) progress_tr finished_tr
start_eng: $(NAME) progress_eng finished_eng

n:
	@norminette src/utilities
	@norminette src/mandatory

c:clean
f:fclean
r:re
s:start_tr

m:
	@echo "$(YELLOW)Welcome to Cub3d Game Setup $(NC)"
	@echo "$(CYAN)Choose language: $(NC)/ $(RED) Dil seçiniz: $(NC)"
	@echo "$(BLUE)1. Turkish $(NC)"
	@echo "$(BLUE)2. English $(NC)"
	@read -p "Enter your choice (1 or 2): " choice; \
	if [ $$choice -eq 1 ]; then \
	    make turkish; \
	elif [ $$choice -eq 2 ]; then \
	    make english; \
	else \
	    echo " $(RED) Invalid choice. Exiting. $(NC)"; \
	fi

t: turkish
turkish:
	@echo "$(MAGENTA)Türkçe dil seçildi. $(NC)"
	@echo "$(YELLOW)1. hedef make re [✓] $(NC)"
	@echo "$(YELLOW)2. hedef make fclean [✓] $(NC)"
	@echo "$(YELLOW)3. hedef make norminette [✓] $(NC)"
	@echo "$(YELLOW)4. hedef sessiz make && run [✓] $(NC)"
	@echo "$(GREEN)5. hedef Oyunu başlat [✓] $(NC)"
	@read -p "Seçiminizi yapın: " secim; \
	case $$secim in \
		1) make re ;; \
		2) make fclean ;; \
		3) make n ;; \
		4) make f && make -s && ./cub3D maps/map.cub;; \
		5) make f && make -s && make start_tr;; \
	esac 

e: english
english:
	@echo "$(MAGENTA)English language selected. $(NC)"
	@echo "$(YELLOW)1. choise make re [✓] $(NC)"
	@echo "$(YELLOW)2. choise make fclean [✓] $(NC)"
	@echo "$(YELLOW)3. choise make norminette [✓] $(NC)"
	@echo "$(YELLOW)4. choise silent make && run [✓] $(NC)"
	@echo "$(GREEN)5. choise Start Game [✓] $(NC)"
	@read -p "Make your choice: " choise; \
	case $$choise in \
		1) make re ;; \
		2) make fclean ;; \
		3) make n ;; \
		4) make f && make -s && ./cub3D maps/map.cub;; \
		5) make f && make -s && make start_eng;; \
	esac
norm:
	@norminette src