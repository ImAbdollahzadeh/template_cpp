#include <iostream>
#include <vector>

//#define type_deduction(T)  type_deduce<T, Base>(T())
#define object_deduction(t) type_deduce<decltype(t), Base>(t)

template<typename _Ty> struct Base {
	static _Ty type(const _Ty& __ty) {
		return _Ty(__ty);
	}
};

template<typename T, template<typename>typename BaseClass>
auto type_deduce(const T& b) -> decltype(BaseClass<T>::type(b)) {
	return BaseClass<T>::type(b);
}

template<typename T> struct IsContainer {
	typedef char Yes[1];
	typedef char No [2];
	template <typename Container> static Yes& test( decltype(&Container::size) );
	template <typename Container> static No & test(...);

	enum { value = sizeof(test<T>(0)) == sizeof(Yes) };
};

template<bool condition, typename T> struct EnableIF {
	typedef T type;
};

template<typename T> struct EnableIF<false, T> {
	typedef void type;
};

template<typename T>
typename EnableIF<IsContainer<T>::value, void>::type log(const T& t) {
	typedef typename T::const_iterator Iter;
	for(Iter it = t.begin(); it < t.end(); it++)
		std::cout << *it << std::endl;
}

void log(const int& t) {
	std::cout << t << std::endl;
}

std::vector<char> python_call()
{
	return std::vector<char>{'a','b','c','d'};
	//return 9845;
}

int main()
{
	auto obj = object_deduction(python_call());
	log(obj);
}
