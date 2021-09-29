SDL_Include := "C:\SDL2-2.0.16\i686-w64-mingw32\include\SDL2"
SDL_Lib 	:= "C:\SDL2-2.0.16\i686-w64-mingw32\lib"
fileName 	:= "mainFile"
files 		:= "main.cpp" "game.cpp" "player.cpp"

all:
	@echo "Starting Build"
	g++ -I${SDL_Include} -L${SDL_Lib} -o ${fileName} ${files} -lmingw32 -lSDL2main -lSDL2
	@echo "Finishing"