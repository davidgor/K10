(function(ext) {									//Start

    var snelhijd=0;									//Sla hier snelhijd op
    var Gezigten=12;								//Sla hier het aantal gezigten op
    var hoek=0;									//Sla hoeksnelhijd op
    var Druk=0;									//Sla druk op
    var Temp=0;									//Sla temperatuur op
    var Noorden=0;									//Sla hoek tot noorden op
    var ok=0;										//Sla op of er fauten zijn

    // Cleanup function when the extension is unloaded
    ext._shutdown = function() {};					//Er moet niets speciaal gebeuren bij stoppen

    Update = function() {							// maak nieuwe funcite
	var req = new XMLHttpRequest();					// maak webaanvraag klaar

	req.open('GET', 'pro', false);						// laad pro van de webserver
	req.send(null);								// verzend aanvraag
		
	if(req.status == 200) {							// Is gelukt?
	   var lines = req.responseText.split('\n');			// deel aantwoord op lijn per lijn
	   	Gezigten=lines[0];							// schrijf eerste lijn naar gezigten
	   	snelhijd=lines[1];							// schrijf tweede lijn naar snelhijd
		hoek=lines[2];							// schrijf derde lijn naar hoek
		Noorden=lines[3];							// schrijf vierde lijn naar noorde
		Temp=lines[4];							// schrijf vijfde lijn naar temp
		Druk=lines[5];							// scrijf zesde lijn naar druk
	}

	setTimeout(function(){							// start later
		Update()									// jezelf
	}, 50);										// binnen 50 ms
    };

    ext._getStatus = function() {						//functie voor vraag: is programma oke?
        return {status: 2, msg: 'Ready'};					//zeg dat alles oke is
    };

    ext.IsFaceFound = function() {						// maak functie
	if(Gezigten==0)								// is het aantal gezigten gelijk aan 0
		return false;								// geef waar terug
	else											// anders
		return true;								// geef onwaar terug
    };

    ext.GetGezigten = function() {						// maak functie
	return Gezigten;								// geef aantal gezigten terug
    };

    ext.GetSnelhijd = function() {						// maak functie
	return snelhijd;								// geef snelhijd terug
    };

    ext.GetHoek = function() {						// maak functie
	return hoek;									// geef hoek terug
    };

    ext.GetNoorden = function() {						// maak functie
	return Noorden;								// geef hoek tot noorde terug
    };

    ext.GetTemp = function() {						// maak functie
	return Temp;									// geef temperatuur terug
    };

    ext.GetDruk = function() {						// maak functie
	return Druk;									// geef druk terug
    };


    // Block and block menu descriptions
    var descriptor = {								// maak lijst van blokken om toe te voegen
        blocks: [
            // Block type, block name, function name
            ['r', ' Kan Gezicht zien? ', 'IsFaceFound'],			
            ['r', ' Aantal gezigten  ', 'GetGezigten'],
            
            ['r', ' Snelhijd', 'GetSnelhijd'],
            ['r', ' hoek', 'GetHoek'],
            ['r', ' Noorden', 'GetNoorden'],
	    ['r', ' Temperatuur (C)', 'GetTemp'],
            ['r', ' Druk', 'GetDruk'],
        ]
    };

    // Register the extension
    ScratchExtensions.register('Sensoren', descriptor, ext);	// vertel scratchX dat we er zijn
    
	//verkrijg jquery
	var script = document.createElement('script');	
	script.src = 'http://code.jquery.com/jquery-1.11.0.min.js';
	script.type = 'text/javascript';
	document.getElementsByTagName('head')[0].appendChild(script);
	
	setTimeout(function(){							// start met update
		Update()									//
	}, 5000);										// binnen 5 seconden
})({});											// KLAAR
