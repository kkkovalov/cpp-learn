#include <iostream>
#include <string>
#include <string_view>

class Ball
{
  private:
    std::string m_color{"black"};
    double m_radius{10.0};
  public:
    // Handles Ball(radius)
    Ball(double radius) : Ball{"black", radius}
    {
    }

    // Handles Ball(color, radius), Ball(color), and Ball()
    Ball(std::string_view color = "black", double radius = 10.0) : m_color{color}, m_radius{radius}
    {
        std::cout << "Ball(" << m_color << ", " << m_radius << ")\n";
    }
};

int main()
{
  int a,b;
  std::cout << "Please enter a & b: ";
  std::cin >> a >> b;
  Ball def{};
  Ball blue{"blue"};
  Ball twenty{20.0};
  Ball blueTwenty{"blue", 20.0};

  return 0;
}
