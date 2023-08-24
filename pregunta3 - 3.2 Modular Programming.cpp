#include <iostream>
#include <cstdlib> 

using namespace std;

struct Vector
{
    int* m_pVect; 
    int m_nCount; 
    int m_nMax;   
    int m_nDelta;
};

void Init(Vector* pThis, int delta);
void Cleanup(Vector* pThis);
void Insert(Vector* pThis, int elem);
void ResizeVector(Vector* pThis);

void Init(Vector* pThis, int delta)
{
    pThis->m_pVect = nullptr;
    pThis->m_nCount = 0;
    pThis->m_nMax = 0;
    pThis->m_nDelta = delta;
}

void Cleanup(Vector* pThis)
{
    free(pThis->m_pVect);
    pThis->m_pVect = nullptr;
    pThis->m_nCount = 0;
    pThis->m_nMax = 0;
}

void Insert(Vector* pThis, int elem)
{
    if (pThis->m_nCount == pThis->m_nMax)
    {
        ResizeVector(pThis); 
    }
  
    pThis->m_pVect[pThis->m_nCount++] = elem;
}

void ResizeVector(Vector* pThis)
{
    int newMax = pThis->m_nMax + pThis->m_nDelta;
    pThis->m_pVect = (int*)realloc(pThis->m_pVect, sizeof(int) * newMax);
    
    if (pThis->m_pVect == nullptr)
    {
        cerr << "Error al redimensionar el vector" << endl;
        exit(1); 
    }
    
    pThis->m_nMax = newMax;
}

int main()
{
    Vector myVector;
    Init(&myVector, 10);
    
    for (int i = 0; i < 30; i++)
    {
        Insert(&myVector, i);
    }
    
    for (int i = 0; i < myVector.m_nCount; i++)
    {
        cout << myVector.m_pVect[i] << " ";
    }
    
    Cleanup(&myVector); 
    
    return 0;
}
