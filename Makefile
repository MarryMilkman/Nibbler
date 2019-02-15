# Name of the program
NAME	:= Nibbler

# Directories
OBJ_DIR	:= ./obj/
SRC_DIR	:= ./src/
INC_DIR := ./inc/

# Source and object files
SRC		:= main.cpp Object.cpp
OBJ		:= $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

# Header files
INC	:= lib.h

STATIC_LIB_SDL2 := ./dlib_tmp/dl_sdl2.a
PATH_INC_SDL2 := ./dlib/dl_SDL2/

# Compiler and flags
CC		:= g++
FLAGS	:= -std=c++11 #-Wall -Wextra -Werror 

# Compile and link the program
all: get_lib obj_dir $(NAME)

get_lib:
	@make -C $(PATH_INC_SDL2)

# Link object files into the executable
$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) -I$(PATH_INC_SDL2) -I$(INC_DIR)  $(STATIC_LIB_SDL2) -I ~/.brew/include -L ~/.brew/lib -lSDL2 -lSDL2_image -lSDL2_ttf

# Compile object files from source files
$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	$(CC) $(FLAGS) -o $@ -c $< -I$(INC_DIR) -I$(PATH_INC_SDL2) -I ~/.brew/include -L ~/.brew/lib -lSDL2 -lSDL2_image -lSDL2_ttf

# Create a directory for object files
obj_dir:
	@mkdir -p $(OBJ_DIR)

# Delete object files
clean:
	rm -rf $(OBJ_DIR)

# Delete all files created with the Makefile
fclean: clean
	rm -f $(NAME)

# Re-make all files
re: fclean all

# GNU will run even if files have names as instructions
.PHONY: all clean fclean re
