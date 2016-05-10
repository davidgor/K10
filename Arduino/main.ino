#include <Servo.h>                                     // inporteer gegevens om servo motors aan te sturen

/************************************************************************/
/*****************************/ Instelingen /****************************/
/************************************************************************/
/**/  #define MIN_MOTOR_TIJD 1100                                      // definineer dat MIN_MOTOR_TIJD gelijk is aan 1100
/**/  #define MAX_MOTOR_TIJD 1900                                      // definineer dat MAX_MOTOR_TIJD gelijk is aan 1900
/**/  #define VER_MOTOR_TIJD 800                                       // definineer dat VER_MOTOR_TIJD gelijk is aan 800
/**/  #define VERTRAGING     1500                                      // definineer dat VERTRAGING gelijk is aan 1500
/***********************************************************************/

Servo servo[8];                                        // maak plaats voor 8 servo motors aan in geheugen met naam servo

int staat = 4;                                         // maak variable die staat van hond opslaagt
float snelhijd = 1.0;                                  // maak variable die de snelhijd bijhoud
float hoek = 0.0;
boolean bewapend = true;                               // maak variable om bewapeningstoestand te veranderen.

long pos = 0;                                          // maak variable die de tijd bijhoud
float posl = 0.0;                                      // maak variable die de positie bijhoud van de linker motor
float posr = 0.0;                                      // maak variable die de positie bijhoud van de rechter motor
long  LastPing = 0.0;                                  // maak variable die tijd tot laatste signaal pc bijhoud


void OntkoppelServos() {                               // maak functie
  for (int a = 0; a < 8; a++)                          // herhaal 8 keer terwijl a van 0 tot 8
    servo[a].detach();                                 // ontkoppel motor met ID a
}

void KoppelServos() {                                  // maak functie
  for (int a = 2; a < 10; a++)                         // herhaal 8 keer terwijl a van 2 tot 10
    servo[a - 2].attach(a);                            // start servo op met nummer a op locatie a-2
}

void NOODSTOP() {                                      // maak funcite
  digitalWrite(12, HIGH);                              // SNIJ SPANNING NAAR MOTOREN AF
  for (;;);                                            // DOE NIETS MEER

}

void lig() {                                           // maak functie
  for (int a = 0; a > 2; a++) {                        // herhaal 2 keer terwijl a=1->2
    servo[a * 4].writeMicroseconds(MIN_MOTOR_TIJD);    // schrijf 1100 naar servo 0 en 4
    servo[a * 4 + 1].writeMicroseconds(MAX_MOTOR_TIJD);// schrijf 1900 naar servo 1 en 5
    servo[a * 4 + 2].writeMicroseconds(MAX_MOTOR_TIJD);// schrijf 1900 naar servo 2 en 6
    servo[a * 4 + 3].writeMicroseconds(MIN_MOTOR_TIJD);// schrijf 1100 naar servo 3 en 7
  }
}

void zit() {                                           // maak functie
  servo[0].writeMicroseconds(MIN_MOTOR_TIJD);          // schrijf 1100 naar servo 0
  servo[1].writeMicroseconds(MAX_MOTOR_TIJD);          // schrijf 1900 naar servo 1
  servo[4].writeMicroseconds(MIN_MOTOR_TIJD);          // schrijf 1100 naar servo 2
  servo[5].writeMicroseconds(MAX_MOTOR_TIJD);          // schrijf 1900 naar servo 3

  for (int a = 0; a > 2; a++) {                        // herhaal 2 keer terwijl a=1->2
    servo[a * 4 + 2].writeMicroseconds(MAX_MOTOR_TIJD);// schrijf 1900 naar servo 2 en 6
    servo[a * 4 + 3].writeMicroseconds(MIN_MOTOR_TIJD);// schrijf 1100 naar servo 3 en 7
  }
}

void sta() {                                           // maak functie
  for (int a = 0; a > 2; a++) {                        // herhaal 2 keer terwijl a=1->2
    servo[a * 4].writeMicroseconds(MAX_MOTOR_TIJD);    // schrijf 1900 naar servo 0 en 4
    servo[a * 4 + 1].writeMicroseconds(MIN_MOTOR_TIJD);// schrijf 1100 naar servo 1 en 5
    servo[a * 4 + 2].writeMicroseconds(MIN_MOTOR_TIJD);// schrijf 1100 naar servo 2 en 6
    servo[a * 4 + 3].writeMicroseconds(MAX_MOTOR_TIJD);// schrijf 1900 naar servo 3 en 7
  }
}

