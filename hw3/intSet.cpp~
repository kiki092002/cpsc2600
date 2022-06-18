// NAME:Nga Hoang 
// FILE: intSet.cpp
// DESCRIPTION: Implementation of the IntSet class.

#include <iostream>
using namespace std;
#include "intSet.h"


IntSet::IntSet():subset(0){}


void IntSet::addElement(int val)
{
  if(!contains(val)){
    subset |= 1 << (val - 1 );
  }
}


void IntSet::removeElement(int val)
{
  if(contains(val)){
    subset ^= 1 << (val - 1 );
  }
}


bool IntSet::contains(int val) const
{
  return (subset >> (val - 1) & 1);
}


void IntSet::printSet() const
{
  if(!size()){
    cout << "{}";
  }
  cout << "{";
  for ( int i = 0,j = 0; i < CARDINALITY; i++){
    if((subset >> i) & 1){
      if(j!=0){
        cout << ", ";
      }
      cout << (i+1);
      j = 1;
    }
  }
  cout << "}" << endl;
}


void IntSet::printBit() const
{
  if(subset == 0){
    cout <<"0000000000" << endl;
  }
  for(int i = 1; i<= CARDINALITY; i++){
    cout << ((subset >> (i -1)) & 1 );
  }
  cout << endl;
}


int IntSet::size() const
{
  if(subset == 0){
    return 0;
  }
  int count = 0 ;
  for ( int i = 0 ; i <= CARDINALITY;i++){
    count += ((subset >> (i - 1)) & 1);
  }
  return count;
}


IntSet IntSet::unions(const IntSet& operand) const
{
  IntSet unionS;
  unionS.subset = subset | operand.subset;
  return unionS;
}


IntSet IntSet::intersect(const IntSet& operand) const
{
  IntSet interS;
  interS.subset = subset & operand.subset;
  return interS;
}


IntSet IntSet::difference(const IntSet& operand) const
{
  return intersect(operand.complement());
}


IntSet IntSet::complement() const
{
  IntSet complementS;
  for(int i = 0 ; i<= CARDINALITY; i++){
    if(!((subset >> i ) & 1)){
      complementS.subset |= 1 << i;
    }
  }
  return complementS;
}


bool IntSet::isEqual(const IntSet& operand) const
{
  return !(subset ^ operand.subset);
}
