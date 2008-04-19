#ifndef STARINPUTINT_H
#define STARINPUTINT_H

#include <list>

namespace Star
{
  class InputListener;

  class Input
  {
  public:
    /**
     * Destructor
     */
    virtual ~Input() {}

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

  protected:
    typedef std::list<InputListener*> ListenerList;
    ListenerList m_listeners;
  };
}

#endif
