#include <iostream>
#include "String1.h"

using namespace std;

int main() 
{
    String1 stringExample("ESKEREE");
    cout << "Len = " << stringExample.MyStrLen() << endl;
    stringExample.Print();

    stringExample.Input();
    stringExample.Print();

    String1 stringExample2("ESKEREE ? ? ?");

    String1::GetCountLiveObj();
    String1::GetCountCreatedObj();
    return 0;
}