//fan pointers
volatile unsigned char* portb = 0x25;
volatile unsigned char* ddrb = 0x24;
volatile unsigned char* pinb = 0x23;

//motor pointers

void setup() {
  *ddrb |= 0x80; //set to output
  
}

void loop() {
  turnMotorOn();
  delay(1000);
  turnMotorOff();
  delay(3000);
}

void turnMotorOn()//pb7 fan
{
  *portb |= 0x01 << (unsigned char)7;
}

void turnMotorOff()//pb7 fan
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
