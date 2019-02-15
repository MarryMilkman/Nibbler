NAME = zalupa

SRC = main.cpp Object.cpp Use_SDL2.cpp

CFLAGS = #-Wall -Wextra -Werror


all:
	g++ -std=c++11 $(SRC) -o zalupa -I ~/.brew/include -L ~/.brew/lib -lSDL2 -lSDL2_image -lSDL2_ttf

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all