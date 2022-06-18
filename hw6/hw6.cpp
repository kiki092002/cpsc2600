// NAME: Nga Hoang                                                                                            
// FILE: hw6.cpp                                                                                  
// DESCRIPTION: Tests Digraph class

#include <iostream>
#include "digraph.h"

using namespace std;

int main(){
  
  cout << " Original graph from test.csv file: " <<endl;
  Digraph g1("test.csv");
  g1.display();
  cout << g1.inDegree(0) << endl;
  cout << g1.inDegree(1) << endl;
  cout << g1.inDegree(2) << endl;
  cout << g1.inDegree(3) << endl;
  cout << g1.inDegree(4) << endl;
  cout << g1.inDegree(5) << endl;
  cout << g1.inDegree(6) << endl;
  cout << g1.inDegree(7) << endl;

  g1.displayDFS(0);
  g1.createBFS(0);

  cout << " Original graph from test2.csv file: " <<endl;

  Digraph g2("test2.csv");
  
  return 0;
}
