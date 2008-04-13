#ifndef STARMOUSELISTENER_H
#define STARMOUSELISTENER_H

#include <StarInput/StarInputListener.h>

namespace Star
{
  class MouseListener : public InputListener
  {
  public:
    virtual void mouseClicked(const MouseButtonEvent& e) {}
    virtual void mousePressed(const MouseButtonPressedEvent& e) {}
    virtual void mouseReleased(const MouseButtonReleasedEvent& e) {}
    virtual void mouseMoved(const MouseMoveEvent& e) {}
  };
}


#endif
