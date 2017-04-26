//v.1.0.1 of a swarming bots project
//April 25, 2017
//this sketch is for a quick prototype

#include <IRremote.h> // Include the IRremote library

/* Setup constants for SparkFun's IR Remote: we will use these to begin 
programming behaviors, and since there are 9 variables, that might suffice 
for the needs of individual ANTs */
#define NUM_BUTTONS 9 // The remote has 9 buttons
/* Define the IR remote button codes. As hexidecimel each one 
   should actually have 0x10EF in front of it.*/
const uint16_t BUTTON_POWER = 0xD827; // i.e. 0x10EFD827
const uint16_t BUTTON_A = 0xF807;  //0x10EFF807
const uint16_t BUTTON_B = 0x7887;  //0x10EF0x7887
const uint16_t BUTTON_C = 0x58A7;  //0x10EF58A7
const uint16_t BUTTON_UP = 0xA05F;  //0x10EFA05F
const uint16_t BUTTON_DOWN = 0x00FF; //0x10EF00FF
const uint16_t BUTTON_LEFT = 0x10EF;  //0x10EF10EF
const uint16_t BUTTON_RIGHT = 0x807F;  //0x10EF807F
const uint16_t BUTTON_CIRCLE = 0x20DF;  //0x10EF20DF

int RECV_PIN_R = 11; //right IR receiver is connected to this pin
int RECV_PIN_L = 10; //left IR receiveer is here 
// maybe write better code here to reduce duplicates for all right and left items
// this is clunky... 
IRrecv irrecv(RECV_PIN_L);  //Initialize a irrecv object from IRremote library
IRrecv irrecv(RECV_PIN_R);
decode_results results; // This will store our IR received codes
uint16_t lastCode = 0; // This keeps track of the last code RX'd

const int RED = 4;
const int GREEN = 7;
const int BLUE = 8;

//motors, let's keep these on PWM pins, since 10 and 11 are for the receivers
// 3, 5, 6, 9 
//const int motor_left = 3;
//const int motor_right = 5;
//
//
//possibly also add hardware:
//inputs ==> push button, extra IR, light sensor, or microphone... 
//outputs ==> OLED screen, speaker/buzzer, servo arm, more LEDs...   

void setup() {
  Serial.begin(9600); // Use serial to debug. 
  irrecv.enableIRIn(); // Start the receiver
//
}

void loop() {

if (irrecv.decode(&results)) 
  {
    /* read the RX'd IR into a 16-bit variable: */
    uint16_t resultCode = (results.value & 0xFFFF);

    /* The remote will continue to spit out 0xFFFFFFFF if a 
     button is held down. If we get 0xFFFFFFF, let's just
     assume the previously pressed button is being held down */
    if (resultCode == 0xFFFF)
      resultCode = lastCode;
    else
      lastCode = resultCode;

    // This switch statement checks the received IR code against
    // all of the known codes. Each button press produces a 
    // serial output, and has an effect on the LED output.
    switch (resultCode)
    {
      case BUTTON_POWER:
        Serial.println("Power");
        if (ledEnable) ledEnable = 0;
        else ledEnable = 1; // Flip ledEnable
        break;
      case BUTTON_A:
        Serial.println("A");
        activeChannel = RED;
        break;
      case BUTTON_B:
        Serial.println("B");
        activeChannel = GREEN;
        break;
      case BUTTON_C:
        Serial.println("C");
        activeChannel = BLUE;
        break;
      case BUTTON_UP:
        Serial.println("Up");
        rgbValues[activeChannel]++; // Increment brightness
        break;
      case BUTTON_DOWN:
        Serial.println("Down");
        rgbValues[activeChannel]--; // Decrement brightness
        break;
      case BUTTON_LEFT:
        Serial.println("Left");
        rgbValues[activeChannel] = 0; // Min brightness (off)
        break;
      case BUTTON_RIGHT:
        Serial.println("Right");
        rgbValues[activeChannel] =  255; // Max brightness
        break;
      case BUTTON_CIRCLE:
        Serial.println("Circle");
        rgbValues[activeChannel] = 127; // Medium brightness
        break;
      default:
        Serial.print("Unrecognized code received: 0x");
        Serial.println(results.value, HEX);
        break;        
    }    
    irrecv.resume(); // Receive the next value
}

/*there will be a section for sending code here
something like this:
void sendNEC(unsigned long data, int nbits);

or, maybe we could prototype with something less specific:
void sendCode()
{
  if (codeType == NEC) 
  {
    irsend.sendNEC(codeValue, irLen);
    Serial.print("Sent NEC ");
    Serial.println(codeValue, HEX);
  } 
  */
