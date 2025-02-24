# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hfeufeu <hfeufeu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 20:28:29 by hfeufeu           #+#    #+#              #
#    Updated: 2025/02/24 18:48:18 by hfeufeu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

EXEC = fdf
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = ./mlx
MLX  = $(MLX_DIR)/libmlx.so
OBJDIR = .build
SRCDIR = src

SRC = fdf.c \
	  fdf_utils.c \
	  points.c \
	  parsing.c \
	  listing.c \
	  drawer.c \

SRC := $(addprefix $(SRCDIR)/, $(SRC))

OBJ := $(addprefix $(OBJDIR)/, $(SRC:%.c=%.o))

IFLAGS = -I ./include -I $(MLX_DIR)

LIB = -L$(LIBFT_DIR) -g -lft -L $(MLX_DIR) -lSDL2
LDFLAGS = -Lmlx -lmlx -lm -lX11 -lXext -Wl,-rpath,./mlx

RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
RESET = \033[0m

define HEADER
$(RED) ███████████ ██████████   ███████████$(RESET)
$(RED)░░███░░░░░░█░░███░░░░███ ░░███░░░░░░█$(RESET)
$(RED) ░███   █ ░  ░███   ░░███ ░███   █ ░$(RESET)
$(RED) ░███████    ░███    ░███ ░███████  $(RESET)
$(RED) ░███░░░█    ░███    ░███ ░███░░░█  $(RESET)
$(RED) ░███  ░     ░███    ███  ░███  ░   $(RESET)
$(RED) █████       ██████████   █████     $(RESET)
$(RED)░░░░░       ░░░░░░░░░░   ░░░░░$(RESET)
$(RED)By Dornagol$(RESET)
endef
export HEADER

all: header $(LIBFT) $(EXEC)

header:
	clear
	@echo  "$$HEADER"

$(OBJDIR)/%.o: %.c
	@mkdir -p '$(@D)'
	@$(CC) $(CFLAGS) $(IFLAGS) -g -c $< -o $@

$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_DIR)

$(EXEC): $(OBJ)
	@echo "$(GREEN)[Linking] Creating executable $(EXEC)...$(RESET)"
	@$(CC) $(OBJ) $(LIB) $(LDFLAGS) -o $(EXEC)
	@cp $(MLX) .
	@echo "$(GREEN)[Executable generated] You can run it with './$(EXEC)'$(RESET)"

test: CFLAGS =
test: clean header $(LIBFT) $(FT_PRINTF) $(EXEC)
	@echo "$(GREEN)[Test Compilation] Executable $(EXEC) ready to use without warning flags$(RESET)"

clean:
	@echo "$(RED)[Cleaning] Removing object files...$(RESET)"
	@rm -f -r $(OBJ) $(OBJDIR)
	@$(MAKE) -s -C $(LIBFT_DIR) clean

fclean: clean
	@echo "$(RED)[Full cleanup] Removing executable...$(RESET)"
	@rm -f -r $(EXEC) libmlx.so
	@$(MAKE) -s -C $(LIBFT_DIR) fclean

re: fclean all
	@echo "$(GREEN)[Rebuilding] Everything is recompiled!$(RESET)"

info:
	@echo "$(GREEN)[Info]\t       Executable is named $(EXEC)"
	@echo "$(GREEN)[Source files] $(SRC)"
	@echo "$(GREEN)[Object files] $(OBJ)"
	@echo "$(GREEN)[Libraries]    $(LIB)"
	@echo "$(GREEN)[Executable]   ./$(EXEC)$(RESET)"

.PHONY: all clean fclean re info header test