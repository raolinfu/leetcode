MAKE = make
SUBDIRS = cfiles cpfiles
SRC1 = $(wildcard cfiles/*.c)  
SRC2 = $(wildcard cpfiles/*.cpp)  
OBJECT = $(patsubst %.c, %.o, ${SRC1}) 
OBJECT += $(patsubst %.cpp, %.o, ${SRC2}) 


all:
	for dir in $(SUBDIRS);\
	do $(MAKE) -C $$dir $@ || exit 1;\
	done 
	icc $(OBJECT) -o main

clean:
	for dir in $(SUBDIRS);\
	do $(MAKE) -C $$dir $@ || exit 1;\
	done 
