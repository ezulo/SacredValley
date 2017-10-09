OBJS = main.o Game.o Event.o EventDispatcher.o FrameMgr.o GreenCircle.o RedCircle.o
CC = g++
DEBUG = -g
CFLAGS = -c ${DEBUG}
LFLAGS = ${SFML} ${DEBUG}
OBJDIR = build
SFML = -lsfml-graphics -lsfml-window -lsfml-system 

my_game: ${OBJS}
	${CC} ${OBJS} -o my_game ${LFLAGS} 	
	
main.o: main.cpp Game.h
	${CC} ${CFLAGS} main.cpp

Game.o: Game.cpp Game.h EventDispatcher.h FrameMgr.h
	${CC} ${CFLAGS} Game.cpp

Event.o: Event.cpp Event.h
	${CC} ${CFLAGS} Event.cpp
	
EventDispatcher.o: EventDispatcher.cpp EventDispatcher.h Event.h
	${CC} ${CFLAGS} EventDispatcher.cpp

FrameMgr.o: FrameMgr.cpp FrameMgr.h frames/GameFrame.h frames/GreenCircle.h frames/RedCircle.h
	${CC} ${CFLAGS} FrameMgr.cpp

GreenCircle.o: frames/GreenCircle.cpp frames/GreenCircle.h frames/GameFrame.h
	${CC} ${CFLAGS} frames/GreenCircle.cpp

RedCircle.o: frames/RedCircle.cpp frames/RedCircle.h frames/GameFrame.h
	${CC} ${CFLAGS} frames/RedCircle.cpp
