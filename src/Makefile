OBJS = main.o Game.o EventDispatcher.o FrameMgr.o InputMgr.o RedCircle.o
CC = g++
DEBUG = -g
CFLAGS = -std=c++11 -c ${DEBUG}
LFLAGS = ${SFML} ${DEBUG}
OBJDIR = build
SFML = -lsfml-graphics -lsfml-window -lsfml-system 

my_game: ${OBJS}
	${CC} ${OBJS} -o my_game ${LFLAGS} 	
	
main.o: main.cpp Game.h
	${CC} ${CFLAGS} main.cpp

Game.o: Game.cpp Game.h util/EventDispatcher.h util/FrameMgr.h util/InputMgr.h
	${CC} ${CFLAGS} Game.cpp

EventDispatcher.o: util/EventDispatcher.cpp util/EventDispatcher.h 
	${CC} ${CFLAGS} util/EventDispatcher.cpp

FrameMgr.o: util/FrameMgr.cpp util/FrameMgr.h util/InputMgr.h frames/GameFrame.h frames/RedCircle.h
	${CC} ${CFLAGS} util/FrameMgr.cpp

InputMgr.o: util/InputMgr.cpp util/InputMgr.h
	${CC} ${CFLAGS} util/InputMgr.cpp

GameFrame.o: frames/GameFrame.cpp frames/GameFrame.h util/InputMgr.h
	${CC} ${CFLAGS} frames/GameFrame.cpp

RedCircle.o: frames/RedCircle.cpp frames/RedCircle.h frames/GameFrame.h
	${CC} ${CFLAGS} frames/RedCircle.cpp
