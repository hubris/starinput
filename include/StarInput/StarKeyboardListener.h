#ifndef STARKEYBOARDLISTENER_H
#define STARKEYBOARDLISTENER_H

namespace Star
{
  class KeyboardListener : public InputListener
  {
    virtual void keyPressed(const KeyboardEvent& e) {}
    virtual void keyReleased(const KeyboardEvent& e) {}
  };
}


#endif
