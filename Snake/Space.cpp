#include "Space.h"

Space& Space::Init() {
    // �����, � ������� ��������
    ReadConsoleOutput(hStdout, chiBuffer, coordBufSize, coordBufCoord, &ReadArea);
    return *this;
}

Space& Space::Clear() {
    WriteConsoleOutput(
        hStdout, 	// �������� �����, � ������� ����� ����������
        chiBuffer,        	// �����, �� �������� ��������
        coordBufSize,     	// ������ �������/������ chiBuffer
        coordBufCoord,    	// ������� ����� ������ ��������� � chiBuffer
        &ReadArea);  	// ������������� ���������� ��������� ������
    return *this;
}
