#pragma once
#include <string>

class Window
{
public:
    Window() = default;
    ~Window() = default;

    virtual bool handleInputs() = 0;

    virtual void init(std::string t_windowName, int t_width, int t_height) = 0;

    virtual void draw() = 0;

    virtual Window* getWindow() {return this;};
};