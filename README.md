# SunLightRise
Alarm Clock that wakes by shining light onto the user's face


# Parts needed:

1. Particle Photon (you can buy any one)
2. Adafruit NeoPixel Digital RGBW LED Strip - White PCB 144 LED/m - 1m (https://www.adafruit.com/product/2847)
3. 11in inner diameter circular container

# Steps

1. Configurate Photon to run "Sunrise.ino" (you can use the Particle Cloud IDE)
2. Copy down the destination URL of the particle
3. Load the iOS app, and change the destination variable to be the same the destination URL of the particle.

# Hardware

To get started, let’s assume you have some model of Arduino microcontroller connected to the computer’s USB port. We’ll elaborate on the finer points of powering NeoPixels later, but in general you’ll usually be using a 5V DC power supply (e.g. “wall wart”) or — for wearable projects — a 3.7 Volt lithium-polymer battery.

Identify the “input” end of your NeoPixel strip, pixel(s) or other device. On some, there will be a solder pad labeled “DIN” or “DI” (data input). Others will have an arrow showing the direction that data moves. The data input can originate from any digital pin on the Arduino, but all the example code is set up for digital pin 6 by default. The NeoPixel shield comes wired this way.

# What you should be able to do:

Use the iOS app to control the lights in your clock container.
