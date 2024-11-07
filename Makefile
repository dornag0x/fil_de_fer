# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hfeufeu <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 20:28:29 by hfeufeu           #+#    #+#              #
#    Updated: 2024/11/07 20:48:40 by hfeufeu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC = gcc
CFLAGS = -Wall -Wextra -Werror

EXEC = fdf
LIB = lib/MacroLibX/libmlx.so
LIBS = -lSDL2

SRC = fdf.c \
	  hooks.c \

OBJ = $(SRC:.c=.o)

RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
RESET = \033[0m

define HEADER
___________              __
\__    ___/___   _______/  |_
  |    |_/ __ \ /  ___/\   __\\
  |    |\  ___/ \___ \  |  |
  |____| \___  >____  > |__|
             \/     \/
endef
export HEADER

all: header $(EXEC)

header:
	clear
	@echo -e "$$HEADER"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	@echo -e "$(YELLOW)[Compiling] $< -> $@$(RESET)"

$(EXEC): $(OBJ)
	@echo -e "$(GREEN)[Linking] Creating executable $(EXEC)...$(RESET)"
	@$(CC) $(OBJ) $(LIB) $(LIBS) -o $(EXEC)
	@echo -e "$(GREEN)[Executable generated] You can run it with './$(EXEC)'$(RESET)"

# Nouvelle règle pour compiler sans les options de warning
test: CFLAGS =
test: clean header $(EXEC)
	@echo -e "$(GREEN)[Test Compilation] Executable $(EXEC) ready to use without warning flags$(RESET)"

clean:
	@echo -e "$(RED)[Cleaning] Removing object files...$(RESET)"
	@rm -f $(OBJ)

fclean: clean
	@echo -e "$(RED)[Full cleanup] Removing executable...$(RESET)"
	@rm -f $(EXEC)

re: fclean all
	@echo -e "$(GREEN)[Rebuilding] Everything is recompiled!$(RESET)"

info:
	@echo -e "$(GREEN)[Info]	       Executable is named $(EXEC)"
	@echo -e "$(GREEN)[Source files] $(SRC)"
	@echo -e "$(GREEN)[Object files] $(OBJ)"
	@echo -e "$(GREEN)[Libraries]    $(LIB) $(LIBS)"
	@echo -e "$(GREEN)[Executable]   ./$(EXEC)$(RESET)"

.PHONY: all clean fclean re info header fast

