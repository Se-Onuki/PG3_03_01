#pragma once
#include <array>
#include <Novice.h>

class InputManager {
	InputManager() = default;
	InputManager(const InputManager &) = delete;
	InputManager &operator=(const InputManager &) = delete;
	~InputManager() = default;
public:

	static auto *const GetInstance() {
		static InputManager instance{};
		return &instance;
	}

	bool IsPress(const uint8_t key) const {
		return key_[key];
	}
	bool IsTrigger(const uint8_t key) const {
		return key_[key] && not preKey_[key];
	}
	bool IsRelease(const uint8_t key) const {
		return not key_[key] && preKey_[key];
	}

	void Update() {
		std::memcpy(preKey_.data(), key_.data(), 256u);
		Novice::GetHitKeyStateAll(key_.data());
	}

private:
	std::array<char, 256u> key_;
	std::array<char, 256u> preKey_;

};