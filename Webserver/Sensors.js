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
	   var respons=req.responseText;
	   var lines = $respons.split('\n');
	   for(var i = 0;i < lines.length;i++){
	   	alert(i);
	   }
	}

	setTimeout(function(){
		Update()
	}, 20000);
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
            ['r', ' Noorden', 'Noorden'],
	    ['r', ' Temperatuur (C)', 'GetTemp'],
            ['r', ' Druk', 'GetTemp'],
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
