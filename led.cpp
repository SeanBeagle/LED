#include <iostream>
#include <string>


// HEADER
class LED {
  public:
    enum Color {RED, YELLOW, GREEN};
    enum Mode {OFF, SOLID, BLINK, ALTERNATE};
    enum Rate {SLOW, MEDIUM, FAST};
    // constructors
    LED();
    LED(Color color, Mode mode);
    // methods
    void Blink(Color color, Rate rate);
    void Alternate(Color color1, Color color2);
    void Solid(Color color);
    void Off();
    std::string ToString();
    
  private:
    Color _color1;
    Color _color2;
    Mode _mode;
    Rate _rate;
    // methods
    void SetColor1(Color color);
    void SetColor2(Color color);
    void SetMode(Mode mode);
    void SetRate(Rate rate);
};


// MAIN
int main() {
   LED power_led = LED();
   power_led.Solid(LED::GREEN);
   power_led.Solid(LED::RED);
   power_led.Blink(LED::GREEN, LED::MEDIUM);
   power_led.Off();
   power_led.Alternate(LED::RED, LED::YELLOW);
   
   return 0;
}


/** Default constructor for LED */
LED::LED() {
    SetColor1(RED);
    SetMode(OFF);
}

/** Construct LED with color and mode */
LED::LED(Color color, Mode mode) {
    SetColor1(color);
    SetMode(mode);
}

/** Set color1 of LED to kRed, kYellow, or kGreen */
void LED::SetColor1(Color color) {
    if (_color1 != color) {
        _color1 = color;
        std::cout << "Set color1 to: " + kColors[_color1] << std::endl;
    }
}

/** Set color2 of LED */
void LED::SetColor2(Color color) {
    if (_color2 != color) {
        _color2 = color;
        std::cout << "Set color2 to: " + kColors[_color2] << std::endl;
    }
}

/** Set mode of LED */
void LED::SetMode(Mode mode) {
    if (_mode != mode) {
        _mode = mode;
        std::cout << "Set mode to: " + kModes[_mode] << std::endl;
    }
}

/** Set blink rate of LED */
void LED::SetRate(Rate rate) {
    if (_rate != rate) {
        _rate = rate;
        std::cout << "Set blink rate to: " + Rates[_rate] << std::endl;
    }
}

void LED::Solid(Color color) {
    SetMode(SOLID);
    SetColor1(color);
}

void LED::Blink(Color color, Rate rate) {
    SetMode(BLINK);
    SetRate(rate);
    SetColor1(color);
}

void LED::Alternate(Color color1, Color color2) {
    SetMode(ALTERNATE);
    SetColor1(color1);
    SetColor2(color2);
}

void LED::Off() {
    SetMode(OFF);
}

/** Return representation of object as string */
std::string LED::ToString() {
    return "LED<color=" + kColors[_color1] + ", mode=" + kModes[_mode] + ">";
}

