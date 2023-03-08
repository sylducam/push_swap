/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_libft.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <sylducam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 10:40:49 by sylducam          #+#    #+#             */
/*   Updated: 2021/10/07 17:10:14 by sylducam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_LIBFT_H
# define HEADER_LIBFT_H
# include <string.h>
# include <strings.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>
# include "get_next_line.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	int				rank;
	bool			turned;
	long long		content;
	struct s_stack	*previous;
	struct s_stack	*next;
}	t_stack;

int				atoi_limit(const char *str, int limit);
int				bool_strchr(const char *s, char c);
char			*change_char(char *s, char a, char b);
int				format_check(char *file, char *format);
int				free_char_p2p(char **str);
long long		ft_atoll(const char *str);
void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_putnbr(int nb);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_lstadd_front(t_list **alst, t_list *new);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
void			*ft_memcpy(void *dst, const void *source, size_t n);
void			*ft_memmove(void *dst, const void *source, size_t len);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memccpy(void *dst, const void *source, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_calloc(size_t count, size_t size);
char			*change_char(char *s, char a, char b);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
char			*ft_strdup(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strstr(char *str, char *to_find);
char			**ft_split(char const *s, char c);
size_t			ft_strlcpy(char *dst, const char *source, size_t size);
size_t			ft_strlen(const char *str);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
int				format_check(char *file, char *format);
int				free_char_p2p(char **str);
int				ft_atoi(const char *str);
int				ft_pf_atoi(char **str);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_strcmp(char *s1, char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstnew(void *content);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
int				get_next_line(int fd, char **line);
int				is_tab_digit(char **tab);
int				is_tab_nb(char **tab);
int				count_lines(char **tab);
int				longest_line(char **tab);
int				str_isdigit(char *str);
void			wrdestroy(void);
int				wrfree(void *ptr);
void			*wrmalloc(unsigned long size);

#endif
