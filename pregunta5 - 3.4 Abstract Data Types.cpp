#include <iostream>
using namespace std;

template <typename Type>
class CVector 
{
private:
    Type* m_pVect;
    int m_nCount; 
    int m_nMax; 
    int m_nDelta; 
    void Init(int delta); 
    void Resize(); 

public:
    CVector(int delta = 10); 
    ~CVector(); 
    void Insert(Type elem); 
    Type& operator[](int index); 
    int Size() const;
};

template <typename Type>
CVector<Type>::CVector(int delta)
{
    Init(delta);
}

template <typename Type>
CVector<Type>::~CVector() 
{
    delete[] m_pVect; 
}

template <typename Type>

void CVector<Type>::Init(int delta) 
{
    m_nCount = 0;
    m_nMax = delta;
    m_nDelta = delta;
    m_pVect = new Type[m_nMax];
}

template <typename Type>

void CVector<Type>::Resize()
{
    int newMax = m_nMax * 2;
    Type* newVect = new Type[newMax];
    for (int i = 0; i < m_nCount; i++)
    {
        newVect[i] = m_pVect[i];
    }
    delete[] m_pVect; 
    m_pVect = newVect;
    m_nMax = newMax;
}

template <typename Type>

void CVector<Type>::Insert(Type elem)
{
    if (m_nCount == m_nMax) 
    {
        Resize(); 
    }
    m_pVect[m_nCount++] = elem; 
}

template <typename Type>

Type& CVector<Type>::operator[](int index) 
{
    if (index >= 0 && index < m_nCount) 
    {
        return m_pVect[index];
    }

}

template <typename Type>

int CVector<Type>::Size() const 
{
    return m_nCount; 
}

int main() 
{
    CVector<int> myVector;
  
    myVector.Insert(1);
    myVector.Insert(2);
    myVector.Insert(3);
    myVector.Insert(4);
    myVector.Insert(5);
    myVector.Insert(6);
    myVector.Insert(7);

    cout << "tamaño del vector: " << myVector.Size() <<endl;
    cout << "primer elemento: " << myVector[0] <<endl;
    cout << "segundo elemento: " << myVector[1] <<endl;
    
    return 0;
}
