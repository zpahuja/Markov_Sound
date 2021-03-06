

#include "sin_wave.h"
#include <stdio.h>
#include <math.h>
#define PI 3.14159265


void init(sin_wave * wave, float amp, float ph, float freq)
{
	wave->amplitude = amp;
	wave->phase = ph;
	wave->frequency = freq;
}


//sets overtone to the harmonic of the fundamental wave
//Check it: http://en.wikipedia.org/wiki/Harmonic
//any harmonic >= 2 is accepted
//overtone must have space allocated for it
//fundamental must be 
void harmonic(sin_wave * overtone, sin_wave * fundamental, int harmonic)
{
	overtone->amplitude = fundamental->amplitude / (float) harmonic;
	overtone->phase = fundamental->phase;
	overtone->frequency = fundamental->frequency * (float) harmonic;
}


float sample(sin_wave * wave, float time)
{
//	printf("time: %f\n", time);
	return wave->amplitude * sin(2*PI*wave->frequency*time + wave->phase);
}

