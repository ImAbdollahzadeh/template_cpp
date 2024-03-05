// Run with:
// g++ try_6.cpp -std=c++20

// #include <iostream>
//
// template <typename T> concept Integral         = std::is_integral<T>::value;
// template <typename T> concept SignedIntegral   = Integral<T> && std::is_signed<T>::value;
// template <typename T> concept UnsignedIntegral = Integral<T> && !SignedIntegral<T>;
//
// void func(SignedIntegral   auto integ) { std::cout << "SignedIntegral: "   << integ << '\n'; }
// void func(UnsignedIntegral auto integ) { std::cout << "UnsignedIntegral: " << integ << '\n'; }
//
// int main()
// {
//     func(-5);
//     func(5u);
// }


// // Run with:
// // g++ try_6.cpp -std=c++20
// #include <iostream>
//
// template <typename T> requires std::is_integral<T>::value && std::is_signed<T>::value
// void func(const T& integ) { std::cout << "SignedIntegral: "   << integ << '\n'; }
//
// template <typename T> requires std::is_integral<T>::value && (!std::is_signed<T>::value)
// void func(const T& integ) { std::cout << "UnsignedIntegral: " << integ << '\n'; }
//
// int main()
// {
//     func(-10);
//     func(1563u);
// }


// Run with:
// g++ try_6.cpp
#include <iostream>

template <typename T>
typename std::enable_if<std::is_integral<T>::value && std::is_signed<T>::value, void>::type
func(const T& integ) { std::cout << "SignedIntegral: "   << integ << '\n'; }

template <typename T>
typename std::enable_if<!(std::is_integral<T>::value && std::is_signed<T>::value), void>::type
func(const T& integ) { std::cout << "UnsignedIntegral: " << integ << '\n'; }

int main()
{
    func(56u);
    func(-2);
}
