#pragma once
#include <memory>
#include <string>
#include <map>
#include <deque>

class State;

class StateManager
	: sf::Drawable
{
public:
	typedef std::unique_ptr<State> stateptr;

public:
	StateManager(void);
	~StateManager(void);

	void registerState(const std::string& id, stateptr state);
	void pushState(const std::string& id);
	void popState();
	void exchangeState(const std::string& id);
	
	const std::string& getTopState() const;
	bool isRunning();

private:
	std::map<std::string, stateptr> m_registered;
	std::deque<State*> m_stack;

	bool m_running;
	std::deque<std::string> m_activeState;
};

