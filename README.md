# joystick_experiments
Software to run behavioral joystick experiments with Drosophiola and collect time series data

Under ./TriplePlattform.ino/ you can find the software for the Arduino

Under ./Release/ you can find the setup file for the current GUI of the project

The documentation of this project can be found under https://youtu.be/zFMI1lQ3naE 

Visit the channel https://www.youtube.com/channel/UC0EiE6oDdhML3SIED-cxTbQ for further informations

Changelog 2.0.0.0

- function write_datafile() -> filename is the current dateTime; 
- fileDialog -> button "Abbrechen" was connected
- insert ledRedOnOff button for the led switching

Changlog 2.1.0.1

- now the calculation of the pi depends of the status of the platform_leds
- insert a try-catch block for the divison by zero
- single definiton of the hysteresis block, >= was changed to >
- the floating-point number is changed to two digits after the decimal point

For further information follow the link https://youtu.be/f2WfK15S_uA
