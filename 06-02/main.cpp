#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <istream>
#include <fstream>
#include <sstream>
#include <Windows.h>

void ClearScreen() {
	system("cls");
}

void DrawCSV(const std::vector<std::vector<int>> data) {
	std::vector<char> displayChars = { '.', '#', 'O', 'X' };
	
	for(const auto& row : data) {
		for(const auto& cell : row) {
			if(cell >= 0 && cell < displayChars.size()) {
				std::cout << displayChars[cell];
			} else {
				std::cout << '?';
			}
		}
		std::cout << std::endl;
	}
}

int main() {
	std::vector<std::vector<int>> rawData;
	std::vector<std::vector<int>> mapData;
	bool dataLoaded = false;
	bool drawingSuccess = false;

	auto loader = [&](std::string filePath) {
		dataLoaded = false;

		std::ifstream file(filePath);
		if (!file.is_open()) {
			std::cerr << "Failed to open file: " << filePath << std::endl;
			dataLoaded = true;
			return;
		}

		std::string line;
		while (std::getline(file, line)) {
			std::vector<int> row;
			std::istringstream iss(line);
			std::string cell;

			while(std::getline(iss, cell, ',')) {
				row.push_back(std::stoi(cell));
			}

			Sleep(100);

			rawData.push_back(row);
		}

		dataLoaded = true;
		};

	auto process = [&]() {

		bool dataCopied = false;

		while (true) {

			if (dataLoaded) {
				mapData = rawData;
				dataCopied = true;
			}

			ClearScreen();
			DrawCSV(mapData);

			if (dataCopied) {
				return;
			}
		}

		};

	std::thread loaderThread(loader, "data.csv");
	std::thread processorThread(process);
	loaderThread.join();
	processorThread.join();

	return 0;
}
