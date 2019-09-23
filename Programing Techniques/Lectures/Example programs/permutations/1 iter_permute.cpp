#include <iostream>

using namespace std;


void iter_permute3();
void iter_permute4();
void iter_permute10();


int main()
{
   char ch;   

   cout << "Solve iteratively for n = 3" << endl;
   iter_permute3();
   cout << "Waiting: -- enter a character";
   cin >> ch;

   cout << "Solve iteratively for n = 4" << endl;
   iter_permute4();
   cout << "Waiting: -- enter a character";
   cin >> ch;

   cout << "Solve iteratively for n = 10" << endl;
   iter_permute10();

}


void iter_permute3()
{
   int i,j,k;

   for(i=0; i<3; i++)
      for(j=0; j<3; j++)
         for(k=0; k<3; k++)
            if(i!=j && i!=k && j!=k)
               cout << i << " " << j << " " << k << endl;
}
void iter_permute4()
{
   int i,j,k,l;

   for(i=0; i<4; i++)
      for(j=0; j<4; j++)
         for(k=0; k<4; k++)
            for(l=0; l<4; l++)
               if( i!=j && i!=k && i!=l && j!=k && j!=l && k!=l )
                  cout << i << " " << j << " " << k << " " << l << endl;

}






void iter_permute10()
{
   int i,j,k,l,m,n,o,p,q,r;
   for(i=0; i<10; i++)
      for(j=0; j<10; j++)
         for(k=0; k<10; k++)
            for(l=0; l<10; l++)
               for(m=0; m<10; m++)
                  for(n=0; n<10; n++)
                     for(o=0; o<10; o++)
                        for(p=0; p<10; p++)
                           for(q=0; q<10; q++)
                              for(r=0; r<10; r++)
                                 if( i!=j && i!=k && i!=l && i!=m && i!=n && 
                                             i!=o && i!=p && i!=q && i!=r &&
                                     j!=k && j!=l && j!=m && j!=n && j!=o && 
                                             j!=p && j!=q && j!=r &&
                                     k!=l && k!=m && k!=n && k!=o && k!=p && 
                                             k!=q && k!=r &&
                                     l!=m && l!=n && l!=o && l!=p && l!=q && 
                                             l!=r &&
                                     m!=n && m!=o && m!=p && m!=q && m!=r &&
                                     n!=o && n!=p && n!=q && n!=r &&
                                     o!=p && o!=q && o!=r &&
                                     p!=q && p!=r &&
                                     q!=r )
                                     cout << i << " " << j << " " << k << " " 
                                          << l << " " << m << " " << n << " " 
                                          << o << " " << p << " " << q << " " 
                                          << r << endl;

}