#include <conio.h>
#include "inc/fmod.h"

FSOUND_SAMPLE* handle;

int main () {
    FSOUND_Init (44100, 32, 0); 
    load and play mp3 handle = FSOUND_Sample_Load (0,"my.mp3",0, 0, 0);
    FSOUND_PlaySound (0,handle); 
    
    while (!_kbhit()) {

    }
    FSOUND_Sample_Free (handle);
    FSOUND_Close();
    
}

