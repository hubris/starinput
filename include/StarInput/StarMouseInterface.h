#ifndef STARMOUSEINTERFACE_H
#define STARMOUSEINTERFACE_H

#include <StarInput/StarInput.h>
#include <StarInput/StarMouseEvent.h>
#include <StarInput/StarMouseListener.h>

#include <functional>
#include <algorithm>

namespace Star
{
  class MouseInterface : public Input
  {
  public:
    /**
     * Return absolute position of the mouse
     */
    virtual void getPosition(int& x, int& y) const = 0;

    /**
     * Return true if button is pressed
     */
    virtual bool isButtonPressed(int button) const = 0;

  protected:
    static void mouseMoved(InputListener* l, MouseMoveEvent e)
    {
      static_cast<MouseListener*>(l)->mouseMoved(e);
    }

    static void mousePressed(InputListener* l, MouseButtonPressedEvent e)
    {
      static_cast<MouseListener*>(l)->mousePressed(e);
    }

    static void mouseReleased(InputListener* l, MouseButtonReleasedEvent e)
    {
      static_cast<MouseListener*>(l)->mouseReleased(e);
    }

    void notifyListener(const MouseMoveEvent &e)
    {
      std::for_each(m_listeners.begin(), m_listeners.end(),
                    std::bind2nd(std::ptr_fun(mouseMoved), e));
    }

    void notifyListener(const MouseButtonReleasedEvent &e)
    {
      std::for_each(m_listeners.begin(), m_listeners.end(),
                    std::bind2nd(std::ptr_fun(mouseReleased), e));
    }

    void notifyListener(const MouseButtonPressedEvent &e)
    {
      std::for_each(m_listeners.begin(), m_listeners.end(),
                    std::bind2nd(std::ptr_fun(mousePressed), e));
    }

  };
}

#endif
