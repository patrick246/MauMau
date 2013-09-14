#pragma once
#include <memory>
#include <string>
#include <map>
#include <deque>
#include <SFML/Graphics.hpp>

class State;

class StateManager
	: public sf::Drawable
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
	
	const std::string& getTopStateID() const;
	template<class T> T* getStatePtr(const std::string& id) const;
	bool isRunning();

	void update(float frametime);
	void draw(sf::RenderTarget &,sf::RenderStates) const;

private:
	std::map<std::string, stateptr> m_registered;
	std::deque<State*> m_stack;

	bool m_running;
	std::deque<std::string> m_activeState;
};

template<class T> 
T* StateManager::getStatePtr( const std::string& id ) const
{
	auto it = m_registered.find(id);
	if(it == m_registered.end())
		throw std::runtime_error("StateManager::getStatePtr: State not found");
	return dynamic_cast<T*>(it->second.get());
}

