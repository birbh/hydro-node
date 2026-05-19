# hydro-node

Hydronode is an automated, web connected soil moisture management system built with ESP32, analog moisture sensor and a reliable feed valve.

## What is this project??
This project is a self thinking, internet connected plant care and monitoring system that bridges the gap betn hardware and earth soil. Unlike some DIY kits which rely on cheap and low quality pump, this project uses heavy duty solenoid water feed valve which was designed for water purifiers. It continuously tracks the soil vitals and serves local interface right from microcontroller. 

## Why is this unique?
It is unique because it has dual mode execution:: it uses hardware logic to dynamically protect plants from dry soil allowing instant,secure watering process for the plants and also can be controlled from mobilephone on the network.

## Story behind this:
I have a Kent RO purifier in my home. Recently the water from RO was leaking from the pipe and we called for support and a person came and changed a feed valve and charged us 10$ just for a part. I was curious about the part and after a hour of research I found that it was a feed valve which works on the principle of electromagnet. Then I started searching why it was leaking and what was the problem and found many reasons. Then I thought 'Why not open it and try to fix?？'. Then I opened it using screwdriver and foumd that the rubber in its bottom was slightly misplaced and some water dirts were deposited in the Base of valve.

So seeing this I cleaned the valve and repositioned the rubber in the bottom. Then I again tested it and say what? It worked and now was good as new. Then I started thinking of using on a project like this which would be lifesaving for many farmers and even in our home use. Then i started brainstorming and came to an idea of making an IOT project with this. 

## Why did I make it?

The main motive of Hydronode is that it solves major issues such as:
- frustrating unreliability of a hobbyisy irrigation setups and anexity of leaving plants unattended.
- in standard low quality valve small plastics clog easily and lack mechanical seating needed for clean water distribution.by using a robust solenoid valve, I want to create a system that handles direct water line pressures safely without any leaking

## Initial coponents(planned):
- ESP32 microcontroller
- Feed valve for water supply
- Relay
- Switch
