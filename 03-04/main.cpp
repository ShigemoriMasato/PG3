#include <iostream>
#include <string>
#include <numbers>

namespace nums = std::numbers;

class IShape {
public:
	virtual void Size() = 0;
	virtual void Draw() = 0;

protected:

	float area_;

};

class Circle : public IShape {
public:

	Circle(float radius) : radius_(radius) {};

	void Size() override {
		area_ = nums::pi_v<float> * radius_ * radius_;
	}

	void Draw() override {
		std::cout << "CircleArea = " << area_ << std::endl;
	}

private:

	float radius_;

};

class RectAngle : public IShape {
public:

	RectAngle(float width, float height) : width_(width), height_(height) {};

	void Size() override {
		area_ = width_ * height_;
	}
	void Draw() override {
		std::cout << "RectAngleArea = " << area_ << std::endl;
	}

private:
	float width_;
	float height_;
};

int main() {
	Circle circle(5.0f);
	circle.Size();
	circle.Draw();

	RectAngle rectAngle(4.0f, 6.0f);
	rectAngle.Size();
	rectAngle.Draw();

	return 0;
}
