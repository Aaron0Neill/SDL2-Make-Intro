INCLUDE := "-IC:\SDL2-2.0.16\i686-w64-mingw32\include\SDL2" "-I.\include" "-IC:\SFML-2.5.1\include"
LIB 	:= "-LC:\SDL2-2.0.16\i686-w64-mingw32\lib" "-LC:\SFML-2.5.1\lib"
OUTPUT_NAME	:= "mainFile"
COMP_FILES	:= "./src/*.cpp"
DLL			:= "-lmingw32" "-lSDL2main" "-lSDL2" "-lSDL2_image" "-"

BUILD_DIR 	:= ./bld

MSG_START	:= "Build Started"
MSG_END 	:= "Build Complete"
MSG_CLEAN	:= "Cleaning Up"

all			:= build

build:
	@echo ${MSG_START}

	rm -rf ${BUILD_DIR} || true

	mkdir ${BUILD_DIR}

	g++ -o  ${BUILD_DIR}/${OUTPUT_NAME} ${COMP_FILES} ${INCLUDE} ${LIB} ${DLL}
	@echo ${MSG_END}
