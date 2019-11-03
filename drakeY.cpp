//Drake Young
//Group Name: ic_daemons
//Instructor: Gordon Griesel
//3350
//date:    fall 2019
//
//Description: Location for My code 
//added to segFault group project
//
//NOTES: WIP
//
//Four Steps of debugging
//1. Identify -Find the source of bug
//2. Isolate  -Seperate buggy function from rest of code 
//3. Fix      -Fix faulty code
//4. Test     -Test the fix to ensure no new bugs are created

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include <GL/glx.h>
#include "fonts.h"
#include <iostream>

using namespace std;

//Copied Timers Class to use for my functions
class Timers {
    public:
        double physicsRate;
        double oobillion;
        struct timespec timeStart, timeEnd, timeCurrent, time1, time2;
        struct timespec playTimeBegin;
        struct timespec playTimeEnd;
        struct timespec walkTime;
        Timers() {
            physicsRate = 1.0 / 30.0;
            oobillion = 1.0 / 1e9;
        }
        double timeDiff(struct timespec *start, struct timespec *end) {
            return (double)(end->tv_sec - start->tv_sec ) +
                (double)(end->tv_nsec - start->tv_nsec) * oobillion;
        }
        void timeCopy(struct timespec *dest, struct timespec *source) {
            memcpy(dest, source, sizeof(struct timespec));
        }
        void recordTime(struct timespec *t) {
            clock_gettime(CLOCK_REALTIME, t);
        }
} timers2;


//Funtion to draw my nane for the credits.
void drawDY_Credits(int x, int y)
{
    Rect D;
    
    unsigned int c = 0x00ffff44;

    D.bot = y;   
    D.left = x;
    D.center = 0;

    ggprint8b(&D, 0, c, "Drake Young");
}

//This Function is called in 
void beginTime()
{
     timers2.recordTime(&timers2.playTimeBegin);
}

//Function to record time played
int playTime(int x, int y)
{

    Rect D;
    unsigned int c = 0x00ffff44;

    D.bot = y;
    D.left = x;
    D.center = 0;
    timers2.recordTime(&timers2.playTimeEnd);

	int minutesPlayed;
    int secondsCounter;

    double timeSpan = timers2.timeDiff(&timers2.playTimeBegin, 
    &timers2.playTimeEnd);
    timeSpan = timeSpan + secondsCounter;
    minutesPlayed = round(timeSpan/60);
    cout << "Time: " << timeSpan << endl;
    ggprint8b(&D, 0, c,  "Time: %i", (int)timeSpan);

    return minutesPlayed;
}

