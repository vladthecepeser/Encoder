#include "AS5600.h"


//  Uncomment the line according to your sensor type

//AS5600L ASL;   //  use default Wire

AS5600 ASL(&Wire);   //  use default Wire
AS5600 ASL1(&Wire1);

//uint8_t dummy[4000];


void setup()

{

  //while(!Serial);


  Serial.begin(115200);

  Serial.println();

  Serial.println(__FILE__);

  Serial.print("AS5600_LIB_VERSION: ");

  Serial.println(AS5600_LIB_VERSION);

  Serial.println();


  Wire.begin(18, 19);
  Wire1.begin(21, 22);


  ASL.begin(4);  //  set direction pin.
  ASL1.begin(4);

  ASL.setDirection(AS5600_CLOCK_WISE);  //  default, just be explicit.
  ASL1.setDirection(AS5600_CLOCK_WISE);

  int b = ASL.isConnected();
  int c = ASL1.isConnected();

  Serial.print("Connect: ");

  Serial.print(b);
  Serial.print("\t");
  Serial.println(c);


  Serial.print("ADDR: ");
  Serial.println(ASL.getAddress());

  Serial.print("ADDR1: ");
  Serial.println(ASL1.getAddress());


  //ASL.setAddress(0x38);
}




void loop()

{

  //  Serial.print(millis());

  //  Serial.print("\t");

  //Serial.print("printed");

  Serial.print(ASL.readAngle());
  Serial.print("\t");
  Serial.print(ASL1.readAngle());
  Serial.print("\t");
  Serial.print(ASL.rawAngle() * AS5600_RAW_TO_DEGREES);
  Serial.print("\t");
  Serial.println(ASL1.rawAngle() * AS5600_RAW_TO_DEGREES);

  delay(250);

}