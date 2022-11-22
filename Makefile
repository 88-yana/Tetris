CC = gcc
CFLAGS = -lncurses
# CFLAGS = -Wall -Wextra -Werror -lncurses
SRCSDIR = srcs
OBJSDIR = objs
SRCS = $(shell find $(SRCSDIR) -type f -name *.c)
OBJS = $(SRCS:$(SRCSDIR)/%.c=$(OBJSDIR)/%.o)
NAME = Tetris

all: $(OBJSDIR) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJSDIR):
	mkdir $(shell find $(SRCSDIR) -type d | sed 's/^$(SRCSDIR)/$(OBJSDIR)/g')

$(OBJSDIR)/%.o: $(SRCSDIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) -rf $(OBJSDIR)
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re