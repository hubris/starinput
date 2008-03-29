#ifndef STARMOUSELISTENER_H
#define STARMOUSELISTENER_H

namespace Star
{
  class MouseListener : public InputListener
  {
    virtual void mouseClicked(const MouseEvent& e) {}
    virtual void mousePressed(const MouseEvent& e) {}
    virtual void mouseReleased(const MouseEvent& e) {}
  };
}


#endif
