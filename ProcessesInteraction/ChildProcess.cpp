#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <fstream>

using namespace std;

int main() {

    int value1, value2;

    ReadFile(GetStdHandle(STD_INPUT_HANDLE), &value1, sizeof(value1), NULL, NULL);
    ReadFile(GetStdHandle(STD_INPUT_HANDLE), &value2, sizeof(value2), NULL, NULL);

    cout << "value1 + value2 = " << value1 + value2 << endl;

    return 0;
}
