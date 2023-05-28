NAME    = container
CC      = c++
FLAGS   = -Wall -Werror -Wextra -std=c++98
SRCS    = main.cpp

OBJS    = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) -o $(NAME) $(SRCS) $(FLAGS)

clean:
	rm -rf $(OBJS) $(NAME)
	make clean -C ./tester

fclean: clean
	rm -rf $(NAME)

test:
	make -C ./tester
	./tester/tester

re: clean $(NAME)

.PHONY  : clean re
