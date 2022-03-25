#include <EEPROM.h>

byte port_b, port_d; 
byte status_b = 0x00;
byte status_d = 0x00;
byte store_eeprom = 0x00;

boolean bo_led = true;

int int_true = 25;
int int_false = 25;
int int_time_on = 25;
int int_time_off = 25;


void setup()
{
  pinMode(2, INPUT_PULLUP);   // sets the pin as input
  pinMode(4, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);
  pinMode(3, OUTPUT);  // sets the pin as output
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
  Serial.setTimeout(10000);
  Serial.println("Triple Platform/ SW 1.0/ Elektronik Werkstatt Biologie/ J. Schmid");
  Serial.println("Value for time_on");
  int_time_on = Serial.parseInt();
  Serial.print("Value for time_on is ");
  Serial.println(int_time_on);
  
  if (int_time_on > 0){
    store_eeprom = int_time_on & 0x00FF;
    EEPROM.write(0,store_eeprom);
    int_time_on = int_time_on >> 8;
    store_eeprom = int_time_on & 0x00FF;
    EEPROM.write(1,store_eeprom);
    Serial.println("Value saved in EEPROM");
    }
  else{
    Serial.println("No value saved");
  }

      
  Serial.println("Value for time_off");
  int_time_off = Serial.parseInt();
  Serial.print("Value for time_off is ");
  Serial.println(int_time_off);
  
  if (int_time_off > 0){
    store_eeprom = 0x00;
    store_eeprom = int_time_off & 0x00FF;
    EEPROM.write(2,store_eeprom);
    int_time_off = int_time_off >> 8;
    store_eeprom = int_time_off & 0x00FF;
    EEPROM.write(3,store_eeprom);
    Serial.println("Value saved in EEPROM");
    }
  else{
    Serial.println("No value saved");
  }  
  
  store_eeprom = 0x00;
  int_true = EEPROM.read(1);
  int_true = int_true << 8;
  store_eeprom = EEPROM.read(0);
  int_true = int_true | store_eeprom;
  
  store_eeprom = 0x00;
  int_false = EEPROM.read(3);
  int_false = int_false << 8;
  store_eeprom = EEPROM.read(2);
  int_false = int_false | store_eeprom;
  
  Serial.print("System Value for time_on is ");
  Serial.println(int_true);
  Serial.print("System Value for time_off is ");
  Serial.println(int_false);
  
  Serial.println("Running");
  Serial.end();
  
}

void loop()
{
  port_b = PINB;
  port_d = PIND;
  
  if (bo_led == true){
    bo_led = false;
    delay(int_true);
    status_d = status_d & 0x97;
    status_b = status_b & 0xF1;
    }
  else{
    bo_led = true;
    delay(int_false);
    status_d = status_d | 0x68;
    status_b = status_b | 0x0E;
    }
    
  if ((port_d & 0x04) == false){
    status_d = status_d & 0xF7;
    }
  else{
    }
    
  if ((port_d & 0x10) == false){
    status_d = status_d & 0xDF;
    }
  else{
    }
  
    if ((port_d & 0x80) == false){
    status_d = status_d & 0xBF;
    }
  else{
    }
    
    if ((port_b & 0x01) == false){
    status_b = status_b & 0xFD;
    }
  else{
    }
    
    if ((port_b & 0x10) == false){
    status_b = status_b & 0xFB;
    }
  else{
    }
    
    if ((port_b & 0x20) == false){
    status_b = status_b & 0xF7;
    }
  else{
    }
  
  PORTD = status_d;
  PORTB = status_b;

}
