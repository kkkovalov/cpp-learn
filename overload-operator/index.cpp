#include <iostream>
class Cents {

  private:
    int m_cents{};

  public:
    Cents(int cents) : m_cents{cents} {}

    friend Cents operator+(const Cents &c1, const Cents &c2);
    friend Cents operator-(const Cents &c1, const Cents &c2);

    int getCents() { return m_cents; };
};

Cents operator-(const Cents &c1, const Cents &c2) {
    return c1.m_cents - c2.m_cents;
};

Cents operator+(const Cents &c1, const Cents &c2) {
    return c1.m_cents + c2.m_cents;
};

int main() {
    Cents c1{5};
    Cents c2{8};
    Cents centsSum(c1 - c2);
    std::cout << "Subtraction: " << centsSum.getCents() << '\n';
    return 0;
};
