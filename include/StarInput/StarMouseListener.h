#ifndef STARMOUSELISTENER_H
#define STARMOUSELISTENER_H

#include <StarInput/StarInputListener.h>

namespace Star
{
  class MouseListener : public InputListener
  {
  public:
    /**
     * Destructor
     */
    virtual ~MouseListener() {}

    virtual void mouseClicked(const MouseButtonEvent&) {}
    virtual void mousePressed(const MouseButtonPressedEvent&) {}
    virtual void mouseReleased(const MouseButtonReleasedEvent&) {}
    virtual void mouseMoved(const MouseMoveEvent&) {}
  };
}


#endif
