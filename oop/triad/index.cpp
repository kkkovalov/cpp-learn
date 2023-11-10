#include <iostream>
#include <string>

template <typename T, typename U, typename K>
class Triad{
    private:
        T m_first{};
        U m_second{};
        K m_third{};

    public:
        Triad(const T& first, const U& second, const K& third) : m_first{first}, m_second(second), m_third{third}{

        };

        // const T& first(){return m_first;}
        // const U& second(){return m_second;}
        // const K& third(){return m_third;}

        void print() const;

};

template <typename T, typename U, typename K>
void Triad<T, U, K>::print() const{
    std::cout << '[' << m_first << ", " << m_second << ", " << m_third << ']';
};

int main(){
    Triad<int, int, int> t1{ 1, 2, 3 };
	t1.print();
	std::cout << '\n';
    
	using namespace std::literals::string_literals;
	const Triad t2{ 1, 2.3, "Hello"s };
	t2.print();
	std::cout << '\n';

	return 0;
}