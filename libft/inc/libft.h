/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:35:14 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/14 12:02:55 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

// ============================================================================
// DEFINES
// ============================================================================

# define PAGE_SIZE 4096

// ============================================================================
// INCLUDES
// ============================================================================

# include <ctype.h>
# include <bsd/string.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <unistd.h>

// ============================================================================
// STRUCTURES
// ============================================================================

typedef struct s_atoi
{
	int	i;
	int	sign;
	int	result;
}	t_atoi;

typedef struct s_itoa
{
	char	*result;
	size_t	len;
	size_t	base_len;
	size_t	flag;
}	t_itoa;

typedef struct s_split
{
	char	**array;
	size_t	i;	
	size_t	j;
}	t_split;

typedef struct s_trim
{
	char	*trim;
	char	*start;
	char	*end;	
	size_t	trimlen;	
}	t_trim;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	int				index;
}	t_list;

typedef struct s_arena
{
	t_list	*pages;
	size_t	used_mem;
	void	*current_page;
}	t_arena;

// ============================================================================
// PROTOTYPES 
// ============================================================================

// CHECKS
int		ft_isneg(int n);
int		ft_isascii(int c);
int		ft_isalnum(int c);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_isupper(int c);
int		ft_islower(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);

// COUNTERS
int		ft_countdigits(ssize_t n, ssize_t len);
int		ft_countwords(char const *s, char c);

// STRINGS
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

size_t	ft_strcspn(const char *s, const char *reject);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
size_t	ft_strspn(const char *s, const char *accept);

char	*ft_search_and_replace(char *s, char search, char replace);
char	**ft_split(char const *s, char c);
char	*ft_strcat(char *dst, const char *src);
char	*ft_strchr(const char *s, int c);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strncat(char *dst, const char *src, size_t ssize);
char	*ft_strncpy(char *dst, const char *src, size_t size);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strpbrk(const char *s, const char *accept);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strtok(char *str, const char *delim);
char	*ft_substr(char const *s, unsigned int start, size_t len);

void	ft_striteri(char *s, void (*f)(unsigned int, char*));

// MEMORY
int		ft_memcmp(const void *s1, const void *s2, size_t n);

void	ft_swap(int *a, int *b);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);

// CONVERSIONS 
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_atoi(const char *nptr);
int		ft_atoi_base(const char *nptr, int base);

char	*ft_itoa(ssize_t n);
char	*ft_utoa(size_t n);
char	*ft_itoa_base(ssize_t n, char *base);
char	*ft_utoa_base(size_t n, char *base);

void	ft_itoa_base_buffer(ssize_t n, char *base, char *buffer);
void	ft_utoa_base_buffer(size_t n, char *base, char *buffer);

// MEMORY ALLOCATION
void	*ft_calloc(size_t nmemb, size_t size);

t_arena	*arena_init(void);
void	*arena_alloc(t_arena *arena, size_t size);
void	arena_free(t_arena *arena);

// FD
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putnbr_base_fd(int n, char *base, int fd);

// LISTS
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	del(void *data);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstcat(t_list **lst1, t_list *lst2);

int		ft_lstsize(t_list *lst);

// ============================================================================
// COLORS
// ============================================================================

# define RESET 		"\033[0m"
# define GRAY 		"\033[0;90m"
# define RED 		"\033[0;91m"
# define GREEN 		"\033[0;92m"
# define YELLOW 	"\033[0;93m"
# define BLUE 		"\033[0;94m"
# define MAGENTA	"\033[0;95m"
# define CYAN 		"\033[0;96m"
# define WHITE 		"\033[0;97m"

#endif
