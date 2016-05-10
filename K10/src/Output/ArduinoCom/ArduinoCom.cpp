/*
 * ArduinoCom.cpp
 *
 *  Created on: 18-feb.-2016
 *      Author: david12
 */

#include "ArduinoCom.h"									// Haal te doen lijst op

FILE *arduino;											// Maak Geheugenplaats vrij voor arduino aan te koppelen
bool Block=false;										// Maag bit vrij voor onderbreken loop

bool Armd=false;										// Maak bit vrij om te weten of de arduino (BEWAPEND) is
pthread_t thread;										// Geheugen voor draat in te laten lopen

int MotorPoses[]={-1,-1,-1,-1,-1,-1,-1,-1};				// Sla alle statusen van de motor's op

Arduino_Com::Arduino_Com() {							// Voet uit bij aanmaak
	arduino = fopen("/dev/ttyUSB0", "w+");				// Koppel arduino aan (Shrijven + lezen)
	if (arduino==NULL)									// Check of koppelen geslaagt is
		arduino = fopen("/dev/ttyUSB1", "w+");			// Probeer aparaat op ander kontact te starten
	if (arduino==NULL)									// Check of koppelen geslaagt is
		arduino = fopen("/dev/ttyUSB2", "w+");			// Probeer aparaat op ander kontact te starten
	if (arduino==NULL){									// Check of koppelen geslaagt is
	  std::cout << "PANIC:Kan arduino niet verbinden\n";// Schrijf faut naar log
	  std::cout << "@ARDUINOCOM.CPP LINE:20\n";			//
	  fputs ("ARDUINO NIET GEVONDEN\n",stderr); 		//
	  //exit (-1);										// NOOTSTOP (Motor's kunnen onkotroleerbaar zijn)
	}
	pthread_create(&thread, 0, &Arduino_Com::Looper, 	// Start loop die input nakijkt en die nakijkt of
			this);										// de arduino nog aangekopeld is.
}

void Arduino_Com::SetMotor(int Motor,int Value){		// Voer uit om een motor naar positie te laten gaan
	if(MotorPoses[Motor]!=Value)						// als motor staat al niet juist staat
		fprintf(arduino, "M %d %d \n",Motor,Value);		// zent signaal in vorm (M1 50)
	fflush (arduino);
	MotorPoses[Motor]=Value;
}

char* Arduino_Com::GetInput(FILE* f){					// voer uit om input te lezen van arduino
	  char * buffer;									// maak geheugen vrij voor verwerking
	  long lSize=1;										// maak geheugen vrij voor verwerking
	  size_t result;									// maak geheugen vrij voor verwerking


	  buffer = (char*) malloc (sizeof(char)*lSize);		// Zeg hoeveelhijd gehuegen nodig is
	  if (buffer == NULL) {								// FOUT : niet genoeg geheugen vrij
		  std::cout << "PANIC:Kan geheugen niet sta\nn";// Schrijf faut naar log
	      std::cout << "@ARDUINOCOM.CPP LINE:38\n";		//
		  fputs ("Memory error\n",stderr); 				//
		  exit (-1);									// NOOTSTOP (waarshijnlijk geheugen aan het lekken)
	  }


	  // copy the file into the buffer:
	  result = fread (buffer,1,lSize,arduino);
	  //if (result != lSize) {fputs ("Reading error",stderr); exit (3);}
	  //free (buffer);

	  //cout << buffer <<result;
	  return buffer;
}

bool Arduino_Com::GetArmd(){							// Vraag of het systeem (BEWAPEND) is
	return Armd;										// Geef bit terug
}

void Arduino_Com::SetArmd(bool armd){					// Zet (BEWAPEND) aan of uit
	Armd=armd;											// Zet geheugen in juiste staat

	if(armd)											// Check of het aan of uit gezet moet worden
		fprintf(arduino, "A1 \n");							// Zet uit
	else												// Anders
		fprintf(arduino, "A0 \n");							// Zet aan
	fflush (arduino);									// Stuur door
}

bool Arduino_Com::Reconect(){							// Doe een poging om de arduino opnieuw aan te koppelen

	if(arduino!=NULL)									// Als arduino nog aangesloten is
		fclose (arduino);								// kopel hem dan nu los

	arduino = fopen("/dev/ttyUSB0", "w+");				// Koppel arduino aan (Shrijven + lezen)
	if (arduino==NULL)									// Check of koppelen geslaagt is
		arduino = fopen("/dev/ttyUSB1", "w+");			// Probeer aparaat op ander kontact te starten
	if (arduino==NULL)									// Check of koppelen geslaagt is
		arduino = fopen("/dev/ttyUSB2", "w+");			// Probeer aparaat op ander kontact te starten
	if (arduino==NULL){									// Check of koppelen geslaagt is
	  std::cout << "PANIC:Verbing met arduino krijt\n"; // Schrijf faut naar log
	  std::cout << "@ARDUINOCOM.CPP LINE:83\n";			//
	  fputs ("ARDUINO LOSGEKOPeLD\n",stderr); 			//
	  exit (-5);										// NOOTSTOP (Motor's kunnen onkotroleerbaar zijn)
	}
return true;
}

void* Arduino_Com::Looper(void *obj){					// Lus die blijft kijken naar opkomende oproepen
	for(;;){											// doe voor ewig
		/*if(access( arduino, F_OK ) != -1){						// kontroleer of arduino aangekopeld is
			arduino = fopen("/dev/ttyUSB0", "w+");				// Koppel arduino aan (Shrijven + lezen)
			if (arduino==NULL)									// Check of koppelen geslaagt is
				arduino = fopen("/dev/ttyUSB1", "w+");			// Probeer aparaat op ander kontact te starten
			if (arduino==NULL)									// Check of koppelen geslaagt is
				arduino = fopen("/dev/ttyUSB2", "w+");			// Probeer aparaat op ander kontact te starten
			if (arduino==NULL){									// Check of koppelen geslaagt is
			  std::cout << "PANIC:Verbing met arduino krijt\n"; // Schrijf faut naar log
			  std::cout << "@ARDUINOCOM.CPP LINE:83\n";			//
			  fputs ("ARDUINO LOSGEKOPeLD\n",stderr); 			//
			  exit (-5);										// NOOTSTOP (Motor's kunnen onkotroleerbaar zijn)
			}
		}*/
														//TODO MAKE FUNKTION
		usleep(1000);									// WACHT 1MS
		while(Block)									// tot blocken uit gaat
			usleep(1000);								// WACHT 1MS
	}
}

int Arduino_Com::GetMotor(int Motor){					// kijk motor staat na
	Block=true;
	fprintf(arduino, "M %d -1 \n",Motor);
	fflush (arduino);

	//for(int a=0;a!=100;a++){
	usleep(1000000);
		GetInput(arduino);
	//}
	Block=false;

	return -1;
}

Arduino_Com::~Arduino_Com() {
	fclose (arduino);
}

