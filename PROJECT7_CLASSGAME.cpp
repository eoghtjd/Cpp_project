#include<iostream>
#include <cstdlib>
#include <ctime>
#include<vector>


using namespace std;

class Weapon {
protected:
    int dmg;
    int turn;

public:
    Weapon(int dmg, int turn) {
        this->dmg = dmg;
        this->turn = turn;
    }

    virtual int get_turn() {
        return this->turn;
    }
    int get_dmg()
    {
        return this->dmg;
    }

    virtual void print_info() {
        cout << "Damage: " << dmg << ", Turn: " << turn << endl;
    }

    virtual void print_attack() = 0;
};

class Sword : public Weapon {
public:
    Sword() : Weapon(5, 3) {}

    void print_attack() override {
        cout << "stabs" << endl;
        
    }
    int get_turn() {        
         return turn = (rand() % 3) + 1;
    }
    int get_dmg() {
        return dmg;
    }
};

class Firearm : public Weapon {
public:
    Firearm() : Weapon(10, 1) {}

    void print_attack() override {
        cout << "shots" << endl;
    }
    int get_turn() {
        return turn;
    }
    int get_dmg() {
        return dmg;
    }
};

class Character {
protected:
    string name;
    static int hp;
    int level;

public:
    Weapon* currentWeapon;
    bool hasWeapon = false;

public:
    Character(string name, int hp, int level) {
        this->name = name;
        this->hp = hp;
        this->level = level;
        this->currentWeapon = nullptr;
    }

    void pickupWeapon(Weapon* weapon) {
        currentWeapon = weapon;
    }

    void attack() {
        if (currentWeapon != nullptr) {
            cout << name << "'s turn and ";
            currentWeapon->print_attack();
            
        }
        else {
            cout << "nothing happened" << endl;
            
        }
        
       
    }

    void set_name(string new_name) {
        name = new_name;
    }

    string get_name() {
        return name;
    }

    int get_level() {
        return level;
    }

    int get_hp() {
        return hp;
    }

    void set_hp(int new_hp) {
        hp = new_hp;
    }

    Weapon* get_currentWeapon() {
        return currentWeapon;
    }

    int hp_after() {
        

    }
    
};

int Character::hp = 100;

int main() {
    srand(time(NULL));
    
    int randomNumber = rand() % 3 + 1;

    char action;
    string name, new_name;
    cout << "What's your name?" << endl;
    cin >> name;
    cout << endl;
    string com2 = "com2";
    Character person(name, 100, 1);
    Character com(com2, 100, 1);
   

    while (true) {
        
        cout << "Command list " << endl;
        cout << "0: terminate " << endl;
        cout << "1: rename " << endl;
        cout << "2: weapon " << endl;
        if (person.hasWeapon)
        {
            cout << "3: status " << endl;
            cout << "4: attack " << endl << endl;
            
        }
        else {
            cout << "3: status " << endl << endl;
        }
        
        cin >> action;
        cout << endl;

        if (action == '0') break;
        if (action < '0' || action > '4') {
            cout << "Error" << endl;
            continue;
        }

        int remain_hp = 0;
        switch (action) {
        case '1':
            cout << "What's new name?" << endl;
            cin >> new_name;
            person.set_name(new_name);
            cout << "new name: " << person.get_name() << endl;
            break;
        case '2':
            int pickupWeapon;
            cout << "Choose a weapon:" << endl;
            cout << "1: Sword" << endl;
            cout << "2: Firearm" << endl;
            cin >> pickupWeapon;

            if (pickupWeapon == 1) {
                person.pickupWeapon(new Sword());
                person.hasWeapon = true;
            }
            else if (pickupWeapon == 2) {
                person.pickupWeapon(new Firearm());
                person.hasWeapon = true;
            }
            else {
                cout << "Invalid" << endl;
                continue;
            }
            cout << "Picked up a weapon." << endl;
            break;
        case '4':

           
            person.attack();
            cout << "Ghoul hp: ";
            remain_hp = com.get_hp() - (person.currentWeapon->get_dmg() * person.currentWeapon->get_turn()) ;
            com.set_hp(remain_hp);
            cout << com.get_hp() << endl;
            if (com.get_hp() <0 )
            {
                cout << "Clear" << endl;

                return -1;
            }

            break;
        case '3':
            cout << "Name: " << person.get_name() << endl;
            cout << "Lv: " << person.get_level() << endl;
            cout << "HP: " << person.get_hp() << endl;
            if (person.get_currentWeapon() != nullptr) {
                cout << person.get_currentWeapon() << ": ";
                person.get_currentWeapon()->print_info();
            }
            else {
                cout << "Unarmed" << endl;
            }
            break;
        default:
            cout << "Invalid." << endl;
            break;
        }
        cout << endl;
    }
    cout << "End" << endl;
}

//공격 & 체력 넣기