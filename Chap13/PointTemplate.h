#ifndef __POINT_TEMPLATE_H
#define __POINT_TEMPLATE_H

template<typename T>
class Point
{
private:
    T xpos, ypos;
public:
    Point(T x=0, T y=0);
    void ShowPosition() const;
};

#endif
