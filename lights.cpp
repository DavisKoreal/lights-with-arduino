
//pinouts used in the project

int detector_input = 1;
int relay_output = 12;       

//running values during initialisation

void setup() {
    pinMode(detector_input, INPUT);   //setting the detector pin to input
    pinMode(relay_output, OUTPUT);    //setting the relay pin as the output
}

void loop() {
    if (motion_detected()) {
        lights_on();
    }
    else {
        lights_off();
    }
}

// Return true if motion is detected.. 
bool motion_detected() {
    int status = digitalRead(detector_input);
    if (status == HIGH) {
        return true;
    }
    else {
        return false;
    }
}

void lights_on() {
    // check if lights were on

    if (digitalRead(relay_output) == LOW) {
        digitalWrite(relay_output, HIGH);
        // Turn on lights for 5 minutes 
         // Change this accordingly
        delay(50000);
        lights_off();
    }
    else {
        // Do nothing
    }


}

void lights_off() {
    digitalWrite(relay_output, LOW);
}