# temaDirigido
Project for the second year of graduation in IME


The objective of this project is to develop a interface between diferent types of signals, including RF and bluetooth, by a microcontroller, at first with an ATmega328p, but evolving to other kinds of microcontrollers.


Guide for ASCII comunication between BT module and main server:

From BT:

a - Button A pressed

b - Button B pressed

c - Button C pressed

g - Enable change the code in first address

h - Enable change the code in second address

i - Enable change the code in third address

t - Disable change the code in first address

u - Disable change the code in second address

v - Disable change the code in third address


From main server:

A - Received code stored in first address

B - Received code stored in second address

C - Received code stored in third address

G - Changed code in first address

H - Changed code in second address

I - Changed code in third address
