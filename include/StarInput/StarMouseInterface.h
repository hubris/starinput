#ifndef STARMOUSEINTERFACE_H
#define STARMOUSEINTERFACE_H

#include <StarInput/StarInput.h>

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
  };
}

#endif
