CXX = g++
CXXFLAGS = -std=c++11 -Wall -I.

TARGET = BinarySearchTree_Lecker_Ian
SRCS = BinarySearchTree_Lecker_Ian.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.pp
	$(CXX) $(CXXFLAGS) -c $<

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
