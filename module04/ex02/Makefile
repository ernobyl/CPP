NAME = animal
CC = c++
STANDARD = -std=c++11
CFLAGS = -Wall -Wextra -Werror $(STANDARD)
SRCS =	Animal.cpp \
		Dog.cpp \
		Cat.cpp \
		WrongAnimal.cpp \
		WrongCat.cpp \
		Brain.cpp \
		main.cpp

OBJS	:= ${SRCS:.cpp=.o}

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	@echo "Compiling animal..."
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "Done!"

clean:
	@echo "Cleaning object files..."
	@rm -rf $(OBJS)

fclean: clean
	@echo "Cleaning everything else..."
	@rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re