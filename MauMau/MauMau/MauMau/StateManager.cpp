#include <exception>

#include "StateManager.h"
#include "State.h"

StateManager::StateManager(void)
	: m_running(true)
{
}


StateManager::~StateManager(void)
{
}

void StateManager::registerState( const std::string& id, stateptr state )
{
	if(m_registered.find(id) != m_registered.end())
		throw std::runtime_error("registerState: State already registered: " + id);

	if(state == nullptr)
		throw std::runtime_error("registerState: State is nullptr: " + id);

	m_registered[id] = std::move(state);
}

void StateManager::pushState( const std::string& id )
{
	if(id == "")
		throw std::runtime_error("pushState: id is empty");

	if(id == m_activeState.back())
		throw std::runtime_error("pushState: state already on top");

	m_stack.push_back(m_registered[id].get());
	m_activeState.push_back(id);
}

void StateManager::popState()
{
	if(m_stack.size() < 1)
	{
		m_stack.pop_back();
		m_activeState.pop_back();
	}
}

void StateManager::exchangeState( const std::string& id )
{
	popState();
	pushState(id);
}

const std::string& StateManager::getTopState() const
{
	return m_activeState.back();
}
