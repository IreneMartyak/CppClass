#include <iostream>
#include <string_view>
#include <array>

void print(std::string_view str = "") { std::cout << str << '\n'; }

int main()
{
    print("\n" "UTF-8 character literals:");
    auto C1 = u8'a';
    std::cout << C1 << std::endl;
//  char8_t C2 = u8'¢';  // error: ¢ maps to two UTF-8 code units
//  char8_t C3 = u8'猫';  // error: 猫 maps to three UTF-8 code units
//  char8_t C4 = u8'🍌'; // error: 🍌 maps to four UTF-8 code units

    print("\n" "Floating-point literal:");
    std::cout << 0x1ffp10 << std::endl; // 0X hex-digit-sequence hex-exponent suffix (optional)
    std::cout << 0x1.p0 << std::endl;   // 0X hex-digit-sequence . hex-exponent suffix (optional)
    std::cout << 0x0.123p-1 << std::endl; // 0X hex-digit-sequence (optional) . hex-digit-sequence hex-exponent suffix (optional)	

    std::array<int,4> arr = {1,2,3,4};
    const int n = 10;
    static_assert(n < 4);
    int value = arr.at(n);

    return 0;
}