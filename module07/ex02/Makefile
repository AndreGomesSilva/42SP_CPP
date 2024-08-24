NAME = ex02
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf
INC = -I ./
LEAK = valgrind --leak-check=full --show-leak-kinds=all

SRCS_DIR = ./
OBJS_DIR = objs/

FILE = main \

OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILE)))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp | $(OBJS_DIR)
	$(CC) $(FLAGS) $(INC) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

val:
	@make
	@$(LEAK) ./$(NAME)

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
