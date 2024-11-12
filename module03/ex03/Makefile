NAME = claptrap
CC = c++
STANDARD = -std=c++11
CFLAGS = -Wall -Wextra -Werror $(STANDARD)
SRCS =	ClapTrap.cpp \
		ScavTrap.cpp \
		FragTrap.cpp \
		DiamondTrap.cpp \
		main.cpp

OBJS	:= ${SRCS:.cpp=.o}

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	@echo "Compiling claptrap..."
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