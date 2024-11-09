# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hfeufeu <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 20:28:29 by hfeufeu           #+#    #+#              #
#    Updated: 2024/11/08 16:53:59 by hfeufeu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC = gcc
CFLAGS = -Wall -Wextra -Werror

EXEC = fdf
LIB = lib/MacroLibX/libmlx.so lib/libft/libft.a
LIBS = -lSDL2

SRC = fdf.c \
	  hooks.c \
	  points.c \
	  parsing.c \

OBJ = $(SRC:.c=.o)

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

all: header $(EXEC)

header:
	clear
	@echo  "$$HEADER"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(YELLOW)[Compiling] $< -> $@$(RESET)"

$(EXEC): $(OBJ)
	@echo "$(GREEN)[Linking] Creating executable $(EXEC)...$(RESET)"
	@$(CC) $(OBJ) $(LIB) $(LIBS) -o $(EXEC)
	@echo "$(GREEN)[Executable generated] You can run it with './$(EXEC)'$(RESET)"

test: CFLAGS =
test: clean header $(EXEC)
	@echo "$(GREEN)[Test Compilation] Executable $(EXEC) ready to use without warning flags$(RESET)"

clean:
	@echo "$(RED)[Cleaning] Removing object files...$(RESET)"
	@rm -f $(OBJ)

fclean: clean
	@echo "$(RED)[Full cleanup] Removing executable...$(RESET)"
	@rm -f $(EXEC)

re: fclean all
	@echo "$(GREEN)[Rebuilding] Everything is recompiled!$(RESET)"

info:
	@echo "$(GREEN)[Info]	       Executable is named $(EXEC)"
	@echo "$(GREEN)[Source files] $(SRC)"
	@echo "$(GREEN)[Object files] $(OBJ)"
	@echo "$(GREEN)[Libraries]    $(LIB) $(LIBS)"
	@echo "$(GREEN)[Executable]   ./$(EXEC)$(RESET)"

.PHONY: all clean fclean re info header fast

