//============================================================================
// Name        : K9.cpp
// Author      : David Gorrebeeck
// Version     : 0.1
// Copyright   : GPL
// Description : K9 software om hond te controleeren
//============================================================================

#include "ClasHolder.h"
#include "Loger/Loger.h"



int main() {

	Loger* log		= new Loger;

	log->Log(3,"Starten ...");

	ClasHolder* ch  = new ClasHolder(log);

	for(;;){
		ch->Update();
		ch->Upgrade();
		ch->Sync();
	}



	return 0;									// Stop progama met code 0 ( Gestopt geen probleem )
}												// STOP
