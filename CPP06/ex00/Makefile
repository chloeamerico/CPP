NAME = Intern

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I.
SRC_DIR = srcs
OBJ_DIR = obj
INC_DIR = includes


SRCS = $(SRC_DIR)/Bureaucrat.cpp \
	   $(SRC_DIR)/AForm.cpp \
	   $(SRC_DIR)/main.cpp \
	   $(SRC_DIR)/Intern.cpp \
	   $(SRC_DIR)/PresidentialPardonForm.cpp \
	   $(SRC_DIR)/RobotomyRequestForm.cpp \
	   $(SRC_DIR)/ShrubberyCreationForm.cpp \

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