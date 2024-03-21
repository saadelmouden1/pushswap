NAME = push_swap.a
HEADER = push_swap.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRCS = push_swap.c push_swap_helpers.c push_stack.c retate_stack.c \
		reverse_retate.c swap_stack.c


OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
		$(AR) $@ $^

%.o: %.c $(HEADER)
		$(CC) -c $< -o $@

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re : fclean all
	