#include <iostream>

bool isPrime(int num);
int solve(int max);

using namespace std;

int main()
{
  int max;
  cout << "上限値を設定してください " ;
  cin >> max;
  cout << "上限値以下で最大の素数は " << solve(max) <<endl;
  return 0;
}

bool isPrime(int num)
{
  if(num == 2) return true;
  for(int i = 2; i < num / 2 ; i++){
    if(num % i == 0) return false;
  }
  return true;
}
int solve(int max)
{
  for(int i = max ; i > 1; i--){
    if (isPrime(i)) return i;
  }
  return -1; // エラー値;
}

