#include <iostream>
#include <array>

class ipv4
{
  std::array<unsigned char, 4> data;
public:
  constexpr ipv4() : ipv4(0,0,0,0) {}
  constexpr ipv4(unsigned char const a, unsigned char const b,
                 unsigned char const c, unsigned char const d) :
                 data{(a,b,c,d)} {}
  explicit constexpr ipv4(unsigned long a) : ipv4
