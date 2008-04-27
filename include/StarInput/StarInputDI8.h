#ifndef STARINPUTINTDI8_H
#define STARINPUTINTDI8_H

#include <StarUtils/StarSingleton.h>
#include <dinput.h>

namespace Star
{
  class InputListener;

  class InputDI8 : public Singleton<InputDI8>
  {
  public:
    /** Constructor */
    InputDI8();

    /** Init the singleton  */
    void init(HINSTANCE hInst);

    /** Get direct input interface */
    inline IDirectInput8* getDi() const { return m_di8; }

  protected:
    /** Destructor */   
    virtual ~InputDI8();

    IDirectInput8* m_di8;  
  };
}

#endif
