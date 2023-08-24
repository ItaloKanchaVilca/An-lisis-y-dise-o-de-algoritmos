#include <iostream>
using namespace std;

int gVect[100];  
int gnCount = 0; 

void Insert(int elem)
{
    if (gnCount < 100)
        gVect[gnCount++] = elem; 
}

int main()
{
    Insert(1);
    Insert(2);
    Insert(3);
    Insert(4);
    Insert(5);


    cout << "Insertamos los elementos en gVect: ";
    for (int i = 0; i < gnCount; i++)
    {
        cout << gVect[i] << " ";
    }
    cout <<endl;

    return 0;
}
