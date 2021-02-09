#include <iostream>
#include "sample.h"

using namespace std;

int main() 
{
  Graph graph;
  int num;

  cout << "input integet : " << endl;
  cin >> num;

  graph.set(num);
  cout << graph.get() << endl;

  return 0;
}
