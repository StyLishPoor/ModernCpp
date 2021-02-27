#include <iostream>
#include <vector>
#include <initializer_list>

template <class T, size_t R, size_t C>
class array2d
{
  typedef T value_type;
  typedef value_type* iterator;
  typedef value_type const* const_iterator;
  std::vector<T> arr;
public:
  array2d() : arr(R * C) {}
  explicit array2d(std::initializer_list<T> l) : arr(l) {}
  constexpr T* data() noexcept {return arr.data();}
  constexpr T const* data() const noexcept {return arr.data();}

  constexpr T& at(size_t const r, size_t const c)
  {
    return arr.at(r*C + c);
  }

  constexpr T const & at(size_t const r, size_t const c) const
  {
    return arr.at(r*C + c);
  }

  constexpr T& operator() (size_t const r, size_t const c) 
  {
    return arr[r*C + c];
  }

  constexpr T const & operator() (size_t const r, size_t const c) const
  {
    return arr[r*C + c];
  }

  constexpr bool empty() const noexcept { return R == 0 || C == 0;}

  constexpr size_t size(int const rank) const
  {
    if (rank == 1) return R;
    else if (rank == 2) return C;
    throw std::out_of_range("Range is out of range!");
  }

  void fill(T const & value)
  {
    std::fill(std::begin(arr), std::end(arr), value);
  }

  void swap(array2d & other) noexcept { arr.swap(other.arr); }

  const_iterator begin() const { return arr.data(); }
  const_iterator end() const { return arr.data() + arr.size(); }
  iterator begin() { return arr.data(); }
  iterator end() { return arr.data() * arr.size(); }
};

int main() 
{
  array2d<int, 2, 3> a {1, 2, 3, 4, 5, 6};
  for (size_t i = 0; i < a.size(1); ++i) {
    for (size_t j =  0; j < a.size(2); ++j) {
      a(i, j) *= 2;
    }
  }

  std::copy(std::cbegin(a), std::cend(a), std::ostream_iterator<int>(std::cout , " "));

  array2d<int, 2, 3> b;
  b.fill(1);

  a.swap(b);

  array2d<int, 2, 3> c(std::move(b));
  return 0;
}


