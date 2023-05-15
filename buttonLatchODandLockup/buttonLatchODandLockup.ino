int ODState=0;
int LockupState=0;

int ODButton=2;
int LockupButton=3;

int ODRelay=8;
int LockupRelay=9;

int ODButtonOld=1;
int ODButtonNew;

int LockupButtonOld=1;
int LockupButtonNew;

int ButtonReadDelay=100;

int Listening=0;

void setup() {

  Serial.begin(9600);

  pinMode(ODButton, INPUT);
  pinMode(LockupButton, INPUT);

  pinMode(ODRelay, OUTPUT);
  pinMode(LockupRelay, OUTPUT);

}

void loop() {

  if (Listening==0){
    Serial.println("Now Listening...");
    Listening=1;
  }
  
  ODButtonNew=digitalRead(ODButton);
  LockupButtonNew=digitalRead(LockupButton);

  if (ODButtonOld==0 && ODButtonNew==1){
    if (ODState==0){
      digitalWrite(ODRelay, HIGH);
      ODState=1;
      Serial.println("Activate OD");
    }
    else{
      digitalWrite(ODRelay, LOW);
      ODState=0;
      Serial.println("Deactiviate OD");
    }
  }

  if (LockupButtonOld==0 && LockupButtonNew==1){
    if (LockupState==0){
      digitalWrite(LockupRelay, HIGH);
      LockupState=1;
      Serial.println("Activate Lockup");
    }
    else {
      digitalWrite(LockupRelay, LOW);
      LockupState=0;
      Serial.println("Deactivate Lockup");
    }
  }
  ODButtonOld=ODButtonNew;
  LockupButtonOld=LockupButtonNew;

  delay(ButtonReadDelay);

}
