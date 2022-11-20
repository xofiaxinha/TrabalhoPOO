OBJS	= ajeitanoFunsao.o func.o DVD.o CD.o midia.o
SOURCE	= ajeitanoFunsao.cpp func.cpp DVD.cpp CD.cpp midia.cpp
HEADER	= func.h DVD.h CD.h midia.h
OUT	= main.exe
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

ajeitanoFunsao.o: ajeitanoFunsao.cpp
	$(CC) $(FLAGS) ajeitanoFunsao.cpp 

func.o: func.cpp
	$(CC) $(FLAGS) func.cpp 

DVD.o: DVD.cpp
	$(CC) $(FLAGS) DVD.cpp 

CD.o: CD.cpp
	$(CC) $(FLAGS) CD.cpp 

midia.o: midia.cpp
	$(CC) $(FLAGS) midia.cpp 


clean:
	rm -f $(OBJS) $(OUT)
