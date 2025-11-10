#include <stdio.h>
#include <vector>
#include <string>

struct Vector2 {
	float x, y;
};

class Enemy {
public:
	Enemy() = default;
	~Enemy() = default;

	void Update(int frame);

private:

	static void (Enemy::*pFunc[])();

	void BehApproach();
	void BehShot();
	void BehGoAway();

private:

	enum Behavior {
		Approach,
		Shot,
		GoAway
	};

private:

	Behavior currentBehavior;

	std::vector<Behavior> actionTable_;
	int actionIndex;

	Vector2 position = { -30.0f, 0.0f };
	const float speed = 1.0f;

private:

	void Log(int frame);

	const std::string behaviorNames[3] = {
		"Approach",
		"Shot    ",
		"GoAway  "
	};
	const std::string format = "[Frame: %03d]\t[Behavior: %s]\tPosition: (%.2f, %.2f)\n";
};

void(Enemy::*Enemy::pFunc[])() = {
	&Enemy::BehApproach,
	&Enemy::BehShot,
	&Enemy::BehGoAway
};

void Enemy::Update(int frame) {
	(this->*pFunc[static_cast<int>(currentBehavior)])();
	Log(frame);
}

void Enemy::BehApproach() {
	position.x += speed;
	if (position.x >= 0.0f) {
		position.x = 0.0f;
		currentBehavior = Shot;
	}
}

void Enemy::BehShot() {
	currentBehavior = GoAway;
}

void Enemy::BehGoAway() {
	position.x -= speed;
	if (position.x <= -30.0f) {
		position.x = -30.0f;
		currentBehavior = Approach;
	}
}

void Enemy::Log(int frame) {
	printf(format.c_str(), frame, behaviorNames[static_cast<int>(currentBehavior)].c_str(), position.x, position.y);
}

int main() {
	Enemy enemy;
	for (int frame = 0; frame < 100; ++frame) {
		enemy.Update(frame);
	}
	return 0;
}
