# Raspi_OLED_Interface
An interactable interface for the Raspberry Pi

## Setup
You need to install the WiringPi library (not included in Raspberry Pi OS Lite) and enable SPI interface.

## Overview
In tools there is a json that determines menu structure, this is then setup by a python file at compilation time.
All items must inherit the Node class which allows it to fit in as a menu item seamlessly.
