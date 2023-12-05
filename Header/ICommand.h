#pragma once

struct Player;

class ICommand {
public:
	virtual ~ICommand() = default;
	virtual void Exec(Player &player) = 0;
};

class MoveRightCommand : public ICommand {
public:

	void Exec(Player &player) override;

private:

};

class MoveLeftCommand : public ICommand {
public:

	void Exec(Player &player) override;

private:

};