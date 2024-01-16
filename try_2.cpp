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

template<typename T> typename std::enable_if<IsContainer<T>::value, void>::type log(const T& t) {
	typedef typename T::const_iterator Iter;
	for(Iter it = t.begin(); it < t.end(); it++)
		std::cout << *it << std::endl;
}

void log(const int& t) {
	std::cout << t << std::endl;
}

std::vector<int> python_call()
{
	return std::vector<int>{1,2,3,4,5,6,7,8,9};
	//return 9845;
}

int main()
{
	auto obj = object_deduction(python_call());
	log(obj);
}
