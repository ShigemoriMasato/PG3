#include <iostream>

class Animal {
public:
	Animal() = default;
	~Animal() = default;

	virtual void Speak() = 0;
};

class Dog : public Animal {
public:
	void Speak() override {
		std::cout << "Dog << Woof!" << std::endl;
	}
};

class Cat : public Animal {
public:
	void Speak() override {
		std::cout << "Cat << Meow!" << std::endl;
	}
};

int main() {
	Animal* dog = new Dog();
	Animal* cat = new Cat();
	dog->Speak();
	cat->Speak();
	delete dog;
	delete cat;
	return 0;
}
