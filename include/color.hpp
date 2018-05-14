#pragma once
#include <cstdint>

namespace pl
{
struct Color
{
  std::uint32_t r;
  std::uint32_t g;
  std::uint32_t b;
  std::uint32_t a;
  Color(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a = 255) : r(r), g(g), b(b), a(a) {}
  static Color TransparentBlack, Black, Red;
};
} // namespace pl