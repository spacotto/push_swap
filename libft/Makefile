# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/01 13:30:48 by spacotto          #+#    #+#              #
#    Updated: 2026/01/15 13:50:35 by spacotto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libft.a
FLAGS		:= -c -Wall -Wextra -Werror

# ============================================================================
# COLORS
# ============================================================================

RESET		:= \033[0m
GRAY		:= \033[0;90m
RED			:= \033[0;91m
GREEN		:= \033[0;92m
YELLOW		:= \033[0;93m
BLUE		:= \033[0;94m
MAGENTA		:= \033[0;95m
CYAN		:= \033[0;96m
WHITE		:= \033[0;97m

# ============================================================================
# COMMANDS
# ============================================================================

CC			:= @cc
AR			:= @/bin/ar rcs
ECHO		:= @echo #-e
MKDIR		:= @/bin/mkdir
RM			:= @/bin/rm -rf

# ============================================================================
# INCLUDES 
# ============================================================================

INC			:= -I ./inc/

# ============================================================================
# SOURCES
# ============================================================================

SRCS_DIR	:=	srcs/

SRC_IS		:=	ft_isneg.c \
				ft_isascii.c \
				ft_isalnum.c \
				ft_isdigit.c \
				ft_isalpha.c \
				ft_isupper.c \
				ft_islower.c \
				ft_isprint.c \
				ft_isspace.c

SRC_COUNT	:=  ft_countdigits.c \
			    ft_countwords.c 

SRC_STR		:=  ft_search_and_replace.c \
				ft_split.c \
				ft_strcat.c \
				ft_strchr.c \
				ft_strcmp.c \
				ft_strcpy.c \
				ft_strcspn.c \
				ft_strdup.c \
				ft_striteri.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strmapi.c \
				ft_strncat.c \
				ft_strncmp.c \
				ft_strncpy.c \
				ft_strnstr.c \
				ft_strpbrk.c \
				ft_strrchr.c \
				ft_strspn.c \
				ft_strtok.c \
				ft_strtrim.c \
				ft_substr.c

SRC_MEM		:=	ft_swap.c \
				ft_bzero.c \
				ft_memchr.c \
				ft_memcmp.c\
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c 

SRC_CNV		:=	ft_toupper.c \
				ft_tolower.c \
				ft_atoi.c \
				ft_atoi_base.c \
				ft_itoa.c \
				ft_itoa_base.c \
				ft_itoa_base_buffer.c \
				ft_utoa.c \
				ft_utoa_base.c \
				ft_utoa_base_buffer.c

SRC_ALC		:=	ft_arena.c \
				ft_calloc.c

SRC_FD		:=	ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putnbr_base_fd.c 

SRC_LST		:=	ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_lstcat.c \
				ft_lstpos.c

SRC_PRINTF	:=	ft_printf.c \
				ft_printchar.c \
				ft_printstr.c \
				ft_printptr.c \
				ft_printnbr.c \
				ft_printunb.c \
				ft_printhex.c

SRC_GNL		:=	get_next_line.c

SRCS		:=	$(SRC_IS) $(SRC_COUNT) $(SRC_STR) $(SRC_MEM) $(SRC_CNV) \
				$(SRC_ALC) $(SRC_FD) $(SRC_LST) $(SRC_PRINTF) $(SRC_GNL) 

# ============================================================================
# OBJECTS
# ============================================================================

OBJS_DIR:= objs/

OBJS	:= $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

# ============================================================================
# RULES
# ============================================================================

all:			$(NAME)

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
				$(AR) $(NAME) $(OBJS)
				$(ECHO) "$(GREEN)✨ libft is ready ✨$(RESET)"

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c
				$(MKDIR) -p $(dir $@)
				$(ECHO) "$(YELLOW)🪄Compiling $< $(RESET)"
				$(CC) $(FLAGS) $(INC) $< -o $@

clean:
				$(RM) $(OBJS_DIR)
				$(ECHO) "$(RED)🧹libft objects removed!$(RESET)"

fclean:			clean
				$(RM) $(NAME)
				$(ECHO) "$(RED)🧹Archive removed!$(RESET)"

re: 			fclean all
				$(ECHO) "$(BLUE)💫 Cleaned and rebuilt everything 💫$(RESET)"

.PHONY: all banner clean fclean re
