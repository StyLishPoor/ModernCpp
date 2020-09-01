#include <iostream>

void over_num(int num);
void solve(int max);
using namespace std;

int main()
{
  int max;
  cout << "上限値を設定してください ";
  cin >> max;
  cout << "上限値までの過剰数を表示します" << endl;
  solve(max);
  return 0;
}

void over_num(int num)
{
  long sum = 0;
  for( int i = 1; i <= num ; i++){
    if( num % i == 0) sum += i;
  }
  if( sum > 2 * num) {
    cout << num << " " << sum - 2 * num << endl;
  }
}

void solve(int max)
{
  for( int i = 0; i <= max; i++){
    over_num(i);
  }
}

