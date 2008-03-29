#ifndef STARMOUSE_H
#define STARMOUSE_H

#include <StarUtils/Singleton.h>
#include <StarInput/MouseSDL.h>

namespace Star
{
  class Mouse : public Singleton<Mouse>
  {
  public:
    /**
     * Return absolute position of the mouse
     */
    void getPosition(int& x, int& y) const
    {
      m_mouse->getPosition(x, y);
    }

    /**
     * Return true if button is pressed
     */
    bool isButtonPressed(int button) const
    {
      return m_mouse->isButtonPressed(button);
    }

  protected:
    Mouse()
    {
      m_mouse = new MouseSDL();
    }

    ~Mouse()
    {
      delete m_mouse;
    }

  private:
    MouseInterface* m_mouse;
  };
}

#endif
