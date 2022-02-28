

![Board](./media/tmpC.png)


```c
float tmpC = 0;
void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop()
{
  Serial.print("tmpC: ");
  int tmpC = celcius();
  Serial.println(tmpC);
  delay(1000);
}

int celcius()
{
  int reading = analogRead(A0); // get the reading of the vout of tmp sensor

  // the analog-in pins A0 to A5 can interpret voltages between 0 and 5V,
  // they then translate that voltage to a value between 0 and 1023
  // for the Arduino sketch to use
  float volts = reading * 5.0;  // multiplication is to account for the 5V
  volts /= 1024.0;              // to account for top voltage

  tmpC = (volts - 0.50) * 100;  // converting from 10 mv per degree wit 500 mV offset
                                // to degrees ((volatge - 500mV) times 100)
  return tmpC;                  // return the current celcius
}
```