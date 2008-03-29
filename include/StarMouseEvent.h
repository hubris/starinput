#ifndef STARMOUSEEVENT_H
#define STARMOUSEEVENT_H

namespace Star
{
  class MouseEvent
  {
    MouseEvent(int x, int y, int button)
      : m_x(x), m_y(y), m_button(button)
    {}

    /**
     * Return the button which triggered the event
     */
    inline int getButton() const { return m_button; }

    /**
     * Return absolute position of the mouse when event
     * has been triggered
     */
    inline void getPosition(int& x, int& y) const
    {
      x = m_x;
      y = m_y;
    }

  private:
    int m_x;
    int m_y;
    int m_button;
  };
}


#endif
