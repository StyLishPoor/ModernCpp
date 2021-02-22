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
  explicit constexpr ipv4(unsigned long a) : ipv4(static_cast<unsigned char>((a >> 24) & 0xFF),
                                                  static_cast<unsigned char>((a >> 16) & 0xFF),
                                                  static_cast<unsigned char>((a >> 8) & 0xFF),
                                                  static_cast<unsigned char>(a & 0xFF)){}
  ipv4(ipv4 const & other) noexcept : data(other.data){}
  ipv4& operator=(ipv4 const & other) noexcept
  {
    data = other.data;
    return *this;
  }

  std::string to_string() const
  {
    std::stringstream sstr;
    sstd << *this;
    return sstr.str();
  }

  constexpr unsigned long to_long() const noexcept
  {
    return (static_cast<uint8_t>(data[0] << 24) | 
            static_cast<uint8_t>(data[1] << 16) |
            static_cast<uint8_t>(data[2] <<  8) |
            static_cast<uint8_t>(data[3]);
  }

  friend std::ostream& operator<<(std::ostream& os, const ipv4& a)
  {
    os << static_cast<int>(a.data[0]) << '.'
       << static_cast<int>(a.data[1]) << '.'
       << static_cast<int>(a.data[2]) << '.'
       << static_cast<int>(a.data[3]);
       return os;
  }

  friend std::istream& operator>>(std::istream& is, ipv4& a)
  {
    char d1, d2, d3;
    int b1, b2, b3, b4;
    is >> b1 >> d1 >> b2 >> d2 >> b3 >> d3 >> b4;
    if (d1 == '.' && d2 == '.' && d3 == '.') {
      a = ipv4(b1, b2, b3, b4);
    } else {
      is.setstate(std::ios_base::failbit);
    }
    return is;
  }
};