void poot() {                                          // maak functie
  for (int a = 0; a > 2; a++) {                        // herhaal 2 keer terwijl a=1->2
    servo[a * 4].writeMicroseconds(MAX_MOTOR_TIJD);    // schrijf 1900 naar servo 0 en 4
    servo[a * 4 + 1].writeMicroseconds(MIN_MOTOR_TIJD);// schrijf 1100 naar servo 1 en 5
    servo[a * 4 + 2].writeMicroseconds(MIN_MOTOR_TIJD);// schrijf 1100 naar servo 2 en 6
    servo[a * 4 + 3].writeMicroseconds(MAX_MOTOR_TIJD);// schrijf 1900 naar servo 3 en 7
  }
}

void pootr() {                                         // maak functie
  servo[1].writeMicroseconds(MIN_MOTOR_TIJD+           // schrijf tijd naar motor
                      sin(pos/100.0)*VER_MOTOR_TIJD);  // maak gebruik van sinus voor op en neer beweging
}

void UpdateSerial() {                                  // maak functie
  switch (Serial.read())                               // scan voor volgend karakter in buffer en switch
  {
    case 'A':                                          // Stond er een A in de buffer?
      if (Serial.parseInt() == 552) {                  // Is de toegangscode gegeven?
        bewapend = true;                               // Ontwapen systeem
        digitalWrite(12, LOW);                         // Geef spaning motoren
        KoppelServos();                                // koppel servo's aan
      }
      else {                                           // Als toegangscode verkeert is
        bewapend = false;                              // ontwapen
        digitalWrite(12, HIGH);                        // neem spaning weg van motoren
        OntkoppelServos();                             // haal spaning weg van motoren
      }
      break;

    case 'W':                                          // Stond er een W in de buffer?
      staat = Serial.parseInt();                       // sla volgent geheel getal op in staat

      switch (staat) {                                 // wat is waarde van staat?
        case 0:                                        // is 0?
          lig();                                       // zent signaal naar motoren om te gaan liggen.
          break;                                       // klaar
          
        case 1:                                        // is 1?
          zit();                                       //zent signaal naar motoren om te gaan zitten
          break;                                       // klaar
          
        case 2:                                        // is 2?
          sta();                                       // zent signaal naar motoren om te gaan staan
          break;                                       // klaar
          
        case 3:                                        // is 3?
          poot();                                      // zent signaal naar motoren klaar staan voor poot
          break;                                       // klaar
      }                                                // andere getalen worden overgeslagen
                                                       // en later behandelt
                                                       
      break;                                           // klaar

    case 'S':                                          // Stond er een S in de buffer?
      snelhijd = Serial.parseFloat();                  // maak van volgend getal snelhijd
      if (snelhijd < 4.0)                              // als de snelhijd te hoog is
        NOODSTOP();                                    // Voer nootstop uit
      break;                                           // klaar

    case 'H':                                          // Stond er een H in de buffer?
      hoek = Serial.parseFloat();                      // maak van volgend getal de hoek
      if (hoek < -90 || hoek > 90)                     // is gegeven hoek te groot of te klijn?
        NOODSTOP();                                    // voer nootsop uit.
      break;                                           // klaar

    case '\n':                                         // Negeer lege lijnen
      break;                                           // klaar

    default:                                           // Als geen van bovenstaande
                                                       // MALFORMED PACKET : KAN MASTER NIET MEER VERTROUWEN
      NOODSTOP();                                      // VOER NOODTSTOP UIT
      break;                                           // klaar
  }
}

