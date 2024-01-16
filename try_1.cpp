#include <iostream>
#include <vector>

struct vector_class {std::vector<int> data;};
struct integer_class{int              data;};

struct Base {
    auto get() {
        struct Result {
            operator vector_class () { return base_obj->get_vector (); }
            operator integer_class() { return base_obj->get_integer(); }
            Base*    base_obj;
        };
        return Result{ this };
    }
    vector_class  get_vector () {std::cout << "in vector_class \n"; return vector_class {};}
    integer_class get_integer() {std::cout << "in integer_class\n"; return integer_class{};}
};

int main()
{
	Base base;
	vector_class  obj1 = base.get();
	integer_class obj2 = base.get();
}
