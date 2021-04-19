# arduino_sw6115
An i2c library to control the sw6115 chip found on DIY-More lithium battery shields

## This is open-source, feel free to help out!
There is still a bunch of untapped potential in this chip. I have only written code for the basic stuff.

## Functions:
.readVbatt();
	 * returns battery voltage (mV).

.readVout();
	 * returns output voltage (mV).

.readIchrg();
	 * returns charging current (mA).

.readIdischrg();
	 * returns discharge current (mA).
	
.readTic();
	 * returns IC temperature (°C).
	
.readVntc();
	 * returns NTC voltage (mV).
	
.powerOff();
	 * Switches off battery-shield.
	


# Connections
## This applies to DIY-More battery-shield V9, and battery-shield V8

<a href="https://ibb.co/0FJssXV"><img src="https://i.ibb.co/fn0DDSG/Screenshot-23.png" alt="Screenshot-23" border="0"></a>

<a href="https://ibb.co/L9N8RWr"><img src="https://i.ibb.co/tYL4Ktz/61-FJGx-Yo-Tq-L-AC-SL1000.jpg" alt="61-FJGx-Yo-Tq-L-AC-SL1000" border="0"></a>
<a href="https://ibb.co/JRSGbtL"><img src="https://i.ibb.co/3yPj8dX/Shield2.jpg" alt="Shield2" border="0"></a>

<a href="https://ibb.co/bX57wTc"><img src="https://i.ibb.co/jDkH0mn/Image-15.jpg" alt="Image-15" border="0"></a>
