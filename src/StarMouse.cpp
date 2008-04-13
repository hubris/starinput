#include <StarInput/StarMouse.h>

namespace Star {
  void
  Mouse::addListener(MouseListener* listener)
  {
    m_mouse->addListener(listener);
  }

  void
  Mouse::removeListener(MouseListener* listener)
  {
    m_mouse->removeListener(listener);
  }
}
