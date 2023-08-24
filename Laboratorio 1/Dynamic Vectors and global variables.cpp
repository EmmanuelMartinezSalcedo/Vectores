#include <iostream>
using namespace std;

int *Vector = NULL;
int Count = 0;
int Max = 0;

void Resize()
{
  const int delta = 10;
  int *pTemp, i;
  pTemp = new int[Max + delta];
  for(i = 0 ; i < Max ; i++)
    {
      pTemp[i] = Vector[i];
    }
  delete [ ] Vector;
  Vector = pTemp;
  Max += delta;
}
void Insert(int elem)
{
  if( Count == Max )
  {
    Resize();
  }
  Vector[Count++] = elem;
}

int main() 
{
  for (int i=0;i<20;i++)
    {
      Insert(i);
    }
  return 0;
}