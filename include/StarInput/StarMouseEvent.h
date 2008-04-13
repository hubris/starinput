#ifndef STARMOUSEEVENT_H
#define STARMOUSEEVENT_H

namespace Star
{
  class MouseEvent
  {
  };

  /**
   * Event trigerred when a button is pressed/released
   */
  class MouseButtonEvent : public MouseEvent
  {
  public:
    MouseButtonEvent(int button)
      : m_button(button)
    {}

    /**
     * Return the button which triggered the event if any
     */
    inline int getButton() const { return m_button; }


  protected:
    int m_button;
  };

  /**
   * Event trigerred when a button is pressed
   */
  class MouseButtonPressedEvent : public MouseButtonEvent
  {
  public:
    MouseButtonPressedEvent(int b) : MouseButtonEvent(b) {}
  };

  /**
   * Event trigerred when a button is released
   */
  class MouseButtonReleasedEvent : public MouseButtonEvent
  {
  public:
    MouseButtonReleasedEvent(int b) : MouseButtonEvent(b) {}
  };

  /**
   * Event trigerred when the mouse moves
   */
  class MouseMoveEvent : public MouseEvent
  {
  public:
    MouseMoveEvent(int x, int y, int relX, int relY)
      : m_x(x), m_y(y), m_relX(relX), m_relY(relY)
    {}

    /**
     * Return absolute position of the mouse when event
     * has been triggered
     */
    inline void getPosition(int& x, int& y) const
    {
      x = m_x;
      y = m_y;
    }

    /**
     * Return relative position of the mouse since a previous
     * event has been triggered
     */
    inline void getRelativePosition(int& x, int& y) const
    {
      x = m_relX;
      y = m_relY;
    }

  private:
    int m_x;
    int m_y;
    int m_relX;
    int m_relY;
  };
}


#endif
