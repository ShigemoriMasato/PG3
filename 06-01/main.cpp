#include <iostream>
#include <thread>
#include <string>

void Print(int num) {
	std::string output = "thread " + std::to_string(num) + '\n';
	std::cout << output;
}

int main() {
	std::thread t1(Print, 1);
	t1.join();
	std::thread t2(Print, 2);
	t2.join();
	std::thread t3(Print, 3);
	t3.join();

	std::cout << std::flush;

	return 0;
}
