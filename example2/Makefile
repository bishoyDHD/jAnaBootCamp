# the compiler: gcc for C program, define as g++ for C++
CXX = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CXXFLAGS  = -g -Wall

# the build target executable:
TARGET = advMap

all: $(TARGET)

$(TARGET): $(TARGET).cxx
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(TARGET).cxx

clean:
	$(RM) $(TARGET)
