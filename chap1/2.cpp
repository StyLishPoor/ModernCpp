#include <iostream>

int solve(int big, int small);

using namespace std;

int main()
{
  int num1, num2;
  cout << "自然数を2つ入力してください :";
  cin >> num1 >> num2 ;
  cout << "最大公約数 " << solve(num1, num2) << endl;
  return 0;
}

int solve(int big, int small)
{
  if (big % small == 0) return small;
  return solve(small, big % small);
}
