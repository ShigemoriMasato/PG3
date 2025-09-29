#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

std::vector<std::string> ReadCsv(const std::string& fileName) {
	std::vector<std::string> result;
	std::fstream file(fileName);
	if (!file.is_open()) {
		printf("Failed to open file: %s\n", fileName.c_str());
		return result;
	}

	std::string line;
	while (std::getline(file, line, ',')) {
		result.push_back(line);
	}

	return result;
}

void PrintVector(const std::vector<std::string>& vec) {
	for (const auto& str : vec) {
		printf("%s\n", str.c_str());
	}
	printf("\n");
}

int main() {

	std::vector<std::string> data = ReadCsv("PG3_2025_01_02.txt");

	printf("Before");
	PrintVector(data);

	std::sort(data.begin(), data.end());

	printf("Sorted");
	PrintVector(data);

	return 0;
}
