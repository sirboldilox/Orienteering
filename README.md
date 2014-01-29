Orienteering
============

Engineering Project Management, group task code

Languages: Parallax PBASIC, C


## Controller Notes:

ADCSRA set to 10001111

Bit: [7] ADC Enable
     [6] ADC start
     [5] ADC auto trigger	
     [4] ADC interupt flag
     [3] ADC interupt enable
     [2:0] ADC clock scaler

Enabled, will trigger interupt and scaled by Clock/128.


ADCSRA set to 00010000

Bit: [7] Bipolar Mode
     [6] Comparator enable
     [5] Reserved	
     [4] Left Adjust
     [3] Reserved
     [2:0] Auto trigger source

Set to default unipolar mode with left shift enabled for 8bit resolution.


DIDR0 set to 00000111

Bit [7:0] disables corresponding input bit on port A for digital signals

Disabled PortA[0:2] for 3 analogue inputs from sliders



