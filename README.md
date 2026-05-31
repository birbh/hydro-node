# hydro-node

Hydronode is an ESP32 based smart irrigation and plant monitoring system which is designed to automate watering using industrial grade solenoid feed valve.

<img width="1410" height="2000" alt="hydronode" src="https://github.com/user-attachments/assets/b5c2abea-d442-4dd7-a66c-f98abe347134" />


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

## How to build it?
### Prepare the enclosure:

1. 3D Print the enclosure and lid as shown in CAD model.(OR buy a waterproof box)
2. If you buy a waterproof box, create mounts for:
    - USB charging module
    - Solar mount
    - OLED display
    - Battery holder
    - Relay holder
    - Boost converter
    - ESP32 mount
    - Hinge mount
    - Wire holes 
    - Switch mount
3. Secure all components using screws, standoffs or adhesive mounts
4. Install internal electronics and mount them as follows:
    - ESP32 Devkit V1
    - Relay module
    - Breadboard(use the dedicated tape in the breadboard to mount it)
    - TP4056 Charging Module(use my custom part in CAD for this)
    - MT3608 Boost Converter
    - 18650 battery holder
    - Oled display
    - Solar panel
    - Switch

    (Note: ensure that the electronics are secured and no conductive parts are touching each other)
    - Install the hinge model and mount it with screws as in the CAD.
5. Assembling the water system:
    - Connect the plumbing as shown in the CAD:
        - WATER SOURCE -> SOLENOID VALVE -> PLANT POT
    - The valve should be installed inline between the water source and the plant irrigation pipe.
    - Use 1/4" inch RO tubing and compatible connectors to prevent leaks
    - Install soil moisture sensor vertically into the soil near plant roots
    - Avoid placing the sensor directly beside the water outlet, as this may produce inaccurate recordings
    - Connect the relay and valve with 24V DC adapter
    - Install a 1N4007 flyback diode across the valve terminals to prevent it from voltage spikes.
6. Configure the power system:
    - First set the MT3608 output to exactly 5V using the multimeter
    - Connect the solar panel to TP4056 charging module
    - Then TP4056 module to MT3608 boost converter
    - Then MT3608 boost converter to ESP32 usb port
7. Upload the firmware to ESP32 and update the wifi credentials in firmware
8. Test the system verifying all the components of the system
(be sure to set the moisture sensor values according to your environmental condition)

### Final assembly:
After successful testing:
- Organize wiring neatly
- close the enclosure
- connect the permanent water source
- seal cable openings to prevent short circuits
- ensure the electronics never come in contact with water


## How to use it??

1. First, power the esp32 and connect the valve system properly.
2. Upload the firmware using arduino ide.
3. Connect the ESP32 to your wifi network by editing a part in firmware:
```
const char* ssid="hydronode";
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
- Industrial grade 24V solenoid valve
- Low cost modular design

## Web Dashboard:

HydroNode includes a built in mobile friendly web interface hosted directly on ESP32.
This dashboard allows user to:

- Monitor soil moisture percentage
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
The valve system uses dedicated 24V adapter ro safely handle higher current requirements.
This hybrid power architecture improves efficiency portability and long term reliability.

## CAD:
### SS:

<img width="917" height="490" alt="Screenshot 2026-05-31 at 4 35 32 PM" src="https://github.com/user-attachments/assets/e930e68b-4a1a-40d4-b0ca-cec278cf6530" />
<img width="894" height="678" alt="Screenshot 2026-05-31 at 4 39 03 PM" src="https://github.com/user-attachments/assets/279d2add-b94f-439a-a4bd-3b3728406873" />
<img width="998" height="573" alt="Screenshot 2026-05-31 at 4 37 30 PM" src="https://github.com/user-attachments/assets/8f8f5f93-136b-44b9-8533-b38e675c1a05" />
<img width="794" height="632" alt="Screenshot 2026-05-31 at 4 39 58 PM" src="https://github.com/user-attachments/assets/5c2d54bb-2e50-4ea5-b1b4-5400ca7ef76d" />


### Links:
Onshape: [Hydronode](https://cad.onshape.com/documents/a54d490bebb072f24616d72a/w/eb742d430f9342788aa9bc21/e/95767b8b5a8d5928ced10f44?renderMode=0&uiState=6a1c0f1aa795d8111e87a7a2)

## Circuit:
### SS:
<img width="1083" height="669" alt="solar+charging" src="https://github.com/user-attachments/assets/c93fdc69-52b5-44be-a1be-2b728e006b2e" />
<img width="799" height="790" alt="esp-circuit" src="https://github.com/user-attachments/assets/1f02cb2b-bef8-457a-853e-d2d4b7dc8388" />


### Links:
Wokwi: [esp-circuit](https://wokwi.com/projects/464828058447249409RL)

Tinkercad:  [solar and charging](https://www.tinkercad.com/things/fsAw2kbm3HE-solar-hydronode?sharecode=bEeTNQzSeW2zAY5gLIxz8n3GflD4GGp1yJB8_YdFxDo)

### Pin mapping:
### Soil moisture sensor:
| Component | ESP32 pin |
| ------- | ------ | ------ |
| Soil Moisture sensor(AOUT) | GPIO34 | 
| VCC | 3V3 |
| GND | GND |

### Relay module:
| Relay pin | Connection |
| ------- | ------ | 
| VCC | VIN(5V) | 
| GND | GND | 
| IN | GPIO26 | 
| NO | Solenoid Valve(+ve) |
| COM | 24V Adapter(+ve) |

### OLED Pin:
| OLED | ESP32 pin |
| ------- | ------ | 
| VCC | 3V3 |
| GND | GND |
| OLED SDA | GPIO21 | 
| OLED SCL | GPIO22 | 

### Solenoid valve:
| Solenoid | Connection | 1N4007 diode |
| ------- | ------ | 
| Solenoid Valve(+ve) | Relay(NO) | Stripe side |
| Solenoid Valve(-ve) | 24V Adapter(-ve) | Non-stripe side |

### 24V adapter:
| Adapter | Connection |
| ------- | ------ | 
| 24V Adapter(+ve) | Relay(COM) |
| 24V Adapter(-ve) | Solenoid Valve(-ve) |

### Charging and boost:
### TP4056 charging module:
| Module | Connection |
| ------- | ------ | 
| B+ | 3.6V li-ion battery(+ve) |
| B- | 3.6V li-ion battery(-ve) |
| IN+ | Solar panel(+ve) |
| IN- | Solar panel(-ve) |
| OUT+ | MT3608 Boost(VIN+) |
| OUT- | MT3608 Boost(VIN-) |

### MT3608 Boost converter(set to 5V):
| Module | Connection |
| ------- | ------ | 
| VIN+ | TP4056(OUT+) |
| VIN- | TP4056(OUT-) |
| VOUT+ and VOUT- | Join to ESP32 usb port wires |


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
