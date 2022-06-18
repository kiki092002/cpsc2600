//NAME: Nga Hoang
//FILE: digraph.h
//DESCRIPTION: contains Digraph's data member and functions.

#ifndef DIGRAPH_H
#define DIGRAPH_H
#include <iostream>
using namespace std;

class Digraph{
 private:
  int** matrix;
  int   size;
  bool* visited;
  void helperDFS(int startIndex);

 public:
  Digraph(const Digraph& G);
  Digraph(int n);
  Digraph(string filename);
  ~Digraph();
  void addEdge(int a, int b );
  void display() const;
  void displayDFS(int vertex);
  Digraph& createBFS(int vertex);
  int inDegree(int i) const;

};
#endif
