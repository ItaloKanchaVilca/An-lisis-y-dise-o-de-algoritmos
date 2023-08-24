#include <iostream>
using namespace std;

int *gpVect = nullptr;
int gnCount = 0;
int gnMax = 0;

void Resize();

void Insert(int elem)
{
    if (gnCount == gnMax)
        Resize();
  
    gpVect[gnCount++] = elem;
}

void Resize()
{
    const int delta = 10;
    int *newPtr = new int[gnMax + delta];
    
    for (int i = 0; i < gnCount; i++) 
    {
        newPtr[i] = gpVect[i];
    }
    
    delete[] gpVect;
    gpVect = newPtr;
    gnMax += delta;
}

int main()
{
    gpVect = new int[10];
    gnMax = 10;

    for (int i = 0; i < 30; i++) 
    {
        Insert(i);
    }

    for (int i = 0; i < gnCount; i++) 
    {
        cout << gpVect[i] << " ";
    }
    
    delete[] gpVect;

    return 0;
}
