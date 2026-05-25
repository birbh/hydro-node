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
#define soil_moisture_sensor_pin 34;
#define relay_in_pin 26;

//req. variables
bool valve_state = false;
bool auto_esp= true;
int moistureper=0;
float batt_volt=0.0;

//soil values(changable)
int dry_soil=
int wet_soil=;


//html page for web server

<!DOCTYPE html>
<html>
<head>
    <title>HydroNode</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <style></style>
    </head>
<body>
<div class="container">
    <h1>HydroNode</h1>
    <div class="data">

