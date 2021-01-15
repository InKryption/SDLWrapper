#include "main.hpp"

typedef const bool* const TypeID;
template<typename> TypeID TypeIdOf() noexcept {
	static const bool idLoc(0);
	return &idLoc;
}

class Base {
	public:
	virtual TypeID Type() const noexcept = 0;
	template<typename T> const bool IsType() const { return Type() == TypeIdOf<T>(); }
};

class Derived1: public Base {
	public: TypeID Type() const noexcept override { return TypeIdOf<Derived1>(); }
};

class Derived2: public Base {
	public: TypeID Type() const noexcept override { return TypeIdOf<Derived2>(); }
};

int main(int argc, char* argv[])
{
	Base* b0 = new Base;
	Base* b1 = new Derived1;
	Base* b2 = new Derived2;
	printf("%i\n", b1->IsType<Derived2>());
	return 0;
}
