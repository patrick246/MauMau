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
		throw std::runtime_error("StateManager::registerState: State already registered: " + id);

	if(state == nullptr)
		throw std::runtime_error("StateManager::registerState: State is nullptr: " + id);

	m_registered[id] = std::move(state);
}

void StateManager::pushState( const std::string& id )
{
	if(id == "")
		throw std::runtime_error("StateManager::pushState: id is empty");

	if(m_activeState.size() > 0 && id == m_activeState.back())
		throw std::runtime_error("StateManager::pushState: state already on top");

	if(m_registered.find(id) == m_registered.end())
		throw std::runtime_error("StateManager::pushState: state " + id + " not registered");

	m_stack.push_back(m_registered[id].get());
	m_activeState.push_back(id);
}

void StateManager::popState()
{
	if(m_stack.size() == 0)
		throw std::runtime_error("StateManager::getTopStateID, state-stack is empty");
	m_stack.pop_back();
	m_activeState.pop_back();
}

void StateManager::exchangeState( const std::string& id )
{
	popState();
	pushState(id);
}

const std::string& StateManager::getTopStateID() const
{
	if(m_stack.size() == 0)
		throw std::runtime_error("StateManager::getTopStateID, state-stack is empty");
	return m_activeState.back();
}

void StateManager::draw( sf::RenderTarget &t,sf::RenderStates s) const
{
	if(m_stack.size() == 0)
		throw std::runtime_error("StateManager::draw, state-stack is empty");
	m_stack.back()->draw(t, s);
}

void StateManager::update( float frametime )
{
	if(m_stack.size() == 0)
		throw std::runtime_error("StateManager::update, state-stack is empty");
	m_stack.back()->update(frametime);
}
