#include <iostream>
using namespace std;

struct Vector
{
    int* m_pVect;
    int m_nCount;
    int m_nMax;
    int m_nDelta;
};

void Resize(Vector* pThis)
{
    pThis->m_pVect = (int*)realloc(pThis->m_pVect, sizeof(int) * (pThis->m_nMax + pThis->m_nDelta));
    pThis->m_nMax += pThis->m_nDelta;
}

void Insert(Vector* pThis, int elem)
{
    if (pThis->m_nCount == pThis->m_nMax)
    {
        Resize(pThis);
    }
    pThis->m_pVect[pThis->m_nCount++] = elem;
}

int main()
{
    Vector* a = new Vector;
    a->m_nCount = 0;
    a->m_nMax = 10;
    a->m_nDelta = 10;
    a->m_pVect = (int*)malloc(sizeof(int) * a->m_nMax);

    for (int i = 0; i < 20; i++)
    {
        Insert(a, i);
    }
  return 0;
}