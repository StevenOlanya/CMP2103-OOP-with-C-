// 
// Calculation of electrical parameters: Device -> Load -> Motor
#include <iostream>
using namespace std;

//  Level 1 (base class) 
class Device {
public:
    double voltage;                              // data member
    void setVoltage(double v) { voltage = v; }   // member function
    void showVoltage() { cout << "Supply voltage = " << voltage << " V" << endl; }
};

//  Level 2: inherits from Device 
class Load : public Device {
public:
    double resistance;                           // data member
    void setResistance(double r) { resistance = r; }
    double current() { return voltage / resistance; }   // uses inherited 'voltage'
};

//  Level 3: inherits from Load (and so from Device) 
class Motor : public Load {
public:
    double efficiency;                           // data member
    void setEfficiency(double e) { efficiency = e; }
    double outputPower() { return efficiency * voltage * current(); }  // uses both parents
};

int main() {
    // Object of Level 1
    cout << "---- Device object---- " << endl;
    Device d;
    d.setVoltage(230);                           // local member
    d.showVoltage();

    // Object of Level 2: uses an inherited member and its own members
    cout << "\n--- Load object ---" << endl;
    Load l;
    l.setVoltage(230);                           // INHERITED from Device
    l.setResistance(46);                         // LOCAL to Load
    l.showVoltage();                             // INHERITED from Device
    cout << "Current = " << l.voltage << " / " << l.resistance
         << " = " << l.current() << " A" << endl;        // LOCAL function

    // Object of Level 3: uses members from all three levels
    cout << "\n--- Motor object ---" << endl;
    Motor m;
    m.setVoltage(230);                           // INHERITED from Device (2 levels up)
    m.setResistance(46);                         // INHERITED from Load
    m.setEfficiency(0.85);                       // LOCAL to Motor
    m.showVoltage();                             // INHERITED from Device
    cout << "Current = " << m.current() << " A" << endl;           // INHERITED from Load
    cout << "Input power = " << m.voltage << " x " << m.current()
         << " = " << m.voltage * m.current() << " W" << endl;
    cout << "Output power = " << m.efficiency << " x " << m.voltage * m.current()
         << " = " << m.outputPower() << " W" << endl;      // LOCAL function
    return 0;
}
