#include <iostream>
using namespace std;

template <typename Type> class CVector
{
private:
    Type* m_pVect;
    int m_nCount;
    int m_nMax;
    int m_nDelta;

    void Resize()
    {
        Type* new_pVect = new Type[m_nMax + m_nDelta];
        
        for (int i = 0; i < m_nCount; i++)
        {
            new_pVect[i] = m_pVect[i];
        }

        delete[] m_pVect;

        m_pVect = new_pVect;
        m_nMax += m_nDelta;
    }

public:
    CVector(int delta = 10)
    {
        m_pVect = new Type[delta];
        m_nCount = 0;
        m_nMax = delta;
        m_nDelta = delta;
    }

    void Insert(Type elem)
    {
        if (m_nCount == m_nMax)
            Resize();
        m_pVect[m_nCount++] = elem;
    }

    ~CVector()
    {
        delete[] m_pVect;
    }
};

int main()
{
    CVector<int> a;
    for (int i = 0; i < 20; i++)
    {
        a.Insert(i);
    }
  return 0;
}
