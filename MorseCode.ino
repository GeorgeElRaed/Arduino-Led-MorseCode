
int pin =  13;
char str[500]="a.-b-...c-.-.d-..e.f..-.g--.h....i..j.---k-.-l.-..m--n-.o---p.--.q--.-r.-.s...t-u..-v...-w.--x-..-y-.--z--..1.----2..---3...--4....-5.....6-....7--...8---..9----.0-----",
text[100];

void setup() {
pinMode(pin,OUTPUT);
Serial.begin(9600);
}

void longBeam(){
  digitalWrite(pin,HIGH);
  delay(500);
  digitalWrite(pin,LOW);  
  delay(100);
}

void shortBeam(){
  digitalWrite(pin,HIGH);
  delay(250);
  digitalWrite(pin,LOW);
  delay(100);
}


void MorseCode(){
  for(int j=0;text[j]!='\0';j++){
  int i=0;
   while(str[i]!='\0'){
      if(str[i]==text[j]){
       i++;
       while(str[i]=='.' || str[i]=='-'){
        if(str[i]=='.') shortBeam();
        if(str[i]=='-') longBeam();
        i++;
       }
       break;
      }
    i++;
    }
    delay(250);
  }
}


void loop() {
  if(Serial.available() > 0){
    Serial.readBytesUntil('\0',text,100);
    MorseCode();
    for(int i =0 ;i<strlen(text);i++)text[i] = ' ';
  }
  delay(1000);
}

