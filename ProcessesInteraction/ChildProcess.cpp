#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <fstream>

using namespace std;

int main1() {

    int value1, value2;

    cout << GetStdHandle(STD_INPUT_HANDLE) << endl; 
    cout << GetStdHandle(STD_OUTPUT_HANDLE) << endl; 

  
    ofstream output;
    output.open("test.txt");

    ReadFile(GetStdHandle(STD_INPUT_HANDLE));
    output << 1;


    output.close();
    system("pause");
    return 0;
}