#include "magic.h"
#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
#define el "\n"
using namespace std;

void delay(int milliseconds) 
{
#ifdef _WIN32
    Sleep(milliseconds);
#else
    usleep(milliseconds*1000);
#endif
}

void clearScreen() 
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

namespace Colors 
{
    const string RESET="\033[0m";
    const string MAGENTA="\033[95m";
    const string LIGHT_MAGENTA="\033[35;1m";
    const string WHITE_ON_MAGENTA="\033[97;105m";
    const string BOLD="\033[1m";
}

void initializeMagicSquare(int n) 
{
    clearScreen();
    cout<<Colors::MAGENTA<<Colors::BOLD;
    cout<<"=== "<<n<<"x"<<n<<" MAGIC SQUARE ==="<<Colors::RESET<<el<<el;
    for(int i=0; i<n; i++) 
    {
        for(int j=0; j<n; j++) 
        {
            cout<<Colors::MAGENTA<<"+---"<<Colors::RESET;
        }
        cout<<Colors::MAGENTA<<"+"<<Colors::RESET<<el;
        for(int j = 0; j < n; j++) 
        {
            cout<<Colors::MAGENTA<<"|   "<< Colors::RESET;
        }
        cout<<Colors::MAGENTA<<"|"<<Colors::RESET<<el;
    }
    for(int j=0; j<n; j++) 
    {
        cout<<Colors::MAGENTA<<"+---"<<Colors::RESET;
    }
    cout<<Colors::MAGENTA<<"+"<<Colors::RESET<<el<<el;
}

void generateMagicSquareWithDelay(int n) 
{
    if(n%2==0) 
    {
        cout<<Colors::LIGHT_MAGENTA << "\nNote: Only odd numbers create perfect magic squares using this method!"<<Colors::RESET << el;
        delay(2000);
    }
    int r=0;
    int c=n/2;
    int gridLines=n*2+3;
    for(int i=0; i<gridLines; i++) 
        cout << "\033[A";

    for(int num=1; num<=n * n; num++) 
    {
        int cursorRow=3+(r*2);
        int cursorCol=2+(c*4);
        cout<<"\033["<<cursorRow<<";"<<cursorCol<<"H";
        cout<<Colors::WHITE_ON_MAGENTA<<setw(3)<<num<<Colors::RESET;
        cout.flush();
        delay(370);
        cout<<"\033["<<cursorRow<<";"<<cursorCol<<"H";
        cout<<Colors::MAGENTA<<setw(3)<<num<<Colors::RESET;
        cout.flush();
        int nextRow=(r-1+n)%n;
        int nextCol=(c+1)%n;
        if(num%n==0)
            r=(r+1)%n;
        else 
            r=nextRow, c=nextCol;
    }
    cout<<"\033["<<(n*2+5)<<";0H";
    cout<<Colors::LIGHT_MAGENTA<<Colors::BOLD;
    int magicNo=n*(n*n+1)/2;
    cout<<"✨Magic number is: "<<magicNo<<el;
    cout<<Colors::MAGENTA<<"✨Bravo ya Shahooda, ILY!"<<Colors::RESET<<el;
}
void cleanup() 
{
    cout << Colors::RESET;
}
