NAME_LIB	:= dl_sdl2.a

SRC = Use_SDL2.cpp

INC_DIR = ../../inc/

OBJ_DIR = ./obj/

CFLAGS = -std=c++11 #-Wall -Wextra -Werror

TMP_DIR = ../../dlib_tmp/


all: $(NAME_LIB)

$(NAME_LIB):
	# g++ $(CFLAGS) -shared -fPIC -o $(NAME_LIB) $(SRC) -I $(INC_DIR) -I ~/.brew/include -L ~/.brew/lib -lSDL2 -lSDL2_image -lSDL2_ttf -rpath ~/.brew/lib
	g++ $(CFLAGS) -c $(SRC) -I $(INC_DIR) -I ~/.brew/include -L ~/.brew/lib -lSDL2 -lSDL2_image -lSDL2_ttf
	mkdir $(OBJ_DIR); mv $(SRC:.cpp=.o) $(OBJ_DIR)
	ar rc $(NAME_LIB) $(OBJ_DIR)$(SRC:.cpp=.o)
	ranlib $(NAME_LIB)
	mv $(NAME_LIB) ../../dlib_tmp

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(TMP_DIR)$(NAME_LIB)

re: fclean all
