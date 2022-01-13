include ../makefile.defs

INCLUDE_DIRS = -I/home/rao/code/demo/icc_make/include
C_FILES = main.c test.c
C_FLAGS = -g -c 
TARGET = c_file.p

OBJ_FILES = $(patsubst %.c,%.o,$(C_FILES))
all: $(TARGET) 

$(TARGET): $(OBJ_FILES)

%.o: %.c
	icc  $< -o $@ $(C_FLAGS) $(INCLUDE_DIRS)  

clean:
	rm *.o

