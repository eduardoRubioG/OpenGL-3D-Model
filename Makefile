COMP = g++
LIBDIRS = -L/usr/lib64
INCDIRS = -I/usr/include
LDLIBS =  -lglut -lGL -lGLU -lX11 -lm

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	CCFLAG = -D LINUX 
endif 

ifeq ($(UNAME_S),Darwin)
	CCFLAG = -D OSX 
endif

.cpp:
	$(COMP) $(CCFLAG) -O $@.cpp -g $(INCDIRS) $(LIBDIRS) $(LDLIBS) -o $@
