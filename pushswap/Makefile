SOURCES = check_numbers.c number_process.c push_swap.c sort_pivot.c \
			sort_process.c sort_process2.c utils_arr.c utils_arrindex.c \
			utils_generic.c utils_pushswap.c utils_str.c

SOURCES_BONUS = check_numbers_bonus.c number_process_bonus.c checker.c \
			utils_arr_bonus.c utils_generic_bonus.c utils_pushswap_bonus.c

NAME = push_swap
NAME_BONUS = checker

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME) : $(SOURCES)
	gcc -Wall -Wextra -Werror $(SOURCES) -o $(NAME)

$(NAME_BONUS) : $(SOURCES_BONUS)
	gcc -Wall -Wextra -Werror $(SOURCES_BONUS) -o $(NAME_BONUS)

clean:
	rm $(NAME)
	rm $(NAME_BONUS)

fclean: clean

re: fclean all

.PHONY:  all clean fclean re