struct LED {
  int bluepin;
  int redpin;
  int greenpin;





};

LED led1 = {2,3,4}; 


void activateLed(struct LED* led) {
  pinMode(led->redpin, OUTPUT);
    pinMode(led->bluepin, OUTPUT);
      pinMode(led->greenpin, OUTPUT);

}

void setup()
{
 activateLed(&led1);
}

void loop()
{
   analogWrite(led1.greenpin, 0);
   analogWrite(led1.redpin, 0);
   analogWrite(led1.bluepin, 200);
}

