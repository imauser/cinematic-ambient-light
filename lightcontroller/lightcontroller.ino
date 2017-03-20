struct LED {
  int redpin;
  int greenpin;
  int bluepin;
};

byte serial_buffer[3];

LED led1 = {3,4,2}; 


void activateLed(struct LED* led) {
  pinMode(led->redpin, OUTPUT);
  pinMode(led->bluepin, OUTPUT);
  pinMode(led->greenpin, OUTPUT);
}

void setup()
{
 activateLed(&led1);
 Serial.begin(9600);
}

bool read_serial_buffer(int buffer_size, byte* buffer)
{
  if (Serial.available() < buffer_size) {
    return false;
  }
 
    // Read buffer
    for (int i = 0; i < buffer_size; i++)
    {
      buffer[i] = Serial.read();
      delay(10); 
    }

}

void empty_serial() 
{

    while (Serial.available()) 
    {
      Serial.read();
    }
    return true;
}

void loop()
{
  if (read_serial_buffer(3, serial_buffer))
    empty_serial();
 
   analogWrite(led1.redpin, serial_buffer[0]); 
   analogWrite(led1.greenpin, serial_buffer[1]);

   analogWrite(led1.bluepin, serial_buffer[2]);
}

