//
// Created by Jiang Yinzuo on 2021/6/17.
//

class A {
public:
    static int b;
};
int A::b = 3;

int main() {
    A::b = 3;
    return 0;
}