# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/08 15:55:57 by spacotto          #+#    #+#              #
#    Updated: 2026/01/16 18:33:57 by spacotto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	push_swap 
LIBFT		:=	libft/libft.a
FLAGS		:=	-c -Wall -Wextra -Werror -g

# ============================================================================
# COLORS
# ============================================================================

RESET		:=	\033[0m
GRAY		:=	\033[0;90m
RED			:= 	\033[0;91m
GREEN		:=	\033[0;92m
YELLOW		:=	\033[0;93m
BLUE		:=	\033[0;94m
MAGENTA		:=	\033[0;95m
CYAN		:=	\033[0;96m
WHITE		:=	\033[0;97m

# ============================================================================
# COMMANDS
# ============================================================================

CC			:=	@cc
CP			:=	@/bin/cp
ECHO		:=	@echo #-e
MAKE		:=	@make -C libft
MKDIR		:=	@/bin/mkdir
RM			:=	@/bin/rm -rf

# ============================================================================
# INCLUDES
# ============================================================================

INC			:=	-I ./inc/

# ============================================================================
# SOURCES
# ============================================================================

SRCS_DIR	:=	srcs/

OP			:=	op_swap.c \
				op_push.c \
				op_rotate.c \
				op_reverse_rotate.c 

BEST		:=	best_move_to_top.c \
				best_op.c

SORT		:=	sort_parsing.c \
				sort_check.c \
				sort_index.c \
				sort_find.c \
				simple_sort.c \
				chunk_sort.c

PUSH_SWAP	:=	push_swap.c

SRCS		:=	$(OP) $(BEST) $(SORT) $(PUSH_SWAP)

# ============================================================================
# OBJECTS
# ============================================================================

OBJS_DIR	:=	objs/

OBJS		:=	$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

# ============================================================================
# RULES
# ============================================================================

all:			banner $(NAME)

banner:			
				$(ECHO) "$(CYAN)"
				$(ECHO)	"      __...--~~~~~-._   _.-~~~~~--...__ 	  "
				$(ECHO) "     /                V                \ 	  "
				$(ECHO) "    /                 |                 \    "
				$(ECHO) "   /__...--~~~~~~-._  |  _.-~~~~~~--...__\   "
				$(ECHO) "  /__.....----~~~~._\ | /_.~~~~----.....__\  "
				$(ECHO) " =====================v===================== "
				$(ECHO) "$(RESET)$(YELLOW)"
				$(ECHO) "         ✨Time to do some magic!✨          "
				$(ECHO) "$(RESET)"

$(NAME):		$(OBJS)
				$(MAKE) 
				$(CP) $(LIBFT) $(NAME)
				$(CC) $(OBJS) ./libft/libft.a -o $(NAME)
				$(ECHO) "$(GREEN)✨ push_swap is ready ✨$(RESET)"

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c
				$(MKDIR) -p $(dir $@)
				$(ECHO) "$(YELLOW)🪄Compiling $< $(RESET)"
				$(CC) $(FLAGS) $(INC) $< -o $@
clean:
				$(RM) $(OBJS_DIR)
				make clean -C libft
				$(ECHO) "$(RED)🧹push_swap objects removed!$(RESET)"

fclean: 		clean
				$(RM) $(NAME)
				$(RM) $(LIBFT)
				$(ECHO) "$(RED)🧹Everything removed!$(RESET)"

re: 			fclean all
				$(ECHO) "$(BLUE)💫 Cleaned and rebuilt everything 💫$(RESET)"

.PHONY: all clean fclean re
