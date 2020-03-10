#pragma once
#include <iostream>
#include <set>
using namespace std;
class Dots {
public:
    double DotX;
    double DotY;
    Dots() {
        DotX = 0;
        DotY = 0;
    }
    Dots(double X, double Y) {
        DotX = X;
        DotY = Y;
    }
};
class DotsCmp {
public:
    bool operator()(const Dots& dotA, const Dots& dotB) const {
        if (dotA.DotX == dotB.DotX) {
            return (dotA.DotY < dotB.DotY);
        }
        else {
            return (dotA.DotX < dotB.DotX);
        }
    }
};
typedef set<Dots, DotsCmp> DotsSet;

class CalDots {
private:
    DotsSet _set;
public:
    CalDots();
    Dots CalDot(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3);
    int DotsSize();
};