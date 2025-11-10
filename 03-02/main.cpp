#include <iostream>

template<typename T>
T Min(T a, T b) {
	return (a < b) ? a : b;
}

int main() {
	int intA = 10;
	int intB = 20;
	std::cout << "Min(" << intA << ", " << intB << ") = " << Min(intA, intB) << std::endl;

	float floatA = 4.5f;
	float floatB = 2.3f;

	std::cout << "Min(" << floatA << "f, " << floatB << "f) = " << Min(floatA, floatB) << std::endl;

	double doubleA = 5.5;
	double doubleB = 3.3;
	std::cout << "Min(" << doubleA << ", " << doubleB << ") = " << Min(doubleA, doubleB) << std::endl;

	return 0;
}
