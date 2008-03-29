#ifndef STARMOUSESDL_H
#define STARMOUSESDL_H

#include <StarInput/StarMouseInterface.h>

namespace Star
{
  class MouseSDL : public MouseInterface
  {
  public:
    /**
     * Return absolute position of the mouse
     */
    virtual void getPosition(int& x, int& y) const
    {
      x = y = 0;
    }

    /**
     * Return true if button is pressed
     */
    virtual bool isButtonPressed(int button) const
    {
      return false;
    }

    /**
     * Check all state and notify listener of state change
     */
    virtual void updateState()
    {
    }
  };
}


#endif
