CC = g++

# C++ 컴파일러 옵션
#CXXFLAGS = -Wall -O2
CXXFLAGS = 

# 링커 옵션
LDFLAGS =

# 소스 파일 디렉토리
SRC_DIR = ./src

# 오브젝트 파일 디렉토리
OBJ_DIR = ./obj

# 생성하고자 하는 실행 파일 이름
TARGET = main.exe

run: all
	$(TARGET)

#solution.o : solution.cpp solution.h
#	$(CC) $(CXXFLAGS) -c solution.cpp

#main.o : main.cpp solution.h
#	$(CC) $(CXXFLAGS) -c main.cpp

all: solution.cpp main.cpp
	$(CC) $(CXXFLAGS) -o $(TARGET) solution.cpp main.cpp
#all: solution.o main.o
#	$(CC) $(CXXFLAGS) -o $(TARGET) solution.o main.o

clean:
	rm \*.o main.exe