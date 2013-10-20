EXE= MarkovSound
OBJS = alsa_main.o sin_wave.o
COMPILER = g++
COMPILER_OPTS = -c -g -O0 -Wall
LINKER = g++
LINKER_OPTS = -lpng

all : $(EXE)

$(EXE) : $(OBJS)
	$(LINKER) $(OBJS) $(LINKER_OPTS) -o $(EXE)
#testscene will need its own exename,objects, linke through $(EXE)

alsa_main.o : alsa_main.cpp
	$(COMPILER) $(COMPILER_OPTS) alsa_main.cpp

sin_wave.o : sin_wave.cpp sin_wave.h
	$(COMPILER) $(COMPILER_OPTS) sin_wave.cpp

clean :
	-rm -f *.o *gch $(EXE)