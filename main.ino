const int readingPin = 2;
const int debounce = 50;
const int dashThreshold = 300;

void setup(){
    Serial.begin(9600);
    Serial.println("Code is working and running!");
    pinMode(readingPin, INPUT);
}

void loop(){
    pinMode(readingPin, INPUT);

    if(digitalRead(readingPin) == HIGH){
        unsigned long pressStartTime = millis();

        while(digitalRead(readingPin) == HIGH){
            // nothing
        }

        unsigned long pressTime = millis() - pressStartTime;

        if(pressTime >= debounce){
            if(pressTime >= dashThreshold){
                Serial.print("-");
            }
            else{
                Serial.print(".");
            }
        }
            delay(debounce);
    }
}
