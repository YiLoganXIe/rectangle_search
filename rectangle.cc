//
// Created by yi on 4/8/19.
//
#include "rectangle.h"

int Rectangle::GetArea() {
    return (x2-x1)*(y2-y1);
}

bool Rectangle::operator<(Rectangle &rhs) {
    if ( this->GetArea() < rhs.GetArea() ) {
        return true;
    }
    return false;
}
