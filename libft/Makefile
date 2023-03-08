SRCS	=		$(addprefix srcs/,\
				atoi_limit.c\
				bool_strchr.c\
				change_char.c\
				format_check.c\
				free_char_p2p.c\
				ft_atoi.c\
				ft_atoll.c\
				ft_memccpy.c\
				ft_memset.c\
				ft_strncmp.c\
				ft_bzero.c\
				ft_memchr.c\
				ft_strchr.c\
				ft_strrchr.c\
				ft_isalnum.c\
				ft_memcmp.c\
				ft_strlcat.c\
			 	ft_isdigit.c\
				ft_memmove.c\
				ft_strlen.c\
				ft_isalpha.c\
				ft_isascii.c\
				ft_isprint.c\
				ft_toupper.c\
				ft_tolower.c\
				ft_strnstr.c\
				ft_calloc.c\
				ft_strdup.c\
				ft_substr.c\
				ft_strjoin.c\
				ft_strtrim.c\
				ft_memcpy.c\
				ft_strlcpy.c\
				ft_itoa.c\
				ft_strmapi.c\
				ft_putchar_fd.c\
				ft_putstr_fd.c\
				ft_putendl_fd.c\
				ft_putnbr_fd.c\
				ft_split.c\
				ft_strcmp.c\
				ft_pf_atoi.c\
				ft_strstr.c\
				ft_putnbr.c\
				ft_putstr.c\
				ft_putchar.c\
				get_next_line.c\
			  	get_next_line_utils.c\
				is_tab_digit.c\
				is_tab_nb.c\
				count_lines.c\
				longest_line.c\
				str_isdigit.c\
				wrmalloc.c\
				ft_lstnew_bonus.c\
				ft_lstadd_front_bonus.c\
				ft_lstsize_bonus.c\
				ft_lstlast_bonus.c\
				ft_lstadd_back_bonus.c\
				ft_lstdelone_bonus.c\
				ft_lstclear_bonus.c\
				ft_lstiter_bonus.c\
				ft_lstmap_bonus.c)

OBJS		= 	$(SRCS:srcs/%.c=objs/%.o)

NAME		= 	libft.a

HEADER_FILE	=	includes/header_libft.h

CC			= 	clang

RM			= 	rm -rf

CFLAGS		= 	-Wall -Wextra -Werror -g3

objs/%.o	: 	srcs/%.c $(HEADER_FILE)
				$(CC) $(CFLAGS) -c $< -o $@

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				ar rc $(NAME) $(OBJS)

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re
