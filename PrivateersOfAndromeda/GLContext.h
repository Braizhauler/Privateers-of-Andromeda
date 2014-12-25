#pragma once
#include <gl/GL.h>

class GLContext
{

public:
	GLContext(void);
	~GLContext(void);
	void init(HWND hWnd);
	void purge();
private:
    void reset();
    {
        mhWnd = NULL;
        mhDC = NULL;
        mhRC = NULL;
     }
    HWND mhWnd;
    HDC mhDC;
    HGLRC mhRC;
};

