#include <iostream>

//const int MAX_NUM = 100;
const int MAX_NUM = 1000000;

int sum_of_divisor(int num);
void solve(int max);

using namespace std;

int main()
{
  cout << "上限値 " << MAX_NUM << endl;
  cout << "上限値までの友愛数を表示します" << endl;
  solve(MAX_NUM);
  return 0;
}

int sum_of_divisor(int num)
{
  long sum = 0;
  if (num == 0 || num == 1) return 0;
  for( int i = 1; i < num; i++){
    if(num % i == 0) sum += i;
  }
  return sum;
}

void solve(int max)
{
  int div_sum;
  for( int i = 1; i <= max; i++){
    div_sum = sum_of_divisor(i);
    if(sum_of_divisor(div_sum) == i && i < div_sum && div_sum < MAX_NUM){
      cout << i << " " << div_sum << endl;
    }
  }
}
