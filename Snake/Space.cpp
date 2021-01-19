#include "Space.h"

Space& Space::Init() {
    // буфер, в который копируем
    ReadConsoleOutput(hStdout, chiBuffer, coordBufSize, coordBufCoord, &ReadArea);
    return *this;
}

Space& Space::Clear() {
    WriteConsoleOutput(
        hStdout, 	// экранный буфер, в который будем записывать
        chiBuffer,        	// буфер, из которого копируем
        coordBufSize,     	// размер колонки/строки chiBuffer
        coordBufCoord,    	// верхн€€ лева€ €чейка источника в chiBuffer
        &ReadArea);  	// пр€моугольник назначени€ экранного буфера
    return *this;
}
