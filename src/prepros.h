#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"
#include "global.h"
#ifdef LINUX
    void getch(void) {
        system("read b");
    }
#elif defined WIN32
    void getch(void) {
        system("@pause>nul");
    }
#else
    void getch(void) {
        system("read b");
    }
#endif
void console_clear(void) {
    #ifdef LINUX
        system("clear");
    #elif defined WIN32
        system ("cls");
    #else
        system("clear");
    #endif
    printf("\nBuild date: %s %s\n", __DATE__, __TIME__);
}