OBJS	= main.o MainFM.o DVD.o CD.o Midia.o
SOURCE	= main.cpp MainFM.cpp DVD.cpp CD.cpp Midia.cpp
HEADER	= MainFM.h DVD.h CD.h Midia.h
OUT	= main.exe
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)
main.o: main.cpp
	$(CC) $(FLAGS) main.cpp
MainFM.o: MainFM.cpp
	$(CC) $(FLAGS) MainFM.cpp 

DVD.o: DVD.cpp
	$(CC) $(FLAGS) DVD.cpp 

CD.o: CD.cpp
	$(CC) $(FLAGS) CD.cpp 

Midia.o: Midia.cpp
	$(CC) $(FLAGS) Midia.cpp 


clean:
	rm -f $(OBJS) $(OUT)
