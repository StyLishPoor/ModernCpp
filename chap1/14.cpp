#include <iostream>
#include <string>
#include <functional>
#include <numeric>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

bool validate_isbn_10(string_view isbn)
{
  auto valid = false;
  if(isbn.size() == 10 && std::all_of(cbegin(isbn), cend(isbn), std::isdigit)){
    auto w = 10;
    auto sum = accumulate(cbegin(isbn), cend(isbn), 0,
      [&w](int const total, char const c){
        return total + w-- * (c - '0');});

    valid = !(sum % 11);
  }
  return valid;
}

int main()
{
  string_view isbn;
  cout << "isbn :";
  cin >> isbn;
  if(validate_isbn_10(isbn)) cout << "ISBNとして有効です" << endl;
  else cout << "ISBNとして無効です" << endl;
}
