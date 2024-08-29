NAME = moar_brainz
CC = c++
CFLAGS = -Wall -Wextra -Werror
SRCS =	Zombie.cpp \
		zombieHorde.cpp \
		main.cpp

OBJS	:= ${SRCS:.cpp=.o}

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	@echo "Compiling zombie horde..."
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "Done!"

clean:
	@echo "Cleaning object files..."
	@rm -rf $(OBJS)

fclean: clean
	@echo "Cleaning everything else..."
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re