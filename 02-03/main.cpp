#include <iostream>
#include <stdlib.h>
#define NOMINMAX
#include <windows.h>

void DelayReveal(void(*fn)(int, int), unsigned int delayMs, int roll, int userGuess) {
	std::cout << "サイコロを振っています";
	for (int time = (int)delayMs; time > 0; time -= 1000) {
		if (time >= 1000) {
			std::cout << ".";
			Sleep(1000);
		}
		else {
			Sleep(time);
		}
	}
	std::cout << std::endl;
	fn(roll, userGuess);
}

void RevealResult(int roll, int userGuess) {
	std::cout << "出た目は" << roll << " です。" << std::endl;
	char result = roll % 2;
	if (userGuess == result) {
		std::cout << "あたり！" << std::endl;
	} else {
		std::cout << "はずれ！" << std::endl;
	}
}


int main() {
	srand(unsigned(time(nullptr)));
	int input = -1;

	std::cout << "奇数ですか？偶数ですか?" << std::endl;
	while (input != 1 && input != 0) {
		input = -1;
		std::cout << "(1/0) :" << std::endl;
		std::cin >> input;
	}

	std::cout << "あなたは" << (input == 1 ? "奇数" : "偶数") << "を選びました。" << std::endl;

	DelayReveal(RevealResult, 3000, (rand() % 6) + 1, input);

	return 0;
}