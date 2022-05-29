// Lab7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

//Абстрактный класс. Тип существо
class Creature{ 
public:
    Creature() {cout << "Constructor " << typeid(*this).name() << endl;}
    virtual ~Creature() { cout << "Destructor " << typeid(*this).name() << endl; } 
    virtual void SetName(string name) = 0;
    virtual string GetName() = 0;
    virtual void whoami() = 0;
    string name;
};

//Установка оружия
class Weapon {
public:
    string weapon;
    Weapon() { cout << "Constructor " << typeid(*this).name() << endl; }
    virtual ~Weapon() { cout << "Destructor " << typeid(*this).name() << endl; }
    virtual void SetWeapon(string weapon) = 0;
    virtual string GetWeapon() = 0;
};

//Раса Орк
class Ork : public Creature {
public:
    Ork() { cout << "Constructor " << typeid(*this).name() << endl; }
    Ork(int weight, int power) {
        cout << "Constructor " << typeid(*this).name() << " with parameters" <<  endl;
        this->weight = weight;
        this->power = power;
    }
    virtual ~Ork() { cout << "Destructor " << typeid(*this).name() << endl; }
    virtual void SetCharacteristics(int weight, int power) = 0;
    virtual int GetWeight() = 0;
    virtual int GetPower() = 0;
    int weight = 0;
    int power = 0;
    
};
//Раса человек
class Human : public Creature {
public:
    Human() { cout << "Constructor " << typeid(*this).name() << endl; }
    virtual ~Human() { cout << "Destructor " << typeid(*this).name() << endl; }
    virtual void SetCharacteristics(int height, int intelligence) = 0;
    virtual int Getheight() = 0;
    virtual int Getintelligence() = 0;
    int height = 0;
    int intelligence = 0;
};

class Archer : public Human {
public:
    Archer() { cout << "Constructor " << typeid(*this).name() << endl; }
    virtual ~Archer() { cout << "Destructor " << typeid(*this).name() << endl; }
    void print(){
        cout << "Hello, im archer!" << endl;
    }
};
//Класс воин расы Орк с оружием
class Warrior : public Ork, public Weapon {
public:
    Warrior() : Ork(150, 200) // Вызов базового класса Ork с параметрами по умолчанию для данной расы
    { cout << "Constructor " << typeid(*this).name() << endl; }
    ~Warrior() { cout << "Destructor " << typeid(*this).name() << endl; }
    void SetName(string name) override {
        this->name = name;
    }
    void SetCharacteristics(int weight, int power) override  {
        this->weight = weight;
        this->power = power;
    }
    
    void SetWeapon(string weapon) override {
        this->weapon = weapon;
    };
    string GetWeapon() override {
        return this->weapon;
    }

    int GetWeight() override{
        return this -> weight;
    };
    int GetPower() override {
        return this->power;
    };
   
    string GetName() override { return this -> name; }

    void whoami() override { cout << "I'm: " << typeid(*this).name() << endl; }
};


//Класс гибрид для примера виртуального наследования(ромбовидное наследование)
class Hybrid : public Human, virtual public Ork {
    void SetCharacteristics(int weight, int power) override {
        
    }
};
int main()
{   
    
    Warrior NumberOne;
    NumberOne.SetName("Jack");
    cout << "His name: " << NumberOne.GetName() << endl;
    cout << "Default his power: " <<  NumberOne.GetPower() << endl;
    cout << "Default his weight: " << NumberOne.GetWeight() << endl;
    NumberOne.SetCharacteristics(120, 60);
    cout << "His power: " << NumberOne.GetPower() << endl;
    cout << "His weight: " << NumberOne.GetWeight() << endl;
    NumberOne.SetWeapon("Axe");
    cout << "His weapon: " << NumberOne.GetWeapon() << endl;
    
    Creature* example = new Warrior();
    example->whoami();
    delete example;

    
    
}

