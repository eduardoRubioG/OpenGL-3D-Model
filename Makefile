COMP = g++
LIBDIRS = -L/usr/lib64
INCDIRS = -I/usr/include
LDLIBS =  -lGL -lGLU -lglut -lX11 -lm
OBJS = animation.o views.o house.o input.o menu.o axes.o init.o text.o 
HEADERS = globals.h include.h

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	CCFLAG = -D LINUX 
endif 

ifeq ($(UNAME_S),Darwin)
	CCFLAG = -D OSX 
endif


main : main.o $(OBJS) 
	$(COMP) $(CCFLAG) main.o -o main $(OBJS) $(LDLIBS) 

main.o : main.cpp $(HEADERS) 
	$(COMP) $(CCFLAG) -c main.cpp 

animation.o : animation.cpp $(HEADERS)
	$(COMP) $(CCFLAG) -c animation.cpp	

views.o : views.cpp $(HEADERS) 
	$(COMP) $(CCFLAG) -c views.cpp 

house.o : house.cpp $(HEADERS) 
	$(COMP) $(CCFLAG) -c house.cpp 

input.o : input.cpp $(HEADERS) 
	$(COMP) $(CCFLAG) -c input.cpp 

menu.o : menu.cpp $(HEADERS) 
	$(COMP) $(CCFLAG) -c menu.cpp 

axes.o : axes.cpp $(HEADERS) 
	$(COMP) $(CCFLAG) -c axes.cpp 

init.o : init.cpp $(HEADERS) 
	$(COMP) $(CCFLAG) -c init.cpp 

text.o : text.cpp $(HEADERS) 
	$(COMP) $(CCFLAG) -c text.cpp 

clean : 
	rm *.o

pristine : 
	rm *.o 
	touch *.c, *.h 
	rm main
