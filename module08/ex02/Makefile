NAME = mutantstack
CPP = c++
STANDARD = -std=c++11
CPPFLAGS = -Wall -Wextra -Werror $(STANDARD)
SRCS = main.cpp

OBJS	:= ${SRCS:.cpp=.o}

all: $(NAME)

%.o: %.cpp
	@$(CPP) $(CPPFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	@echo "Compiling $(NAME)..."
	@$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)
	@echo "Done!"

clean:
	@echo "Cleaning object files..."
	@rm -rf $(OBJS)

fclean: clean
	@echo "Cleaning everything else..."
	@rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re