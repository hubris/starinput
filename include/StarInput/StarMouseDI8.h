#ifndef STARMOUSEDI8_H
#define STARMOUSEDI8_H

#include <StarInput/StarMouseInterface.h>
#include <StarInput/StarMouseEvent.h>
#include <StarInput/StarInputDI8.h>
#include <StarUtils/StarExceptions.h>

namespace Star
{
  class MouseDI8 : public MouseInterface
  {
  public:
    /**
     * Constructor
     */
    MouseDI8(HWND hWnd, HINSTANCE hInst);

    /**
     * Destructor
     */
    virtual ~MouseDI8();

    /**
     * Return absolute position of the mouse
     */
    virtual void getPosition(int& x, int& y) const;

    /**
     * Return true if button is pressed
     */
    virtual bool isButtonPressed(int button) const;

    /**
     * Check all state and notify listener of state change
     */
    virtual void updateState();

    /** If true use system cursor pos(for windowed mode) */
    void setUseSystemCursor(bool flag) { m_useSystemCursor = flag; }

  private:
    /** window handle */
    HWND m_hWnd;

    /** acquire the device */
    void acquire();

    LPDIRECTINPUTDEVICE8 m_mouse; 
    DIMOUSESTATE2 m_state;
    int m_x, m_y;

    /** If true use system cursor pos(for windowed mode) */
    bool m_useSystemCursor;
  };
}


#endif
