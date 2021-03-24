//test commit

//hello me changing something

//second test thing

volatile unsigned char* portb = 0x25;
volatile unsigned char* ddrb = 0x24;
volatile unsigned char* pinb = 0x23;

void setup() {
  *ddrb |= 0x80; //set to output
  
}

void loop() {
  turnMotorOn();
  delay(1000);
  turnMotorOff();
  delay(3000);
}

void turnMotorOn()//we dedicate pinb7 for the motor function
{
  *portb |= 0x01 << (unsigned char)7;
}

void turnMotorOff()//dedicated pinb7 (digital pin 13)
{
    if(isMotorOn == false)
    {
        return;
    }
    else
        *portb &= 0x01;
}

bool isMotorOn()
{
  if(*pinb & 0x80)
  {
    return true;
  }
  else
    return false;
}
