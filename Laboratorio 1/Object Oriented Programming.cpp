#include <iostream>
using namespace std;

class CVector
{
private:
    int* m_pVect;
    int m_nCount;
    int m_nMax;
    int m_nDelta;
    void Resize();
    
public:
    CVector(int delta = 10);
    ~CVector();
    void Insert(int elem);
};

CVector::CVector(int delta)
{
    m_pVect = new int[delta];
    m_nCount = 0;
    m_nMax = delta;
    m_nDelta = delta;
}

// Destructor de la clase
CVector::~CVector()
{
    delete[] m_pVect;
}

void CVector::Insert(int elem)
{
    if (m_nCount == m_nMax)
        Resize();
    m_pVect[m_nCount++] = elem;
}

void CVector::Resize()
{
    int* new_pVect = new int[m_nMax + m_nDelta];
    
    for (int i = 0; i < m_nCount; i++)
    {
        new_pVect[i] = m_pVect[i];
    }

    delete[] m_pVect;
    
    m_pVect = new_pVect;
    m_nMax += m_nDelta;
}

int main()
{
    CVector a;
    for (int i = 0; i < 20; i++)
    {
        a.Insert(i);
    }
  return 0;
}