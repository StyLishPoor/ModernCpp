#include <iostream>
#include <string>

using namespace std;

// テンプレート関数
template <typename T>
T add(T x, T y)
{
  return x+y;
}

int main() 
{
  cout << add<int>(4,3) << endl;
  cout << add<string>("ABC", "DEF") << endl;
  cout << add(1,2) << endl;
  return 0;
}
