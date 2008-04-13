#include <StarInput/StarInput.h>
#include <StarInput/StarInputListener.h>

#include <algorithm>
#include <cassert>

namespace Star
{
/******************************************************************************/
  void
  Input::addListener(InputListener* listener)
  {
    ListenerList::iterator it;
    it = std::find(m_listeners.begin(), m_listeners.end(), listener);
    assert(it == m_listeners.end() && "Listener already in list");

    m_listeners.push_back(listener);
  }

/******************************************************************************/
  void
  Input::removeListener(InputListener* listener)
  {
    m_listeners.remove(listener);
  }
}
