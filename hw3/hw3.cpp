// NAME: 
// FILE: hw3.cpp
// DESCRIPTION: Tests IntSet class

#include <iostream>
using namespace std;
#include "intSet.h"

int main()
{
  IntSet A;
  IntSet B;
  IntSet C;
  //Tests written here
  for(int i=1;i<=10;i++)
    {
      if(i% 2 == 0){
        A.addElement(i);
      }
      if(i%3 ==0){
        B.addElement(i);
      }
      if( i == 2 || i == 4 || i == 6 || i == 9  ) {
        C.addElement(i);
      }
    }
    // "-------------Problem 2-------------"
        IntSet D = A.complement();
        IntSet E = A.unions(B);
        IntSet F = B.intersect(C);
        IntSet G = A.difference(B);
        IntSet H = B.unions(A.intersect(C));
        IntSet I = E.difference(C);

    // "-------------Problem 3-------------"
    cout<<"A: ";A.printBit();
    cout<<"Number of elements in the set : "<<A.size()<<"\n\n";
 
    cout<<"B: ";B.printBit();
    cout<<"Number of elements in the set : "<<B.size()<<"\n\n";

    cout<<"C: ";C.printBit();
    cout<<"Number of elements in the set : "<<C.size()<<"\n\n";

    // "-------------Problem 4-------------"
    cout<<"D: ";D.printSet();
    cout<<"Number of elements in the set : "<<D.size()<<"\n\n";

    cout<<"E: ";E.printSet();
    cout<<"Number of elements in the set : "<<E.size()<<"\n\n";

    cout<<"F: ";F.printSet();
    cout<<"Number of elements in the set : "<<F.size()<<"\n\n";

    cout<<"G: ";G.printSet();
    cout<<"Number of elements in the set : "<<G.size()<<"\n\n";

    cout<<"H: ";H.printSet();
    cout<<"Number of elements in the set : "<<H.size()<<"\n\n";

    cout<<"I: ";I.printSet();
    cout<<"Number of elements in the set : "<<I.size()<<"\n\n";

    // "-------------Problem 5-------------"
    if(H.contains(6)){
        cout << "The set H contains 6" << endl << endl;
    }
    else {
        cout << "The set H doesn't contains 6"<< endl << endl;
    }

    if(D.contains(2)){
        cout << "The set D contains 2" << endl << endl;
    }
    else {
        cout << "The set D doesn't contain 2" << endl << endl;
    }
  return 0;
}
