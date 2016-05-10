(function(ext) {
    // Cleanup function when the extension is unloaded
    ext._shutdown = function() {};

    // Status reporting code
    // Use this to report missing hardware, plugin or unsupported browser
    ext._getStatus = function() {
        return {status: 2, msg: 'Ready'};
    };

    ext.my_first_block = function() {
        // Code that gets executed when the block is run
    };

    // Block and block menu descriptions
    var descriptor = {
        blocks: [
            // Block type, block name, function name
            [' ', ' Vooruit snelhijd: %n hoek: %n ', 'Vooruit'],
            [' ', ' Vooruit snelhijd: %n hoek: %n voor: %n', 'Vooruit'],
            
            [' ', ' Achteruit %n hoek: %n ', 'Achteruit'],
            [' ', ' Achteruit %n hoek: %n  voor: %n', 'Achteruit'],
            
            [' ', ' verander snelhijd: %n', 'Achteruit'],
            
            [' ', ' STOP ', 'STOP'],
            
        ]
    };

    // Register the extension
    ScratchExtensions.register('Bewegingen', descriptor, ext);
})({});
