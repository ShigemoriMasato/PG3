#pragma once
#include <memory>

class IScene {
public:

	virtual ~IScene() = default;
	virtual std::unique_ptr<IScene> Update(bool trigger) = 0;
	virtual void Draw() = 0;

private:


}