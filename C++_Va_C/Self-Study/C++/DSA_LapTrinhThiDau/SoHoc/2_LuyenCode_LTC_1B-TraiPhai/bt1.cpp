#include <iostream>

struct Vect2d {
    long int x;
    long int y;
};

long int calc(Vect2d v1, Vect2d v2) {
    return v1.x * v2.y - v2.x * v1.y;
}

int main() {
    long int x1, y1, x2, y2, x3, y3;

    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    Vect2d v1, v2;

    // vector AB
    v1.x = x2 - x1;
    v1.y = y2 - y1;

    // vector AC
    v2.x = x3 - x1;
    v2.y = y3 - y1;

    long int result = calc(v1, v2);

    int ON_THE_LINE = 0, LEFT = -1, RIGHT = 1;

    if (result == 0)
        std::cout << ON_THE_LINE;
    else if (result > 0)
        std::cout << LEFT;
    else
        std::cout << RIGHT;

    return 0;
}
