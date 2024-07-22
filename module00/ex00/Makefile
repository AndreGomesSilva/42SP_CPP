NAME = megaphone
CC = c++ -g3
FLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf
INC = -I .

SRCS_DIR = ./
OBJS_DIR = objs/

FILE = megaphone

OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILE)))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp | $(OBJS_DIR)
	$(CC) $(FLAGS) $(INC) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)
	mkdir -p $(OBJS_DIR)$(EX_DIR)

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
