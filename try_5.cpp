#include <iostream>

template<typename _Ty, unsigned int _Size>
static constexpr unsigned int sizeof_array(_Ty const(&given_array)[_Size] = nullptr)
{
	return _Size;
}

int main()
{
	int MyArray[] = {0,1,5,6,7,8};
	std::cout << sizeof_array(MyArray);
}
