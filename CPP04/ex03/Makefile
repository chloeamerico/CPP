NAME = Interface

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I.
SRC_DIR = srcs
OBJ_DIR = obj
INC_DIR = includes


SRCS = $(SRC_DIR)/AMateria.cpp \
       $(SRC_DIR)/Character.cpp \
	   $(SRC_DIR)/Cure.cpp \
	   $(SRC_DIR)/Ice.cpp \
	   $(SRC_DIR)/MateriaSource.cpp \
	   $(SRC_DIR)/main.cpp \

OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re