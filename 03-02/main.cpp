#include <iostream>

template<typename T>
class Checker {
public:
	T a;
	T b;
	T Min() {
		return (a < b) ? a : b;
	}
};

int main() {

	int intA = 10;
	int intB = 20;
	Checker<int> intChecker{ intA, intB };
	std::cout << "Min(" << intA << ", " << intB << ") = " << intChecker.Min() << std::endl;

	float floatA = 4.5f;
	float floatB = 2.3f;
	Checker<float> floatChecker{ floatA, floatB };
	std::cout << "Min(" << floatA << "f, " << floatB << "f) = " << floatChecker.Min() << std::endl;

	double doubleA = 5.5;
	double doubleB = 3.3;
	Checker<double> doubleChecker{ doubleA, doubleB };
	std::cout << "Min(" << doubleA << ", " << doubleB << ") = " << doubleChecker.Min() << std::endl;

	return 0;
}
