#pragma once
#include <list>
#include <memory>
class ICommand;

class InputHandler {
	InputHandler() = default;
	InputHandler(const InputHandler &) = delete;
	InputHandler &operator=(const InputHandler &) = delete;
	~InputHandler() = default;
public:

	static InputHandler *const GetInstance() {
		static InputHandler instance{};
		return &instance;
	}

	std::list<ICommand *> HandleInput()const;

	void AssiginMoveLeftCommandPressKeyA();
	void AssiginMoveRightCommandPressKeyD();

private:

	std::unique_ptr<ICommand> pressKeyA_;
	std::unique_ptr<ICommand> pressKeyD_;

};