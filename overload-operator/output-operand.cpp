#include <iostream>

class Point {
  private:
    int m_x{};
    int m_y{};
    int m_z{};

  public:
    // constructor for the Artisan point
    Point(int x = 0, int y = 0, int z = 0) : m_x{x}, m_y{y}, m_z{z} {};

    friend std::ostream& operator<<(std::ostream& out, const Point& point);
    friend std::istream& operator>>(std::istream& in, Point& point);

    int getPoint_x() { return m_x; };
    int getPoint_y() { return m_y; };
    int getPoint_z() { return m_z; };
};

std::ostream &operator<<(std::ostream &out, const Point &point) {

    out << "Point(" << point.m_x << ", " << point.m_y << ", " << point.m_z
        << ")";

    return out;
}

std::istream& operator>> (std::istream& in, Point& point){
    in >> point.m_x;
    in >> point.m_y;
    in >> point.m_z;

    return in;
}

int main() {
    int x, y, z;
    std::cin >> x >> y >> z;
    Point point1(x, y, z);
    std::cout << point1 << '\n';
    return 0;
};
