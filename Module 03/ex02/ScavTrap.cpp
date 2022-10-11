#include"ScavTrap.hpp"

void ScavTrap::guardGate(){
    std::cout << "ScavTrap " << _name << " now is in Gate mode\n";
}
ScavTrap::ScavTrap() : ClapTrap("unknown") {
    std::cout << "ScavTrap defaut constructor\n";
    std::cout << "insert ScavTrap name:  ";
    std::cin >> _name;
    this->_damage = 20;
    this->_EP = 50;
    this->_HP = 100;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
    std::cout << "ScavTrap string constructor\n";
    this->_damage = 20;
    this->_EP = 50;
    this->_HP = 100;
    this->_name = name;
}

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap destructor\n";
}

ScavTrap::ScavTrap(const ScavTrap &srcForCopy){
    std::cout << "ScavTrap copy constructor\n";
    *this = srcForCopy;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &srcForAssigment){
    std::cout << "ScavTrap assigment constructor\n";
    this->_damage = srcForAssigment._damage;
    this->_EP = srcForAssigment._EP;
    this->_HP = srcForAssigment._HP;
    this->_name = srcForAssigment._name;
    return *this;
}

void ScavTrap::attack(const std::string& target){
    if(_HP > 0 && _EP != 0){
        _EP--;
        std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _damage << " points of damage!\n";
    }
}

void ScavTrap::takeDamage(unsigned int amount){
    if(_HP != 0){
        if(amount >= _HP)
            _HP = 0;
        else
            _HP -= amount;
        std::cout << "ScavTrap " << _name << " takes " << amount << " points of damage!\n";
    }
}

void ScavTrap::beRepaired(unsigned int amount){
    if(_HP > 0 && _EP != 0){
        _EP--;
        _HP += amount;
        std::cout << "ScavTrap " << _name << " restore " << amount << " HP!\n";
    }
}