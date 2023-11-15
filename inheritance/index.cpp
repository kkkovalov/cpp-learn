#include <array>
#include <iostream>
#include <string>

class Creature {
  protected:
    std::string m_name;
    char m_symbol;
    int m_health;
    int m_attackDamage;
    int m_goldAmount;

  public:
    Creature(std::string name, char symbol, int health, int attackDamage,
             int goldAmount)
        : m_name{name}, m_symbol{symbol}, m_health{health},
          m_attackDamage{attackDamage}, m_goldAmount{goldAmount} {};

    std::string &getName() { return m_name; };
    char const getSymbol() { return m_symbol; };
    int const getHealth() { return m_health; };
    int const getAttackDamage() { return m_attackDamage; };
    int const getGoldAmount() { return m_goldAmount; };

    void reduceHealth(int healthReducedByValue) {
        if (healthReducedByValue > m_health)
            m_health = 0;
        else
            m_health -= healthReducedByValue;
        std::cout << "Ouch, that hurt!\n";
    };

    bool isDead() { return m_health == 0; };

    void addGold(int goldAddedByValue) {
        m_goldAmount += goldAddedByValue;
        std::cout << "Cha-ching!\n";
    };

    friend std::ostream &operator<<(std::ostream &out,
                                    const Creature &creature){};
};

class Player : public Creature {
  private:
    int m_level{1};

  public:
    Player(std::string playerName) : Creature{playerName, '@', 10, 1, 0} {
        std::cout << "Welcome, Alex.\nYou have " << m_health
                  << " health and are carrying " << m_goldAmount << " gold.\n";
    };

    void levelUp() {
        ++m_level;
        ++m_attackDamage;
    };

    int getLevel() { return m_level; };

    bool hasWon() { return m_level >= 20; };
};

class Monster : public Creature {
  public:
    enum class Type { dragon, orc, slime, max_types };

  private:
    static const Creature &getDefaultCreature(Type type) {
        static const std::array<Creature,
                                static_cast<std::size_t>(Type::max_types)>
            monsterData{{{"dragon", 'D', 20, 4, 100},
                         {"orc", 'o', 4, 2, 25},
                         {"slime", 's', 1, 1, 10}}};

        return monsterData.at(static_cast<std::size_t>(type));
    }

  public:
    Monster(Type type) : Creature{getDefaultCreature(type)} {}
};

int main() {
    std::cout << "Please enter user name: ";
    std::string playerName;
    std::cin >> playerName;

    Player p{playerName};

    Monster m{Monster::Type::orc};
    std::cout << "A " << m.getName() << " (" << m.getSymbol()
              << ") was created.\n";

    return 0;
};
