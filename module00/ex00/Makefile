NAME = megaphone
CC = c++
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
SRCS =	megaphone.cpp

OBJS	:= ${SRCS:.cpp=.o}

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	@echo "Compiling megaphone..."
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "Done!"

clean:
	@echo "Cleaning object files..."
	@rm -rf $(OBJS)

fclean: clean
	@echo "Cleaning everything else..."
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re