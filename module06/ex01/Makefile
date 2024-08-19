#Basic variable
NAME = ex01
CC = c++ -g3
FLAGS = -Wall -Wextra -Werror -std=c++98
DEPFLAGS = -MMD -MP
RM = rm -rf
LEAK = valgrind --leak-check=full --show-leak-kinds=all

#libraries
INC = -I./include/

#Folders
SRCS_DIR = src/
OBJS_DIR = objs/

#Files source
FILES = main \
		Serialize


OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
DEPS = $(OBJS:.o=.d)

all: $(NAME)

-include $(DEPS)

$(OBJS_DIR)%.o:$(SRCS_DIR)%.cpp | $(OBJS_DIR)
	$(CC) $(FLAGS) $(DEPFLAGS) $(INC) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(INC) -o $(NAME)

run:
	@make
	./$(NAME)

val:
	@make
	$(LEAK) ./$(NAME)

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
