#include <StarInput/StarInput.h>
namespace Star
{
/******************************************************************************/
  void
  Input::addListener(StarInputListener* listener)
  {
    ListenerList::iterator it;
    it = std::find(m_listeners.begin(), m_listeners.end(), listener);
    assert(it == m_listeners.end() && "Listener already in list");

    m_listeners.push_back(listener);
  }

/******************************************************************************/
  void
  Input::removeListener(StarInputListener* listener)
  {
    m_listeners.remove(listener);
  }
}
