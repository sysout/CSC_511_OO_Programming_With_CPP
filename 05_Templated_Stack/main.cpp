#include "stack.hpp"

int main(int argc, char const *argv[]) {
  /* code */
  Stack<int> a,b;
  cout<<a.top();
  a.push (1);
  a.push (2);
  b.push (3);
  b.push (4);
  Stack<int> c = a + b;
  cout<<c;
  c.pop();
  cout<<c;
  c.pop();
  cout<<c;
  c.pop();
  cout<<c;
  // c.pop();
  // cout<<c;
  // c.pop();
  // cout<<c;
  return 0;
}
