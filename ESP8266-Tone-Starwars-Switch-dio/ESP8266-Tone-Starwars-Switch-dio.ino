/*
  Plays Starwars Imperial March using Passive Buzzer

  circuit:
  - Passiv Buzzer on GPIO4 digital pin 2
  - led on GPIO5 digital pin 1

  original code by: Steven Nunez
  https://gist.github.com/StevenNunez/6786124

  modified 12 Sept 2018
  by Diobert Dioneo
*/

// Solution proposed by @TylerLewis:
#define ARRAY_SIZE(x) sizeof(x)/sizeof(x[0])

// Template based solution:
template<typename T, size_t N> size_t ArraySize(T(&)[N]){ return N; }

int speakerPin = 4; //THIS IS GPIO4
int ledPin = 5; //THIS IS GPIO5
int buttonPin = 12; //THIS IS GPIO12
String notes[] = {"G4","G4", "G4", "D#4/Eb4", "A#4/Bb4", "G4", "D#4/Eb4","A#4/Bb4", "G4", "D5", "D5", "D5", "D#5/Eb5", "A#4/Bb4", "F#4/Gb4", "D#4/Eb4","A#4/Bb4", "G4", "G5","G4","G4","G5","F#5/Gb5", "F5","E5","D#5/Eb5","E5", "rest", "G4", "rest","C#5/Db5","C5","B4","A#4/Bb4","A4","A#4/Bb4", "rest", "D#4/Eb4", "rest", "F#4/Gb4", "D#4/Eb4","A#4/Bb4", "G4" ,"D#4/Eb4","A#4/Bb4", "G4"}; 
int beats[] = {8, 8, 8, 6, 2, 8, 6 , 2 ,16 ,8, 8, 8, 6, 2, 8, 6, 2, 16, 8, 6, 2, 8, 6, 2, 2, 2, 2, 6, 2, 2, 8, 6, 2, 2, 2, 2, 6, 2, 2, 9, 6, 2, 8, 6, 2, 16};
int tempo = 60;
 
void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);      
  }
}
  
void playNote(String note, int duration) {
  String noteNames[] = { "D#4/Eb4", "E4", "F4", "F#4/Gb4", "G4", "G#4/Ab4", "A4", "A#4/Bb4", "B4", "C5", "C#5/Db5", "D5", "D#5/Eb5", "E5", "F5", "F#5/Gb5", "G5", "G#5/Ab5", "A5", "A#5/Bb5", "B5", "C6", "C#6/Db6", "D6", "D#6/Eb6", "E6", "F6", "F#6/Gb6", "G6" };
  int tones[] = { 1607, 1516, 1431, 1351, 1275, 1203, 1136, 1072, 1012, 955, 901, 851, 803, 758, 715, 675, 637, 601, 568, 536, 506, 477, 450, 425, 401, 379, 357, 337, 318 };
  for (int i = 0; i < 29; i++) {
    if (noteNames[i] == note) {
      playTone(tones[i], duration);
    }
  }
}

void triggerPlay(){
  Serial.println("start playing..");
  //delay(2000);
  for (int i = 0; i < ArraySize(notes); i++) {
      if (notes[i] == "rest") {
        Serial.println("rest...");
        Serial.println("");
        digitalWrite(LED_BUILTIN, HIGH);
        delay(beats[i] * tempo);
        digitalWrite(LED_BUILTIN, LOW);
      } else {
        Serial.print(i);
        Serial.println(" notes="+notes[i]+", beats="+beats[i]);
        digitalWrite(LED_BUILTIN, HIGH);
        playNote(notes[i], beats[i] * tempo);
        digitalWrite(LED_BUILTIN, LOW);
      }
      delay(tempo / 2);
      digitalWrite(LED_BUILTIN, LOW);
  }
  Serial.println("the end.");
}

void countDown(int count, int seconds){
  while(count != 0){
    Serial.println(count);
    digitalWrite(ledPin, HIGH);
    delay(seconds/2);
    digitalWrite(ledPin, LOW);
    delay(seconds/2);
    count = count -1;
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(speakerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  //Serial.println("pause..10 seconds");
  //delay(10000);
  Serial.println("looping for input...");
  if(digitalRead(buttonPin)==LOW){
    Serial.println("button pressed.");
    countDown(5,1000);
    digitalWrite(ledPin, HIGH);
    triggerPlay();
    digitalWrite(ledPin, LOW);
  }
}