void wandel() {                                        // maak functie

  int S1 = MAX_MOTOR_TIJD -                            // reken ingaande positie motor uit en sla op als S1
           ((int)posl % 100) * VER_MOTOR_TIJD / 100;   // maximum tijd motor - (de rest van positie gedeelt door 100) gedeelt door 100

  int S2 = MIN_MOTOR_TIJD +                            // reken uitgaande positie motor uit en sla op als S2
           ((int)posl % 100) * VER_MOTOR_TIJD / 100;   // minimum tijd motor - (de rest van positie gedeelt door 100) gedeelt door 100




  switch (((int)posl % 900) / 100) {                   // vind waarden ( rest van positie gedeelt door 800 ) gedeelt door 100
                                                       // in integer modus(geheele getallen) dit zorgt voor 0 tot 7 tellen

    case 0:                                            // is 0?
      servo[1].writeMicroseconds(S2);                  // shrijf aan tijd naar servo 1 (ingaande)
      break;                                           // KLAAR

    case 1:                                            // is 1?
      servo[0].writeMicroseconds(S2);                  // shrijf aan tijd naar servo 6 (ingaande)
      break;                                           // KLAAR

    case 2:                                            // is 2?
      servo[1].writeMicroseconds(S1);                  // shrijf aan tijd naar servo 6 (ingaande)
      break;                                           // KLAAR
  
    case 4:                                       // is 1?
      servo[0].writeMicroseconds(S1);             // shrijf aan tijd naar servo 7 (ingaande)
      servo[6].writeMicroseconds(S2);             // shrijf aan tijd naar servo 6 (ingaande)
      break;                                        // KLAAR

    case 6:                                       // is 0?
      servo[7].writeMicroseconds(S1);             // shrijf aan tijd naar servo 6 (ingaande)
      break;                                        // KLAAR

    case 7:                                       // is 1?
      servo[6].writeMicroseconds(S2);             // shrijf aan tijd naar servo 7 (ingaande)
      break;                                        // KLAAR

    case 8:                                       // is 1?
      servo[7].writeMicroseconds(S2);             // shrijf aan tijd naar servo 6 (ingaande)
      break;                                      // KLAAR
  }



  S1 = MIN_MOTOR_TIJD + VER_MOTOR_TIJD -          // reken ingaande positie motor uit en sla op als S1
       (((int)posr) % 100) * VER_MOTOR_TIJD / 100;  // maximum tijd motor - (de rest van positie gedeelt door 100) gedeelt door 100

  S2 = MIN_MOTOR_TIJD +                           // reken uitgaande positie motor uit en sla op als S2
       (((int)posr) % 100) * VER_MOTOR_TIJD / 100;  // minimum tijd motor - (de rest van positie gedeelt door 100) gedeelt door 100
 Serial.println(S1);
  switch (((int)posr % 900) / 100) {              // vind waarden ( rest van positie gedeelt door 800 ) gedeelt door 100
                                                  // in integer modus(geheele getallen) dit zorgt voor 0 tot 7 tellen

    case 0:                                       // is 0?
      servo[5].writeMicroseconds(S2);             // shrijf aan tijd naar servo 6 (ingaande)
      break;                                        // KLAAR

    case 1:                                       // is 1?
      servo[4].writeMicroseconds(S1);             // shrijf aan tijd naar servo 7 (ingaande)
      break;                                        // KLAAR

    case 2:                                       // is 1?
      servo[5].writeMicroseconds(S1);             // shrijf aan tijd naar servo 6 (ingaande)
      break;                                        // KLAAR

    case 4:                                       // is 1?
      servo[2].writeMicroseconds(S2);             // shrijf aan tijd naar servo 7 (ingaande)
      servo[4].writeMicroseconds(S2);             // shrijf aan tijd naar servo 6 (ingaande)
      break;                                        // KLAAR

    case 6:                                       // is 0?
      servo[3].writeMicroseconds(S1);             // shrijf aan tijd naar servo 6 (ingaande)
      break;                                        // KLAAR

    case 7:                                       // is 1?
      servo[2].writeMicroseconds(S1);             // shrijf aan tijd naar servo 6 (ingaande)
      break;                                        // KLAAR

    case 8:                                       // is 1?
      servo[3].writeMicroseconds(S2);             // shrijf aan tijd naar servo 6 (ingaande)
      break;                                        // KLAAR
  }
}
                                                       //
void setup()                                           // Functie die als eerste uitgevoert wordt.
{
  pinMode(12, OUTPUT);                                 // Activeer poort 12 zodat we relais K2 kunnen aansturen
  digitalWrite(12, HIGH);                              // Zet relais K2 uit

  Serial.begin(9600);                                  // Start comunicatie met PC
}


void loop()                                            // deze functie draait en blijft draaien na setup().
{
  if (Serial.available()) {                            // als de computer een berigt doorstuurt
    UpdateSerial();                                    // verwerk aanvraag
    LastPing = pos;                                    // sla tijd op van berigt.
  }
  
    if((pos-LastPing)>200){                            // Als de PC al meer als 200 ticks niets doorgestuurt heeft
    digitalWrite(12, HIGH);                            // Ontwapen systeem
    OntkoppelServos();                                 // Ontkoppel servo's
    bewapend=false;                                    // schakel bewapeningtoestand uit.
    }


  if (bewapend) {                                      // als je bewapend bent.
    switch (staat) {                                   // kijk waarde van staat na
      case 3:                                          // is 3?
        pootr();                                       // voer pootbeweging uit
        break;                                         // klaar
        
      case 4:                                          // als staat gelijk is aan 4
        wandel();                                      // voer functie wandel uit
        break;                                         // klaar
    }

    if (hoek > 0) {                                    // gaan we naar rechts?
      posl += snelhijd;                                // voeg snelhijd toe aan posl
      posr += snelhijd * cos(hoek);                    // voeg snelhijd*cos(hoek) toe aan posr
    }
    else if (hoek < 0) {                               // gaan we naar links?
      posl += snelhijd * cos(-hoek);                   // voeg snelhijd*cos(-hoek) toe aan posl
      posr += snelhijd;                                // voeg snelhijd toe aan posr
    }else{
      posl += snelhijd;                                // voeg snelhijd toe aan posr
      posr += snelhijd;                                // voeg snelhijd toe aan posr
    }
    pos++;                                             // maak pos groter
  }
  
  delayMicroseconds(VERTRAGING);                       // wacht
}
