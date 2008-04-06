#ifndef STARMOUSESDL_H
#define STARMOUSESDL_H

#include <StarInput/StarMouseInterface.h>

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
      m_buttonState = SDL_GetMouseState(&m_pos[0], &m_pos[1]);
    }

  private:
    Uint8 m_buttonState;
    int m_x;
    int m_y;
  };
}


#endif
