//  Polymorphism
//  Element -> Resistor, Inductor, Capacitor
#include <iostream>
using namespace std;

const double PI = 3.14;
const double f = 50;                             // frequency in Hz

// ---------- Parent class with a VIRTUAL function ----------
class Element {
public:
    virtual void impedance() {
        cout << "Generic element: no formula" << endl;
    }
};

//  Derived class 1: overrides the virtual function 
class Resistor : public Element {
public:
    void impedance() override {
        cout << "Resistor: Z = R = 100 ohm" << endl;
    }
};

//  Derived class 2: overrides the virtual function 
class Inductor : public Element {
public:
    void impedance() override {
        cout << "Inductor: XL = 2 x pi x f x L = 2 x " << PI << " x " << f
             << " x 0.5 = " << 2 * PI * f * 0.5 << " ohm" << endl;
    }
};

//  Derived class 3: overrides the virtual function 
class Capacitor : public Element {
public:
    void impedance() override {
        cout << "Capacitor: XC = 1/(2 x pi x f x C) = 1/(2 x " << PI << " x " << f
             << " x 0.0001) = " << 1 / (2 * PI * f * 0.0001) << " ohm" << endl;
    }
};

// Calls the overridden function through a BASE-CLASS REFERENCE
void show(Element& e) {
    e.impedance();
}

int main() {
    // Create the objects
    Resistor  r;
    Inductor  l;
    Capacitor c;

    // Runtime polymorphism through a BASE-CLASS POINTER
    cout << "--- Using a base-class pointer ---" << endl;
    Element* p;
    p = &r;  p->impedance();                     // same call ...
    p = &l;  p->impedance();                     //  different behaviour
    p = &c;  p->impedance();                     // depends on the object

    // Runtime polymorphism through a BASE-CLASS REFERENCE
    cout << "\n--- Using a base-class reference ---" << endl;
    show(r);
    show(l);
    show(c);
    return 0;
}
