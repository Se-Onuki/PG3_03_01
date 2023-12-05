#include "InputHandler.h"
#include "Header/InputManager.h"
#include "Header/ICommand.h"

std::list<ICommand *> InputHandler::HandleInput() const {
	static const auto *const input = InputManager::GetInstance();
	std::list<ICommand *>result;

	if (input->IsPress(DIK_A)) {
		result.push_back(pressKeyA_.get());
	}

	if (input->IsPress(DIK_D)) {
		result.push_back(pressKeyD_.get());
	}

	return result;
}

void InputHandler::AssiginMoveLeftCommandPressKeyA() {
	if (not pressKeyA_) {
		pressKeyA_ = std::make_unique<MoveLeftCommand>();
	}
}

void InputHandler::AssiginMoveRightCommandPressKeyD() {
	if (not pressKeyD_) {
		pressKeyD_ = std::make_unique<MoveRightCommand>();
	}
}
