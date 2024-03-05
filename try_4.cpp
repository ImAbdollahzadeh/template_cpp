/* It can be quite useful. For example, i used it to check whether
   an initializer list collected using operator comma is no longer
   than a fixed size.
*/

#include <iostream>

static constexpr int vector_bound = 5;

template<int _Size> struct List {};

template<int _Size> struct Vector {
    template<int _ListSize>
    Vector(const List<_ListSize>& l, char(*)[_ListSize <= _Size] = nullptr) { std::cout << "Accepted list with size " << _ListSize << std::endl; }

    Vector(...)                                                             { std::cout << "Rejected list " << std::endl; }
};

int main()
{
	List<3>  short_list;
	List<12> long_list;

	Vector<vector_bound> v1 { short_list };
	Vector<vector_bound> v2 { long_list  };
}
