# hydro-node

Hydronode is an ESP32 based smart irrigation and plant monitoring system which is designed to automate watering using industrial grade solenoid feed valve.

## What is this project??
This project is a self thinking, internet connected plant care and monitoring system that bridges the gap between hardware and earth. Unlike some DIY kits which rely on cheap and low quality pump, this project uses heavy duty solenoid water feed valve which was designed for water purifiers. The moisture sensor continuously tracks the soil vitals and serves local interface right from microcontroller. 

## Why is this unique?
It is unique because it has dual mode execution : it uses hardware logic to dynamically protect plants from dry soil allowing instant,secure watering process for the plants and also can be controlled from mobilephone on the network.

## Story behind this:
I have a Kent RO purifier in my home. Recently the water from RO was leaking from the pipe and we called for support and a person came and changed a feed valve and charged us 10$ just for a part. I was curious about the part and after a hour of research I found that it was a feed valve which works on the principle of electromagnet. Then I started searching why it was leaking and what was the problem and found many reasons. Then I thought 'Why not open it and try to fix?？'. Then I opened it using screwdriver and foumd that the rubber in its bottom was slightly misplaced and some water dirts were deposited in the Base of valve.

So seeing this I cleaned the valve and repositioned the rubber in the bottom. Then I again tested it and say what? It worked and now was good as new. Then I started thinking of using on a project like this which would be lifesaving for many farmers and even in our home use. Then i started brainstorming and came to an idea of making an IOT project with this. 

## Why did I make it?

The main motive of Hydronode is that it solves major issues such as:
- frustrating unreliability of a hobbyist irrigation setups and anexity of leaving plants unattended.
- in standard low quality valve small plastics clog easily and lack mechanical seating needed for clean water distribution by using a robust solenoid valve, I want to create a system that handles direct water line pressures safely without any leaking.

## How to use it??

1. First, power the esp32 and connect the valve system properly.
2. Upload the firmware using arduino ide.
3. Connect the ESP32 to your wifi network by editing a part in firmware:
```const char* ssid="hydronode";
const char* password="soil@123";
```
4. Open serial monitor in your pc and copy the ESP32 IP address. eg: 192.168.1.5
5. Open the IP address in your browser while connected to the same wifi.
6. Use the dashboard to:
- monitor soil moisture
- enable AUTO mode
- manually control watering
7. Place the sensor into soil and connect the valve to the water line.
(note: hydronode will also automatically water plants when soil becomes dry.)



## Features:
- Realtime soil moisture monitoring
- Auto irrigation logic
- Manual watering from mobile
- ESP32 Wifi web dashboard
- Solar powered green energy system
- Industrial grade 24 V solenoid valve
- Low cost modular design

## Web Dashboard:

HydroNode includes a built in mobile friendly web interface hosted directly on ESP32.
This dashboard allows user to:

- Monitorsoil moisture percentage
- Check valve status
- Enable auto irrigation mode
- Manually turn watering ON and OFF
- No external mobile app or cloud service required

## Auto irrigation logic:
| Moisture level | Action |
| ------- | ------ | 
| 0-30% | Start Watering | 
| 30-60% | Maintain Normal state | 
| 60-100% | Stop Watering | 


## Power System:
The ESP32 is powered using a rechaargable 18650 battery combined with solar assisted charging.
The valve sysrem uses dedicated 24V adapter ro safely handle higher current requirements.
This hybrid power architecture improves efficiency portability and long term reliability.


## Initial coponents(planned):

- ESP32 DevKit V1
- Capacitive soil moisture sensor v1.2 
- 1 Channel Relay Module
- FPD-180K80-DC24V Solenoid Feed Valve
- 24V 0.5A DC Power Supply Adapter 
- 1N4007 diode
- Breadboard
- Pipe ( 1/4" Size) for purifiers
- Multimeter(Optional)
- Oled display(Optional)
- Waterproof Box
- Solar Panel 70x70mm, 4V, 100mA
- MT3608 Boost Converter 
- TP4056 Charger Module 
- Lithium-ion battery 18650
- 18650 Series Batteries Holder