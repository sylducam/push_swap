NAME				=	push_swap

INCLUDES_PATH		=	include

HEADER				=	include/header_push_swap.h

PATH_LIBFT			=	libft

LIBFTA				=	libft.a

SRCS				=	$(addprefix srcs/,\
						start.c\
						store_stacks.c\
						transform_numbers.c\
						finish_program.c\
						push_b.c\
						push_a.c\
						swap.c\
						rotate.c\
						reverse_rotate.c\
						sort.c\
						sort_utils.c\
						push_chunks_b.c\
						tools.c)

OBJS				=	$(SRCS:srcs/%.c=objs/%.o)

COMP				=	clang

CFLAGS				=	-Iinclude -Wall -Wextra -Werror -g3 -Iinclude

RM					=	rm -rf

objs/%.o			:	srcs/%.c $(HEADER)
						$(COMP) $(CFLAGS) -c $< -o $@

all					:	libft $(NAME)

$(NAME)				:	$(OBJS)
						$(COMP) $(CFLAGS) $(LIBFTA) $(OBJS) main.c -o $(NAME) -I$(INCLUDES_PATH)

libft				:	
						$(MAKE) -C $(PATH_LIBFT)
						ln -sf $(PATH_LIBFT)/$(LIBFTA) .

clean				:
						$(RM) $(OBJS)
						$(MAKE) clean -C $(PATH_LIBFT)

fclean				:	clean
						$(RM) $(NAME) $(LIBFTA)
						$(MAKE) fclean -C $(PATH_LIBFT)

re					: 	fclean all

.PHONY				:	all libft clean fclean re
