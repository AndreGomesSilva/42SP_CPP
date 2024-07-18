NAME = replaceWord
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf
INC = -I ./
LEAK = valgrind --leak-check=full --show-leak-kinds=all
ARGS = "test.txt" "filename" ">>abacate123"

SRCS_DIR = ./
OBJS_DIR = objs/

FILE = main \
			 Replace 

OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILE)))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp | $(OBJS_DIR)
	$(CC) $(FLAGS) $(INC) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)
	mkdir -p $(OBJS_DIR)$(EX_DIR)

run:
	@make
	@./$(NAME) $(ARGS)

val:
	@make
	@$(LEAK) ./$(NAME) $(ARGS)	

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
