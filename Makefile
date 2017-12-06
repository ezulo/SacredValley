SRC_DIR := src
OBJ_DIR := build
OBJS = $(patsubst %, ${OBJ_DIR}/%, main.o Game.o EventDispatcher.o StateMgr.o InputMgr.o ResourceMgr.o GameState.o RedCircle.o)
CC = g++
DEBUG = -g
CFLAGS = -std=c++11 -c ${DEBUG}
LFLAGS = ${SFML} ${DEBUG}
SFML = -lsfml-graphics -lsfml-window -lsfml-system 

my_game: ${OBJS}
	@echo ${OBJS}
	${CC} ${OBJS} -o my_game ${LFLAGS} 	

${OBJ_DIR}/main.o: $(patsubst %, ${SRC_DIR}/%, main.cpp Game.h)
	${CC} ${CFLAGS} ${SRC_DIR}/main.cpp -o $@

${OBJ_DIR}/Game.o: $(patsubst %, ${SRC_DIR}/%, Game.cpp util/EventDispatcher.h util/StateMgr.h util/InputMgr.h util/ResourceMgr.h)
	${CC} ${CFLAGS} ${SRC_DIR}/Game.cpp -o $@

${OBJ_DIR}/ResourceMgr.o: $(patsubst %, ${SRC_DIR}/%, util/ResourceMgr.cpp )
	${CC} ${CFLAGS} ${SRC_DIR}/util/ResourceMgr.cpp -o $@

${OBJ_DIR}/EventDispatcher.o: $(patsubst %, ${SRC_DIR}/%, util/EventDispatcher.cpp util/EventDispatcher.h)
	${CC} ${CFLAGS} ${SRC_DIR}/util/EventDispatcher.cpp -o $@

${OBJ_DIR}/StateMgr.o: $(patsubst %, ${SRC_DIR}/%, util/StateMgr.cpp util/InputMgr.h states/GameState.h states/RedCircle.h)
	${CC} ${CFLAGS} ${SRC_DIR}/util/StateMgr.cpp -o $@

${OBJ_DIR}/InputMgr.o: $(patsubst %, ${SRC_DIR}/%, util/InputMgr.cpp util/InputMgr.h)
	${CC} ${CFLAGS} ${SRC_DIR}/util/InputMgr.cpp -o $@

${OBJ_DIR}/GameState.o: $(patsubst %, ${SRC_DIR}/%, states/GameState.cpp util/InputMgr.h)
	${CC} ${CFLAGS} ${SRC_DIR}/states/GameState.cpp -o $@

${OBJ_DIR}/RedCircle.o: $(patsubst %, ${SRC_DIR}/%, states/RedCircle.cpp states/GameState.h)
	${CC} ${CFLAGS} ${SRC_DIR}/states/RedCircle.cpp -o $@
