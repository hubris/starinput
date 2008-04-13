#ifndef STARMOUSE_H
#define STARMOUSE_H

#include <StarUtils/StarSingleton.h>
#include <StarInput/StarMouseSDL.h>

namespace Star
{
  class Mouse : public Singleton<Mouse>
  {
  public:
    Mouse()
    {
      m_mouse = new MouseSDL();
    }

    ~Mouse()
    {
      delete m_mouse;
    }

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

    /**
     * Add a listener
     */
    void addListener(MouseListener* listener);

    /**
     * Remove a listener
     */
    void removeListener(MouseListener* listener);

    /**
     * Check all state and notify listener of state change
     */
    void updateState() { m_mouse->updateState(); }

  private:
    MouseInterface* m_mouse;
  };

#define g_StarMouse (*Star::Mouse::getInstance())
}

#endif
