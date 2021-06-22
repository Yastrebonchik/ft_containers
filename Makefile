NAME = ft_containers

CC = clang++

FLAGS = -Wall -Werror -Wextra -std=c++98

HEADERS = list.hpp vector.hpp stack.hpp queue.hpp map.hpp algorithm.hpp test_headers.hpp \
	list_tests.hpp vector_tests.hpp stack_tests.hpp queue_tests.hpp map_tests.hpp

HEADER_DIR = includes

S_DIR = srcs

O_DIR = obj

SRCS = main.cpp list_tests.cpp vector_tests.cpp stack_tests.cpp queue_tests.cpp map_tests.cpp

OBJECTS = $(addprefix $(O_DIR)/, $(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADER_DIR)
	clang++ -o $(NAME) $(OBJECTS)

$(O_DIR)/%.o: $(S_DIR)/%.cpp
	mkdir -p $(O_DIR)
	$(CC) $(FLAGS) -I$(HEADER_DIR) -o $@ -c $<

clean:
	rm -rf $(O_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re