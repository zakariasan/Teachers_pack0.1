
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Adresse I2C 0x27 (du LCD DIYables), 16 colonnes et 2 lignes
int trigPin = A0; // Broche TRIG
int echoPin = A1; // Broche ECHO
float duration_us, distance_cm;

void setup() {
    lcd.init(); // Initialisation de l'écran LCD
    lcd.backlight(); // Activation du rétroéclairage
    pinMode(trigPin, OUTPUT); // Configuration de la broche TRIG en mode sortie
    pinMode(echoPin, INPUT); // Configuration de la broche ECHO en mode entrée
      Serial.begin(9600);
      lcd.print("hello ===>");

}

void loop() {
    // Génère une impulsion de 10 microsecondes sur la broche TRIG
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Mesure la durée de l'impulsion depuis la broche ECHO
    duration_us = pulseIn(echoPin, HIGH);

    // Calcule la distance en centimètres
    distance_cm = duration_us / 58.0;

    // Affiche la distance sur l'écran LCD
    lcd.clear();
    lcd.setCursor(0, 0); // Début de l'affichage à la première ligne
    lcd.print("OMPP--2BAC ");
        lcd.setCursor(0, 1); // Début de l'affichage à la première ligne
        lcd.print("distance:");
    lcd.print(distance_cm);


      Serial.print("Distance : ");
  Serial.print(distance_cm);  // Use println for a new line after the value
    
      Serial.println("cm");
lcd.print("cm");
    delay(500); // Attente de 500 ms
}