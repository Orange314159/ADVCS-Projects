#include <iostream>
using namespace std;
int main()
{
   int i1 = 7, i2 = -3;
   int arr[5] = {1,2,3,4,5};
   int* aqq[5];
   int* akk[5];
   int * m;
   int * n;
   int * o;
   int * p, q;
   int r;
   int &s = r;
   
   m = arr;
   n = arr+1;
   o = m+*n;
   p = o;
   q = 1+*n;
   
   
   void Swap0(int , int);
   void Swap1 (int &, int &);
   void Swap2 (int *, int *);

    cout << i1 << " " << i2 << endl;
    Swap2(&i1,&i2);
    cout << i1 << " " << i2;

}

void Swap0 (int i1, int i2)
{
   int i;
   i = i1;
   i1 = i2;
   i2 = i;
}

void Swap1 (int &ri1, int &ri2)
{
   int i;
   i = ri1;
   ri1 = ri2;
   ri2 = i;
}

void Swap2 (int *pi1, int *pi2)
{
    int i;
    i = *pi1;
    *pi1 = *pi2;
    *pi2 = i;
}