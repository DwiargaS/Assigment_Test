class bms{
  private:
    int adc;
  public:
    float full=4.25;
    float empty=2.5;
    float volt;
    float percentage;

  void setFullVoltage(float value){
    full = value; 
  }
  
  void setEmptyVoltage(float value){
    empty = value; 
  }

  int readADCRaw(){
    adc = analogRead(A0);
    Serial.print("ADC Value :");
    Serial.println(adc);
  }

  float getBatteryVoltage(){
    volt=adc*5.0/1024;
    Serial.print("Voltage Value :");
    Serial.println(volt);
  }

  float getBatteryPercentage(){
    percentage=(volt-empty)/(full-empty)*100;
    Serial.print("Battery Percentage :");
    Serial.print(percentage);
    Serial.println("%");
  }

  void isBatteryLow(){
    if (percentage<30){
      Serial.println("Warning: Low Battery !");
    }
  }
};

void setup() {
  Serial.begin(115200);
  pinMode(A0, INPUT);

}

void loop() {
  bms bms1;
  bms1.readADCRaw();
  bms1.getBatteryVoltage();
  bms1.getBatteryPercentage();
  bms1.isBatteryLow();
  Serial.print('\n');
  delay(1000);
}
