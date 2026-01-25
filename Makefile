# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/08 15:55:57 by spacotto          #+#    #+#              #
#    Updated: 2026/01/25 18:13:07 by spacotto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	push_swap 
NAME_BONUS	:=	checker
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

OPS			:=	op_swap.c \
				op_push.c \
				op_rotate.c \
				op_reverse_rotate.c 

BEST		:=	move_to_top.c \
				ops_merge.c \
				ops_remove.c \
				ops_optimise.c

PREP		:=	make_parsing.c \
				make_stack.c \
				make_check.c \
				make_index.c 

SORT		:=	range_presort.c \
				range_sort.c

PUSH_SWAP	:=	push_swap.c

SRCS		:=	$(OPS) $(BEST) $(PREP) $(SORT) $(PUSH_SWAP)

CHECKER_OPS	:=	checker_ss_bonus.c \
				checker_pp_bonus.c \
				checker_rr_bonus.c \
				checker_rrr_bonus.c

CHECKER		:=	checker_bonus.c

SRCS_BONUS	:= $(CHECKER_OPS) $(CHECKER)

# ============================================================================
# OBJECTS
# ============================================================================

OBJS_DIR	:=	objs/

OBJS		:=	$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

OBJ_BONUS	:=	$(addprefix $(OBJS_DIR), $(SRCS_BONUS:.c=.o))

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

bonus:			banner $(NAME_BONUS)

$(NAME_BONUS):	$(OBJS_BONUS)
				$(MAKE) 
				$(CP) $(LIBFT) $(NAME_BONUS)
				$(CC) $(OBJS_BONUS) ./libft/libft.a -o $(NAME_BONUS)
				$(ECHO) "$(GREEN)✨ checker is ready ✨$(RESET)"

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
				$(RM) $(NAME_BONUS)
				$(RM) $(LIBFT)
				$(ECHO) "$(RED)🧹Everything removed!$(RESET)"

re: 			fclean all
				$(ECHO) "$(BLUE)💫 Cleaned and rebuilt everything 💫$(RESET)"

.PHONY: all clean fclean re
