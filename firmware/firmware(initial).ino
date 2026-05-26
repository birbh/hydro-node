#include <WiFi.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include <WebServer.h>

#define width 128
#define height 64

Adafruit_SSD1306 display(width, height, &Wire, -1);

WebServer server(80);

// wifi info.

const char* ssid="hydronode";
const char* password="soil@123";


// pins
#define soil_moisture_sensor_pin 34
#define relay_in_pin 26

//req. variables
bool valve_state = false;
bool auto_esp= true;
int moistureper=0;

//soil values(changable acc to your sensor)
int dry_soil=3500;
int wet_soil=1500;

//time see
unsigned long prevmillis=0;
const long interval=2000;



//html page for web server
String webpage(){
String page=R"rawliteral(
<!DOCTYPE html>
<html>
<head>
    <title>HydroNode</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <style>
        body { 
            font-family: Arial, sans-serif;
            background: #3a3838;
            color: white;
            text-align: center;
            padding: 15px;
        }
        .container {
            background: #2a2828;
            padding: 20px;
            border-radius: 20px;
            margin: auto;
            max-width: 400px;
            box-shadow: 0 0 20px rgba(0, 0, 0, 0.4);
            
        }
        h1{
            color: #4CAF50;
        }
        .data{
            font-size: 22px;
            margin:15px;
        }
        button{
            width: 150px;
            padding: 15px;
            margin:10px;
            border: none;
            border-radius: 15px;
            font-size: 16px;
            cursor: pointer;
        }
        .on{
            background: #4ca7af;
            color: white;
        }
        .off{
            background: #c53b31;
            color: white;
        }
        .mode{
            background: #439045;
            color: white;
        }

    </style>
    </head>
<body>
<div class="container">
    <h1>HydroNode</h1>

    <div class="data">
    Moisture: )rawliteral";
    page+= moistureper;
    page+=R"rawliteral(%</div>
    
    <div class="data">
    Valve: )rawliteral";
    page+= valve_state ? "ON" : "OFF";
    page+=R"rawliteral(</div>
    <a href="/on">
        <button class="on">Water ON</button>
    </a>
    <a href="/off">
        <button class="off">Water OFF</button>
    </a>
    <a href="/auto">
        <button class="mode">Auto Mode</button>
    </a>
    <a href="/manual">
        <button class="mode">Manual Mode</button>
    </a>
</div>
</body>
</html>)rawliteral";
return page;
}


// handlers
void handleroot(){
    server.send(200,"text/html",webpage());  
}
void handleon(){
    valve_state = true;
    digitalWrite(relay_in_pin, LOW);
    server.sendHeader("Location", "/");
    server.send(303);
}
void handleoff(){
    valve_state=false;
    digitalWrite(relay_in_pin, HIGH);
    server.sendHeader("Location", "/");
    server.send(303);
}
void handleauto(){
    auto_esp= true;
    server.sendHeader("Location", "/");
    server.send(303);
}

void handlemanual(){
    auto_esp=false;
    server.sendHeader("Location", "/");
    server.send(303);
}


//moisturesensor read
void readmoisture(){
    int raw_value= analogRead(soil_moisture_sensor_pin);
    //calc %
    int moisturepercent=map(raw_value,dry_soil,wet_soil,0,100);
    moistureper= constrain(moisturepercent,0,100);
}

//auto watering

void auto_watering(){
    if (auto_esp){
        if(moistureper<30){
            valve_state= true;
            digitalWrite(relay_in_pin, LOW);
        }
        else if(moistureper>60){
            valve_state=false;
            digitalWrite(relay_in_pin, HIGH);

        }
    }
}

//oled 
void oleddisplay(){
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0,0);
    display.println("HydroNode");
    display.setCursor(0,16);
    display.print("Moisture: ");
    display.print(moistureper);
    display.print("%");

    display.setCursor(0,32);
    display.print("Valve: ");
    if (valve_state){
        display.print("ON");
    }
    else{
        display.println("OFF");
    }

    display.setCursor(0,48);
    display.println("MODE");
    
    if (auto_esp){
        display.print("AUTO");
    }
    else{
        display.print("MANUAL");
    }
    display.display();

}

//setup 
void setup(){
    Serial.begin(115200);
    pinMode(relay_in_pin,OUTPUT);
    digitalWrite(relay_in_pin,HIGH);

    //oled init..
    Wire.begin(21,22);
    if (!display.begin(SSD1306_SWITCHCAPVCC,0x3C))
    {
        Serial.println("OLED Failed");
        while(true);
    }
    display.clearDisplay();
    display.display();

    // wifi ini..
    WiFi.begin(ssid,password);
    display.setTextSize(1);
    display.setTextColor(WHITE);

    while (WiFi.status()!= WL_CONNECTED)
    {
        delay(1000);
        display.clearDisplay();
        display.setCursor(0,0);
        display.println("Connecting WiFi....");
        display.display();
    }
    
    // wifi conn...
    display.clearDisplay();
    display.setCursor(0,0);
    display.println("WiFi Connected");
    display.println("");
    display.println(WiFi.localIP());
    display.display();
    Serial.println(WiFi.localIP());

    //web route
    server.on("/",handleroot);
    server.on("/on",handleon);
    server.on("/off",handleoff);
    server.on("/auto",handleauto);
    server.on("/manual",handlemanual);
    server.begin();



}


//loop
void loop(){
    server.handleClient();

    unsigned long millisnow=millis();
    if(millisnow- prevmillis>=interval){
        prevmillis=millisnow;
    readmoisture();
    auto_watering();
    oleddisplay();
    }
}