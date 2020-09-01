#include <iostream>

bool isPrime(int num);
void solve(int max);

using namespace std;

int main()
{
  int max;
  cout << "上限値を設定してください " ;
  cin >> max;
  cout << "上限値以下までのセクシー素数 " << endl;
  solve(max);
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
void solve(int max)
{
  for(int i = 2; i <= max; i++){
    if(isPrime(i)){
      if(isPrime(i+6) && i+6 <= max){
        cout << i << " " << i+6 << endl;
      }
    }
  }
}

