#include <iostream>

int gcd(int big, int small);

using namespace std;

int main()
{
  int num1, num2;
  cout << "自然数を2つ入力してください :";
  cin >> num1 >> num2 ;
  cout << "最小公倍数  " << num1 * (num2 / gcd(num1, num2)) << endl;
  return 0;
}

int gcd(int big, int small)
{
  if (big % small == 0) return small;
  return gcd(small, big % small);
}
