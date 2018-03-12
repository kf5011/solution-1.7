#include <mbed.h>

enum { Red, Green, Blue, SRed, SGreen, SBlue};
DigitalOut LED[] = {
  DigitalOut(PTB22,1),
  DigitalOut(PTE26,1),
  DigitalOut(PTC21,1),
  DigitalOut(D5,1),
  DigitalOut(D9,1),
  DigitalOut(D8,1),

};

void LEDon(int n) {
  LED[n].write(0);
}
void LEDoff(int n) {
  LED[n].write(1);
}

void flashfor(int ms){
    LEDon(Red);
    wait_ms(ms/2);
    LEDoff(Red);
    wait_ms(ms/2);
}
int main() {
    int tick;
    for(tick=1 ; tick<=10 ; tick++){
        int flash;
        for(flash=0 ; flash<tick ; flash++) flashfor(1000/tick);
    }
    LEDon(Red);
    wait(1);
    LEDoff(Red);

    LEDon(SRed);
    LEDon(SGreen);
    LEDon(SBlue);
    wait_ms(10);
    LEDoff(SRed);
    LEDoff(SGreen);
    LEDoff(SBlue);
}
