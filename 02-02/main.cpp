#include <stdio.h>

int TimeReward(int hour, int rewardPerHour) {
	return hour * rewardPerHour;
}

int RecursiveReward(int hour, int rewardPerHour) {
	if (hour == 1) {
		return rewardPerHour;
	}
	return RecursiveReward(hour - 1, rewardPerHour) * 2 - 50;
}

int main() {

	int timeReward = 0;
	int recursiveReward = 0;

	int hour = 0;

	do {
		hour++;

		timeReward = TimeReward(hour, 1226);
		recursiveReward += RecursiveReward(hour, 100);

		printf("Hour:	%3d, TimeReward:	%8d, RecursiveReward:	%8d\n", hour, timeReward, recursiveReward);

	} while (timeReward > recursiveReward);

	return 0;
}
