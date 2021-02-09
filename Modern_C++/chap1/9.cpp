#include <iostream>

using namespace std;

void solve(long num)
{
  for(int i = 2; i <= num; i++){
    if(num == 1) break;
    int count = 0;
    while(num % i == 0){
      cout << i << " ";
      num /= i;
    }
  }
  cout << endl;
}

int main()
{
  long num;
  cin >> num;
  solve(num);
  return 0;
}
