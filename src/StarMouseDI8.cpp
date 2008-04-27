#include <StarInput/StarMouseDI8.h>

#include <StarInput/StarMouseInterface.h>
#include <StarInput/StarMouseEvent.h>
#include <StarInput/StarInputDI8.h>
#include <StarUtils/StarExceptions.h>

namespace Star
{
  /****************************************************************************/
  MouseDI8::MouseDI8(HWND hWnd, HINSTANCE hInst)
    : m_hWnd(hWnd), m_x(0), m_y(0), m_useSystemCursor(true)
  {
    HRESULT hr; 
    InputDI8::getInstance()->init(hInst);
    hr = InputDI8::getInstance()->getDi()->CreateDevice(GUID_SysMouse, &m_mouse, NULL);       
    if FAILED(hr)            
      throw Exception("MouseDI8::MouseDI8: Can't create mouse device!\n");
    
    hr = m_mouse->SetDataFormat(&c_dfDIMouse2);
    if (FAILED(hr))
      throw Exception("MouseDI8::MouseDI8: Can't set data format!\n");

    hr = m_mouse->SetCooperativeLevel(hWnd,  DISCL_NONEXCLUSIVE|DISCL_FOREGROUND);
    if (FAILED(hr))
      throw Exception("MouseDI8::MouseDI8: Can't set coopertative level!\n");

    acquire();
    m_mouse->GetDeviceState(sizeof(m_state), (LPVOID)&m_state); 
  }

  /****************************************************************************/
  MouseDI8::~MouseDI8() 
  {
    m_mouse->Unacquire();
    m_mouse->Release();
    m_mouse = NULL;
  }

  /****************************************************************************/
  void
  MouseDI8::getPosition(int& x, int& y) const
  {
    x = m_x;
    y = m_y;
  }

  /****************************************************************************/
  bool 
  MouseDI8::isButtonPressed(int button) const
  {
    return m_state.rgbButtons[button] != 0;
  }

  /****************************************************************************/
  void 
  MouseDI8::updateState()
  {   
    DIMOUSESTATE2 oldState = m_state;
    HRESULT hr;
    int retry = 0;
    do {      
      hr = m_mouse->GetDeviceState(sizeof(m_state), (LPVOID)&m_state);
      if(FAILED(hr)) {
        if(hr != DIERR_INPUTLOST && hr != DIERR_NOTACQUIRED || retry++ > 2)
          return;
        acquire();        
      }
    } while(FAILED(hr));
    
    for(int i = 0; i <= 8; i++) {
      bool pressed = m_state.rgbButtons[i] != 0;
      if(pressed != (oldState.rgbButtons[i] != 0))
        pressed?notifyListener(MouseButtonPressedEvent(i)):notifyListener(MouseButtonReleasedEvent(i));
    }

    if(!m_useSystemCursor) {
      m_x += m_state.lX;
      m_y += m_state.lY;
    } else {
      POINT point;
      GetCursorPos(&point);
      ScreenToClient(m_hWnd, &point);
      m_x = point.x;
      m_y = point.y;
    }

    if(m_state.lX != oldState.lX || m_state.lY != oldState.lY )
      notifyListener(MouseMoveEvent(m_x, m_y, 
                                    m_state.lX,
                                    m_state.lY));
  }

  /****************************************************************************/
  void
  MouseDI8::acquire()
  {
    HRESULT hr = m_mouse->Acquire();
    if(FAILED(hr))		
      return;
  }
}