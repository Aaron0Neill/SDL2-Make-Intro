SDL_INCLUDE := "C:\SDL2-2.0.16\i686-w64-mingw32\include\SDL2"
SDL_LIB 	:= "C:\SDL2-2.0.16\i686-w64-mingw32\lib" 
OUTPUT_NAME	:= "mainFile"
COMP_FILES	:= "./src/main.cpp" "./src/game.cpp" "./src/player.cpp"
DLL			:= "-lmingw32" "-lSDL2main" "-lSDL2"

BUILD_DIR 	:= ./build

MSG_START	:= "Build Started"
MSG_END 	:= "Build Complete"
MSG_CLEAN	:= "Cleaning Up"

all			:= build

build:
	@echo ${MSG_START}

	rm -rf ${BUILD_DIR} || true

	mkdir ${BUILD_DIR}

	g++ -o  ${BUILD_DIR}/${OUTPUT_NAME} ${COMP_FILES} -I${SDL_INCLUDE} -L${SDL_LIB} ${DLL}
	@echo ${MSG_END}
