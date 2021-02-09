#include <iostream>
#include <string>


// HEADER
enum Color { kRed, kYellow, kGreen };
const std::string kColors[] { "red", "yellow", "green" };
enum Mode { kOff, kSolid, kBlink, kAlternate };
const std::string kModes[] { "off", "blink", "alternate" };

class LED {
  private:
    // Fields
    int _color;
    int _mode;
    // Methods
    void SetColor(Color color);
    void SetMode(Mode mode);
    
  public:
    // Constructors
    LED();
    LED(Color color, Mode mode);
    // Methods
    void Blink(Color color);
    void Solid(Color color);
    void Off();
    std::string ToString();
    
};


// MAIN
int main() {
   LED power_led = LED();
   std::cout << power_led.ToString() << std::endl;
   power_led.Solid(kGreen);
   std::cout << power_led.ToString() << std::endl;
   power_led.Solid(kRed);
   std::cout << power_led.ToString() << std::endl;
   power_led.Off();
   std::cout << power_led.ToString() << std::endl;
   
   return 0;
}


// DEFINITIONS

/** Default constructor for LED */
LED::LED() {
    SetColor(kRed);
    SetMode(kOff);
}

/** Construct LED with color and mode */
LED::LED(Color color, Mode mode) {
    SetColor(color);
    SetMode(mode);
}

/** Set color of LED to kRed, kYellow, or kGreen */
void LED::SetColor(Color color) {
    if (_color != color) {
        _color = color;
        std::cout << "Set color to: " + kColors[_color] << std::endl;
    }
}

/** Set mode of LED to kOff, kSolid, or kAlternate */
void LED::SetMode(Mode mode) {
    if (_mode != mode) {
        _mode = mode;
        std::cout << "Set mode to: " + kModes[_mode] << std::endl;
    }
}

void LED::Solid(Color color) {
    SetMode(kSolid);
    SetColor(color);
}

void LED::Blink(Color color) {
    SetMode(kBlink);
    SetColor(color);
}

void LED::Off() {
    SetMode(kOff);
}

/** Return representation of object as string */
std::string LED::ToString() {
    return "LED<color=" + kColors[_color] + ", mode=" + kModes[_mode] + ">";
}

