#pragma once

class Factory
{
public:
    Factory();
    virtual ~Factory() = default;

    template<class T>
    T* create()
    {
        return new T;
    };

private:
};