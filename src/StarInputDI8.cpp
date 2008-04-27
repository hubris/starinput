#include <StarInput/StarInputDI8.h>
#include <StarUtils/StarExceptions.h>

namespace Star
{
  /***************************************************************************/  
  InputDI8::InputDI8() 
    : m_di8(NULL)
  {
  }

  /***************************************************************************/
  void
  InputDI8::init(HINSTANCE hInst) 
  {
    if(m_di8)
      return;

    HRESULT hr;
    hr = DirectInput8Create(hInst, DIRECTINPUT_VERSION, 
                            IID_IDirectInput8, (void**)&m_di8, NULL); 

    if FAILED(hr)            
      throw Exception("StarInputDI8::StarInputDI8: Can't create direct input interface!\n");
  }

  /***************************************************************************/
  InputDI8::~InputDI8()
  {
    m_di8->Release();
    m_di8 = NULL;
  }
}