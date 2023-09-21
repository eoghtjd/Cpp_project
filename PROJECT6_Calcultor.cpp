#include <iostream>

using namespace std;

class Character {

    double x = 0;
    double y;
    double cal = 0;
public:
    Character(double x, double y) {
        this->x = x;
        this->y = y;

    }

    void setx(double x) {
        this->x = x;
    }
    void sety(double y) {
        this->y = y;
    }


    double add() {
        return x + y;
    }

    double subtract() {
        return x - y;
    }

    double multiply() {
        return x * y;
    }

    double divide() {
        if (y == 0) {
            cout << "y could not be 0" << endl;
            return 0;
        }

        return x / y;
    }
};

int main() {
    cout << "x ,y : ";
    double x, y;
    cin >> x >> y;
    cout << endl;
    Character character(x, y); 

    double y2;
    double x2;
    while (true) {
        string oprtr;
        cout << "Operator: ";

        cin >> oprtr;
        cout << endl;
        if (oprtr == "+") {
            cout << "Add: " << character.add() << endl;
            x2 = character.add();
        }
        else if (oprtr == "-") {
            cout << "Subtract: " << character.subtract() << endl;
            x2 = character.subtract();
        }
        else if (oprtr == "%") {
            cout << "Multiply: " << character.multiply() << endl;
            x2 = character.multiply();
        }
        else if (oprtr == "*") {
            while (true) {
                if (y != 0) {
                    cout << "Divide: " << character.divide() << endl;

                    x2 = character.divide();
                    break;
                }
                else if (y==0)  {
                    
                    cout << "y : " << y << endl;
                    cin >> y;

                }

            }
        }
        else if (oprtr == "AC") { x = 0; y = 0; x2 = 0; y2 = 0; }
        
        else {
            cout << "Error or terminate" << endl;
            break;
        }

        cout << endl;

        cout << "next number : ";
       
        while (true) {
            cin >> y2;
            
            cout << endl;
            if (y2==0) {
                cout << "could not be divided by 0" << endl;
                continue;
            }
            character.setx(x2);
            character.sety(y2);
            x = x2;
        }
    }
    return 0;
}