#include <string>
#include <cstdlib>
#include <sys/time.h>

using namespace std;

//=========================================================================================
//		CODE FOR TIME EVALUATION --- DON'T DWELL INTO IT :P
//=========================================================================================
struct timeval t1, t2;
struct timezone tz;

void startTimer()
{
	gettimeofday(&t1, &tz);
}

int stopTimer()
{
	gettimeofday(&t2, &tz);
	return 1000000*(t2.tv_sec - t1.tv_sec) + t2.tv_usec - t1.tv_usec;
}

// call "startTimer()" to start timer
// call "stopTimer()" to stop timer and return total time in microseconds.
