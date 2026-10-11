#include "Serializer.hpp"

int main(void)
{
	Data data;
	Data *ptr = &data;
	uintptr_t raw;
	Data *restored;
	data.value = 42;
	data.test = "test";
	raw = Serializer::serialize(ptr);
	restored = Serializer::deserialize(raw);

	std::cout << "original: " << ptr << std::endl;
	std::cout << "raw:      " << raw << std::endl;
	std::cout << "restored: " << restored << std::endl;
	std::cout << "value:    " << restored->value << std::endl;
	std::cout << "label:    " << restored->test << std::endl;
	return 0;
}
