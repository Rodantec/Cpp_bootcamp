#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(void)
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	Base *p = generate();
	std::cout << "Pointer identification: ";
	identify(p);
	std::cout << "Reference identification: ";
	identify(*p);
	delete p;
	return 0;
}
