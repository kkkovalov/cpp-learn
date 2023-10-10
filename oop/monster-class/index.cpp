#include <iostream>
#include <string>
#include "Random.h"


class Monster{
  public:
    enum Type{
        Dragon,
        Goblin,
        Ogre,
        Orc,
        Skeleton,
        Troll,
        Vampire,
        Zombie,
        max_monster_types,
    };
    
    Monster(Type type, std::string name, std::string roar, int hitPoints) :
        m_type{type}, m_name{name}, m_roar{roar}, m_hitPoints{hitPoints}
    {
    }

    void print() const;

  private:
    Type m_type{};
    std::string m_name{};
    std::string m_roar{};
    int m_hitPoints{};

    std::string_view getTypeString() const{
        switch(m_type){
            case Type::Dragon:
                return "Dragon";
            case Type::Goblin:
                return "Goblin";
            case Type::Ogre:
                return "Ogre";
            case Type::Orc:
                return "Orc";
            case Type::Skeleton:
                return "Skeleton";
            case Type::Troll:
                return "Troll";
            case Type::Vampire:
                return "Vampire";
            case Type::Zombie:
                return "Zombie";
            
            default:
                return "None";
        }
    }
    
};


void Monster::print() const{
    std::cout << m_name << " the " << getTypeString() << " has " << m_hitPoints << " hit points and says " << m_roar;
}

namespace MonsterGenerator{

    std::string getName(int rnd){
        switch(rnd){
            case 0:
                return "Den";
            case 1:
                return "Neil";
            case 2:
                return "Noah";
            case 3:
                return "Gello";
            case 4:
                return "Adik";
            case 5:
                return "Lom";
            default:
                return "NoName";
        }
    }

    std::string getRoar(int rnd){
        switch(rnd){
            case 0:
                return "Ooouf";
            case 1:
                return "bark-bark";
            case 2:
                return "Lip-lip";
            case 3:
                return "Gafff";
            case 4:
                return "Chirk-chirk";
            case 5:
                return "psyyyy";
            default:
                return "NoRoar";
        }
    }

    Monster generate(){

        return Monster{ Monster::Type(Random::get(0,8)), getName(Random::get(0,5)), getRoar(Random::get(0,5)), Random::get(0,100)};
    };
}

int main(){
    Monster m {MonsterGenerator::generate()};
    m.print();

	return 0;
}
