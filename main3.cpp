#include "magic.h"
#include <iostream>
#include <string>
#include <cctype>
#define el '\n'
using namespace std;

bool isNumber(const string &s) 
{
    if(s.empty()) 
        return 0;
    for(char c:s)
        if(!isdigit(c))return 0;
    return 1;
}

int main() 
{
    int n;
    string input;
    cout<<"=== SHAHOODA'S MAGIC GRID ==="<<el;
    bool ok=0;
    while(!ok) 
    {
        cout<<"Enter size of magic square (odd number, >=3):";
        getline(cin, input);
        if(!isNumber(input)) 
        {
            cout<<"Invalid input! Please enter a number."<<el;
            continue;
        }
        n=stoi(input);
        if(n<3) 
        {
            cout<<"Please enter a number greater than or equal to 3!"<<el;
            continue;
        }
        ok=1;
    }
    if(n%2==0) 
    {
        cout<<"Note: Odd numbers work best with this algorithm!"<<el;
        cout<<"But we'll try anyway..."<<el;
    }
    cout<<"\nGenerating "<<n<<" x "<<n<<" Magic Square..."<<el;
    cout<<"Watch the numbers appear one by one!"<<el;
    delay(2000);
    initializeMagicSquare(n);
    generateMagicSquareWithDelay(n);
    cout<<"\nPress Enter to exit...";
    cin.ignore();
    cin.get();
    cleanup();
    return 0;
}
