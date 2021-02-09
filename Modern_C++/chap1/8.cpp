#include <iostream>
using namespace std;

bool solve(int check)
{
  int num1,num2,num3;
  int tmp = check;
  num1 = check / 100;
  check -= num1 * 100;
  num2 = check / 10;
  check -= num2 * 10;
  num3 = check;
  
  if(num1*num1*num1 + num2*num2*num2 + num3*num3*num3 == tmp) return true;
  return false;
}

int main()
{
  for(int i = 100; i < 1000; i++){
    if(solve(i)){
      cout << i << endl;
    }
  }
  return 0;
}

