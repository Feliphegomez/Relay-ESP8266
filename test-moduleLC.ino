/*
 * -------------------------
 *  FelipheGomez - Colombia
 * -------------------------
 */

byte relON[] = {0xA0, 0x01, 0x01, 0xA2};  //Hex command to send to serial for open relay
byte relOFF[] = {0xA0, 0x01, 0x00, 0xA1}; //Hex command to send to serial for close relay

int ledState = false;
unsigned long previousMillis = 0;
const long interval = 2000; //  2 seconds

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize serial:
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop()
{
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;   
    if (ledState == true) {
      Serial.write(relON, sizeof(relON));     // turns the relay ON
      ledState = false;
    } else {
      Serial.write(relOFF, sizeof(relOFF));   // turns the relay OFF
      ledState = true;
    }    
  }
}
