This code is designed to be run on a Particle Photon.

Using the photon read the current state of the soil. Then decide based on the weather and soil moisture and temperature if we should water, or wait to water because it is about to rain or something.

Notes: This is still a work in progress. Code may not be performing all the tasks above yet.

Compilation:
	You must run the configuration generator script in order to setup the variables with your adafruit IO username and password if you are planning on using that. (Currently is used as part of development) 

Libraries:
	I had to take the SHT1x Library and put it in here because I have been using the Photon web IDE *Shame*. You should look at their repository for the most up to date code.

Hardware List:
Adafruit Solar panel
Adafruit Solar Lipo UPS
Lipo with JST connector (currently 500mAh)
5V boost converter
Particle Photon
Soil sensor

Optional:
Hose solenoid
