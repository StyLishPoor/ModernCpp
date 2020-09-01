#include <iostream>

int solve(int input);
using namespace std;

int main()
{
  int max_num;
  cout << "input max num: ";
  cin >> max_num;
  cout << "3または5で割り切れる性の整数の総和: " << solve(max_num) << endl;
  return 0;
}

int solve(int input)
{
  int ans = 0;
  for(int i = 1; i <= input; i++){
    if (i % 3 == 0 || i % 5 == 0){
      ans += i;
    }
  }
  return ans;
}
