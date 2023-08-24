#include <iostream>
using namespace std;

class CVector {
private:
    int* m_pVect; 
    int m_nCount;
    int m_nMax; 
    int m_nDelta; 

    void Init(int delta); 
    void Resize(); 

public:
    CVector(int delta = 10); // Constructor
    ~CVector(); // Destructor
    CVector(const CVector& other); 
    CVector& operator=(const CVector& other); 

    void Insert(int elem); 
    void Print(); 
};

CVector::CVector(int delta) 
{
    Init(delta);
}

CVector::~CVector() 
{
    delete[] m_pVect;
}

CVector::CVector(const CVector& other) 
{
    Init(other.m_nDelta);
    m_nCount = other.m_nCount;
    for (int i = 0; i < m_nCount; ++i) 
    {
        m_pVect[i] = other.m_pVect[i];
    }
}

CVector& CVector::operator=(const CVector& other) 
{
    if (this != &other) 
    {
        delete[] m_pVect;
        Init(other.m_nDelta);
        m_nCount = other.m_nCount;
        for (int i = 0; i < m_nCount; ++i) 
        {
            m_pVect[i] = other.m_pVect[i];
        }
    }
    return *this;
}

void CVector::Init(int delta) 
{
    m_nCount = 0;
    m_nMax = delta;
    m_nDelta = delta;
    m_pVect = new int[m_nMax];
}

void CVector::Resize() 
{
    m_nMax += m_nDelta;
    int* newVect = new int[m_nMax];
  
    for (int i = 0; i < m_nCount; ++i) 
    {
        newVect[i] = m_pVect[i];
    }
    delete[] m_pVect;
    m_pVect = newVect;
}

void CVector::Insert(int elem) 
{
    if (m_nCount == m_nMax) 
    {
        Resize();
    }
  
    m_pVect[m_nCount++] = elem;
}

void CVector::Print() 
{
    for (int i = 0; i < m_nCount; ++i) 
    {
        cout << m_pVect[i] << " ";
    }
  
    cout <<endl;
}

int main() 
{
    CVector vec;
    for (int i = 0; i < 30; ++i) 
    {
        vec.Insert(i);
    }

    cout << "Vector elements: ";
    vec.Print();

    return 0;
}
