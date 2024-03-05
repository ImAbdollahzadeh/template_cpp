// // Run with:
// // g++ try_7.cpp -std=c++20
#include <iostream>

template<typename T> struct Addable      { static constexpr bool value = false; };
template<          > struct Addable<int> { static constexpr bool value = true;  };

template<typename T> concept addable     =  Addable<T>::value;
template<typename T> concept not_addable = !Addable<T>::value;

addable auto add(addable     auto a, addable     auto b) { return a + b;   }
void*        add(not_addable auto a, not_addable auto b) { return nullptr; }

int main()
{
	std::cout << add(9, 15)      << std::endl;
    std::cout << add(1.0f, 2.3f) << std::endl;
}
