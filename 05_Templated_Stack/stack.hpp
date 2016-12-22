#ifndef MY_STACK_HPP
#define MY_STACK_HPP

#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

template <typename T>
class Stack{
  vector<T> v;
public:
  bool empty(){
    // – returns whether the stack is empty
    return v.empty();
  };
  void push(const T &item){
    // – adds item to the stack
    v.push_back(item);
  };
  T & top(){ // – returns a reference to the most-recently-added item
    if(v.empty())
      throw std::out_of_range("Top stack when empty");
    return v.back();
  };
  void pop(){
    // – removes the most-recently-added item from the stack
    // Stack∷pop() should include exception handling to handle the exception
    // when a pop operation is requested when the stack is empty
    if(v.empty())
      throw std::out_of_range("Pop stack when empty");
    v.pop_back();
  };
  friend Stack operator+(const Stack &a, const Stack &b){
    Stack<T> c(a);
    c.v.insert(c.v.end(),b.v.begin(),b.v.end());
    return c;
  }

  friend ostream & operator<<(ostream &o, const Stack &a){
    for (auto it = a.v.begin(); it!=a.v.end(); it++) {
     o<<*it<<" ";
    }
    o<<endl;
    return o;
  }
};
#endif
