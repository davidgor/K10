(function(ext) {

    var snelhijd=0;
    var Gezigten=12;
    var hoek=0;
    var Druk=0;
    var Temp=0;
    var Noorden=0;
    var ok=0;

    // Cleanup function when the extension is unloaded
    ext._shutdown = function() {};


function httpGet(theUrl)
{
    if (window.XMLHttpRequest)
    {// code for IE7+, Firefox, Chrome, Opera, Safari
        xmlhttp=new XMLHttpRequest();
    }
    else
    {// code for IE6, IE5
        xmlhttp=new ActiveXObject("Microsoft.XMLHTTP");
    }
    xmlhttp.onreadystatechange=function()
    {
        if (xmlhttp.readyState==4 && xmlhttp.status==200)
        {
            return xmlhttp.responseText;
        }
    }
    xmlhttp.open("GET", theUrl, false );
    xmlhttp.send();    
}

    Update = function() {
	var req = new XMLHttpRequest();

	req.open('GET', 'pro', false);
	req.send(null);
	
	if(req.status == 200) {
	   var lines = req.responseText.split('\n');
	   	Gezigten=lines[0];
	   	snelhijd=lines[1];
		hoek=lines[2];
		Noorden=lines[3];
		Temp=lines[4];
		Druk=lines[5];
	}

	setTimeout(function(){
		Update()
	}, 50);
    };

    ext._getStatus = function() {
        return {status: 2, msg: 'Ready'};
    };

    ext.IsFaceFound = function() {
	if(Gezigten==0)
		return false;
	else
		return true;
    };

    ext.GetGezigten = function() {
	return Gezigten;
    };

    ext.GetSnelhijd = function() {
	return snelhijd;
    };

    ext.GetHoek = function() {
	return hoek;
    };

    ext.GetNoorden = function() {
	return Noorden;
    };

    ext.GetTemp = function() {
	return Temp;
    };

    ext.GetDruk = function() {
	return Druk;
    };

    ext.my_first_block = function() {
        // Code that gets executed when the block is run
    };

    // Block and block menu descriptions
    var descriptor = {
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
    ScratchExtensions.register('Sensoren', descriptor, ext);
    
	//verkrijg jquery
	var script = document.createElement('script');
	script.src = 'http://code.jquery.com/jquery-1.11.0.min.js';
	script.type = 'text/javascript';
	document.getElementsByTagName('head')[0].appendChild(script);
	
	setTimeout(function(){
		Update()
	}, 20000);
})({});
