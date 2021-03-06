//NAME : Nga Hoang
//FILE : digraph.cpp
//DESCRIPTION: Implementation of the Digraph class.

#include "digraph.h"
#include <iostream>
using namespace std;
#include <deque>
#include <fstream>
#include <sstream>
Digraph::Digraph(const Digraph& G){
  size = G.size;
  matrix = new int*[size];
  for(int i = 0; i< size; i++){
    matrix[i] = new int[size];
    for( int j = 0 ; j < size; j++){
      matrix[i][j] = G.matrix[i][j];
    }
  }
}

Digraph::Digraph(int n){
  size   = n;
  matrix = new int*[n];
  for(int i = 0; i <n ; i++){
    matrix[i] = new int[n];
    for(int j = 0 ; j<n ;j++){
      matrix[i][j] = 0;
    }
  }
}

Digraph::Digraph(string filename){
  ifstream file;
  file.open(filename);
  if(!file){
    cout << "FILE NOT OPEN";
    return;
  }
  string  v1,v2;
  string line;
  getline(file,line);
  stringstream iss(line);
  iss >> size;
  
  matrix = new int*[size];
  for(int i = 0; i< size;i++){
    matrix[i] = new int[size];
    for(int j =0; j < size; j++){
      matrix[i][j] = 0;
    }
  }

  while(getline(file,line)){
    istringstream iss(line);
    getline(iss,v1,',');
    getline(iss,v2,',');
    // addEdge(stoi(v1),stoi(v2));
    if((stoi(v1) >0 && stoi(v1) <= size) || (stoi(v2) >0 && stoi(v2) <=size)){
      addEdge(stoi(v1)-1, stoi(v2)-1);
    }
    else {
      addEdge(stoi(v1), stoi(v2));
    }
    
      
  }
   file.close();
}

Digraph::~Digraph(){
  delete[] matrix;
  
}

void Digraph::addEdge(int a, int b){
  
  matrix[a][b] =1;  
}

void Digraph::display() const{
  for(int i = 0; i< size; i++){
    for(int j = 0; j< size; j++){
      cout << " " << matrix[i][j];
        
    }
    cout << endl;
  }
  cout << endl;
}

void Digraph::helperDFS(int startIndex){
  visited[startIndex] = true;
  cout << startIndex << " " ;
  for(int i = 0 ;i < size; i++){
    if(matrix[startIndex][i] && !visited[i]){
      helperDFS(i);
    }
  }
}

void Digraph::displayDFS(int vertex){
  visited = new bool[size];
  for(int i = 0; i < size; i++){
    visited[i] = false;
  }
  cout << "DFS visit order starting at 0: ";
  helperDFS(vertex);
  cout << endl;
}

Digraph& Digraph::createBFS(int vertex){
  Digraph*  G = new Digraph(size);
  deque<int> q;
  visited = new bool[size];
  for(int i = 0 ; i < size; i ++){
    visited[i] = false;
  }
  visited[vertex] = true;
  cout << "BFS visit order starting at 0: " ;
  q.push_back(vertex);
  while(!q.empty()){
    int v = q.front();
    q.pop_front();
    cout << v << " ";
    for(int i = 0 ; i < size; i++){
      if(!visited[i] && matrix[v][i] == 1){
        visited[i] = true;
        G->addEdge(v,i);
        q.push_back(i);
      }
    }
  }
  cout << endl << " BFS Spanning Tree: " << endl;
  G->display();
  return* G;
}

int Digraph::inDegree(int i) const{
  int count = 0;
  for(int j = 0 ; j < size; j++){
    if(matrix[j][i] == 1){
      count++;
    }
  }
  cout << " Deg-" << "(" << i << ")" << " = " ;
  return count;
}
