INCLUDE_DIRS = -I/home/rao/code/demo/icc_cpp/include
CPLUS_FILES = apple.cpp AppleWrapper.cpp
CPLUS_FLAGS = -g -c 
OBJ_FILES = $(patsubst %.cpp,%.o,$(CPLUS_FILES))

all: cpp_file.p

cpp_file.p: $(OBJ_FILES)

%.o: %.cpp
	icc  $< -o $@ $(CPLUS_FLAGS) $(INCLUDE_DIRS)  

clean:
	rm *.o

