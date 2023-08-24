#include <iostream>
using namespace std;

int Vector[100];
int Count;  

void Insert(int elem)
{
  if( Count < 100 )
    {
      Vector[Count++] = elem;
    }
}
int main() 
{
  for (int i=0;i<20;i++)
    {
      Insert(i);
    }

  return 0;
}