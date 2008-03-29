#ifndef STARINPUT_H
#define STARINPUT_H

#include <StarInput/StarInputListener.h>

#include <list>

namespace Star
{
  class Input
  {
  public:
    /**
     * Add a listener
     */
    void addListener(InputListener* listener);

    /**
     * Remove a listener
     */
    void removeListener(InputListener* listener);

    /**
     * Check all state and notify listener of state change
     */
    virtual void updateState() = 0;

  private:
    typedef std::list<InputListener*> ListenerList;
    ListenerList m_listeners;
  };
}

#endif
