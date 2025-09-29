#include <stdio.h>
#include <list>
#include <string>

/// <summary>
/// 駅を追加する
/// </summary>
/// <param name="lst">追加する対象</param>
/// <param name="str">追加する駅名</param>
/// <param name="next">どこの前に追加するか</param>
void AddString(std::list<const char*>& lst, const char* str, const char* next) {
	for (std::list<const char*>::iterator it = lst.begin(); it != lst.end(); ++it) {
		if (*it == next) {
			it = lst.insert(it, str);
			break;
		}
	}
}

/// <summary>
/// 山手線出力関数
/// </summary>
/// <param name="list">駅リスト</param>
/// <param name="year">年号</param>
void PrintYamanote(const std::list<const char*>& list, int year) {

	// std::stringにならないようにc_strをしてchar配列にする
	printf("Yamanote Line Stations(%s):\n", std::to_string(year).c_str());

	int number = 0;		// 駅番号
	for (std::list<const char*>::const_iterator it = list.begin(); it != list.end(); ++it) {
		printf("JY%d:	%s\n", ++number, *it);
	}
	printf("\n");
}

int main() {

	std::list<const char*> yamanote = {
		"Toukyou",
		"Kanda",
		"Akihabara",
		"Okachimachi",
		"Ueno",
		"Uguisudani",
		"Nippori",
		"Tabata",
		"Komagome",
		"Sugamo",
		"Otsuka",
		"Ikebukuro",
		"Mejiro",
		"Takadanobaba",
		"Shin-Okubo",
		"Shinjuku",
		"Yoyogi",
		"Harajuku",
		"Shibuya",
		"Ebisu",
		"Meguro",
		"Gotanda",
		"Osaki",
		"Shinagawa",
		"Tamachi",
		"Hamamatsucho",
		"Shinbashi",
		"Yurakucho"
	};

	PrintYamanote(yamanote, 1970);

	//========================================================
	AddString(yamanote, "Nishi-Nippori", "Tabata");
	PrintYamanote(yamanote, 2019);

	//========================================================
	AddString(yamanote, "Takanawa Gateway", "Tamachi");
	PrintYamanote(yamanote, 2022);

	return 0;
}
