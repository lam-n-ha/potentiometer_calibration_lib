# potentiometer_calibration_lib
ECE387 Midterm Project

# **Video demo**
The demo video of the library can be found here: https://www.youtube.com/shorts/HFV7CaCE1qU?feature=share

# **What is a potentiometer**
A potentiometer is three contact resistor with a sliding or rotating contact.

![image](https://user-images.githubusercontent.com/64882818/165802163-093102e2-fdb6-45d9-880c-69d322a553cc.png)

# **How a potentiometer works**
When only pin 1 and 2 are used, the potentiometer become a variable resistor. As a rotary potentiometer is turned (or a sliding potentiometer slides), the wiper moves over the resistive track and change the resistor value of the potentionmeter

When all 3 pins are used, the potentiometer form a voltage divider and can be used to measure and adjust voltage. the principle of a voltage divider can be found here:
https://en.wikipedia.org/wiki/Voltage_divider

# The CA9 Carbon ACP Potentiometer

The potentiometer is included in Arduino Starter Kit
Datasheet: The datasheet of the ACP CA9 potentiometer can be found here: https://www.arduino.cc/documents/datasheets/ACP_potentiometers.pdf

![image](https://user-images.githubusercontent.com/64882818/165806042-b8e90117-2b6f-475c-a908-a41126d293c9.png)
![image](https://user-images.githubusercontent.com/64882818/165806370-c22bc3a7-0e14-43ca-b461-f5ecb8fadd8f.png)

# **My Potentiometer build**

![image](https://user-images.githubusercontent.com/64882818/165807406-5d557c07-24d2-408c-aff2-d072e62fa927.png)

I tested the library using one potentiometer and and LCD, plus another potentiometer to control the brightness of the LCD.
The potentiometer calibration library contains:
A function to read and convert the analog signal from the potentiometer to a digital signal
A function to initialize timer and a delay function based on it that allow execution during value polls
The main function of the program count up a integer variable at a speed determined by the digital value from the potentiometer

The c file poten.c can be compiled with avr-gcc using the compile_script.py, a python script written by Dr. Jamie Peterson. Before compiling, modify path_win_avr to the path of avr-gcc on your computer. Specify the level of compilation and com port by passing them as command line argument. For example: python3 compile_script.py 4 com7
If a com port is not provided, the default is com4
