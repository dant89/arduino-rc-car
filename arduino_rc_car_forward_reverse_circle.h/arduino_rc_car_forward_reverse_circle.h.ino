#include <Servo.h>

Servo steering;
Servo throttle;

int accelerationSpeed = 89; // Slowest accelerate speed 90
int reverseSpeed = 104;     // Slowest reverse speed 102
int neutral = 91;
int brake = 180;

int noTurn = 90;
int leftTurn = 0;
int rightTurn = 180;

bool debug = true;

void setup()  {
    if (debug) {
        Serial.begin(9600);
    }
    throttle.attach(9);
    steering.attach(10);
}

void Logger(String message) {
    if (debug) {
        Serial.println(message);
    }
}

void MoveBackward() {
    Logger("Move: reverse");
    throttle.write(reverseSpeed);
}

void MoveForward() {
    Logger("Move: accelerate");
    throttle.write(accelerationSpeed);
}

void Brake() {
    Logger("Move: brake");
    throttle.write(brake);
}

void Stop() {
    Logger("Move: stop");
    throttle.write(neutral);
}

void SteerLeft() {
    Logger("Steer: left");
    steering.write(leftTurn);
}

void SteerStraight() {
    Logger("Steer: staight");
    steering.write(noTurn);
}

void SteerRight() {
    Logger("Steer: right");
    steering.write(rightTurn);
}

void loop() {
    SteerLeft();
    MoveForward();
    delay(2000);

    Brake();
    delay(250);

    Stop();
    delay(2000);

    SteerRight();
    MoveBackward();
    delay(2000);

    Stop();
    delay(2000);
}