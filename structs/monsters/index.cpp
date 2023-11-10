#include <iostream>
#include <string>

enum class MonsterType
{
    Ogre,
    Dragon,
    Orc,
    GiantSpider,
    Slime,
};

struct Monster
{
    MonsterType type{};
    std::string name{};
    int health{};
};

constexpr std::string_view getMonsterTypeString(MonsterType type)
{
    switch (type)
    {
    case MonsterType::Ogre:
        return "Ogre";
    case MonsterType::Orc:
        return "Orc";
    case MonsterType::Dragon:
        return "Dragon";
    case MonsterType::GiantSpider:
        return "Giant Spider";
    case MonsterType::Slime:
        return "Slime";
    }

    return "Unknown";
}

void printMonster(const Monster &monster)
{
    std::cout << "This " << getMonsterTypeString(monster.type) << " is named " << monster.name << " and has " << monster.health << " health.\n";
};

int main()
{

    Monster ogre{MonsterType::Ogre, "Torg", 145};
    Monster slime{MonsterType::Slime, "Blurp", 23};
    printMonster(ogre);
    printMonster(slime);
}
