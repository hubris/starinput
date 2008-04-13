#ifndef STARMOUSESDL_H
#define STARMOUSESDL_H

#include <StarInput/StarMouseInterface.h>
#include <StarInput/StarMouseEvent.h>

#include <SDL.h>

namespace Star
{
  class MouseSDL : public MouseInterface
  {
  public:
    /**
     * Constructor
     */
    MouseSDL() : m_buttonState(0), m_x(0), m_y(0)
    {
    }

    /**
     * Return absolute position of the mouse
     */
    virtual void getPosition(int& x, int& y) const
    {
      x = m_x;
      y = m_y;
    }

    /**
     * Return true if button is pressed
     */
    virtual bool isButtonPressed(int button) const
    {
      return m_buttonState&SDL_BUTTON(button);
    }

    /**
     * Check all state and notify listener of state change
     */
    virtual void updateState()
    {
      Uint8 oldState = m_buttonState;
      int oldX = m_x;
      int oldY = m_y;
      m_buttonState = SDL_GetMouseState(&m_x, &m_y);

      if(m_buttonState != oldState) {
        for(int i = 1; i <= 5; i++) {
          bool pressed = m_buttonState&SDL_BUTTON(i);
          if(pressed != oldState&SDL_BUTTON(i))
            pressed?notifyListener(MouseButtonPressedEvent(i)):notifyListener(MouseButtonReleasedEvent(i));
        }
      }

      if(m_x != oldX || m_y != oldY)
        notifyListener(MouseMoveEvent(m_x, m_y, m_x-oldX, m_y-oldY));
    }

  private:
    Uint8 m_buttonState;
    int m_x;
    int m_y;
  };
}


#endif
