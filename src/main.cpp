#include <iostream>
class CCircle;

//class A {
//    CCircle *c;
//};

class CPoint {
public:
    unsigned x;
    unsigned y;
    bool IsInCircle(CCircle *Circle);
};

class CCircle {
public:
    unsigned Radius;
    CPoint Center;
};

bool CPoint::IsInCircle(CCircle *Circle) {
    return (((x - Circle->Center.x) * (x - Circle->Center.x)
        + (y - Circle->Center.y) * (y - Circle->Center.y)) <= Circle->Radius * Circle->Radius);
}

int main() {

    return 0;
}

