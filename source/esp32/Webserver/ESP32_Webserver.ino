/******************************************************************
  Created with PROGRAMINO IDE for Arduino
  Project     : Webserver with OLED and RGB
  Board       : MAKERFACTORY EBB ESP32
  Version     : 1.0
  Date        : 28.12.2018
  Author      : MF

  Description : Show text from Webserver at OLED and switch RGB LEDs
                and set background color of textboxes
  Note        : key in your personal SSID and Password

  Switches:
  I2C   SW307 ON
  I2C   SW308 ON
  LCD   SW309 all ON
  RGB   SW312 ON

  Original from:
  IOT Actor Board Webserver Demo for ESP32 DevKitC
  Elektor / Jens Nickel / My Journey in the IoT
*********************************************************************/


// +++++++++++++++++++ NETWORK ++++++++++++++++

// SSID and Password of your Wifi network
const char* txtSSID      = "xxxxxxxxxxxxxxx";
const char* txtPassword  = "xxxxxxxxxxxxxxx";




// +++++++++++++++++++ OLED +++++++++++++++++++

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h> // https://github.com/adafruit/Adafruit-GFX-Library
#include "Adafruit_SSD1306.h" // https://github.com/adafruit/Adafruit_SSD1306
#define OLED_RESET -1
Adafruit_SSD1306 display(OLED_RESET);

#define LOGO16_GLCD_HEIGHT 64
#define LOGO16_GLCD_WIDTH  128
static const unsigned char PROGMEM logo16_glcd_bmp[] =
{
  B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000
};


// +++++++++++++++++++ RGB LED +++++++++++++++++++

#include <Adafruit_NeoPixel.h> // https://github.com/adafruit/Adafruit_NeoPixel
#define PIN         2
#define NUMPIXELS   4
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);



// +++++++++++++++++++ Start of Webserver Library +++++++++++++++++++
// as ESP32 Arduino Version

#include <WiFi.h>

WiFiClient myclient;
WiFiServer server(80);

void Webserver_Start()
{
  server.begin();     // Start TCP/IP-Server on ESP32
}


//  Call this function regularly to look for client requests
//  template see https://github.com/espressif/arduino-esp32/blob/master/libraries/WiFi/examples/SimpleWiFiServer/SimpleWiFiServer.ino
//  returns empty string if no request from any client
//  returns GET Parameter: everything after the "/?" if ADDRESS/?xxxx was entered by the user in the webbrowser
//  returns "-" if ADDRESS but no GET Parameter was entered by the user in the webbrowser
//  remark: client connection stays open after return

String Webserver_GetRequestGETParameter()
{
  String GETParameter = "";

  myclient = server.available();   // listen for incoming clients

  //Serial.print(".");

  if (myclient) {                            // if you get a client,
    Serial.println("New Client.");           // print a message out the serial port
    String currentLine = "";                 // make a String to hold incoming data from the client

    while (myclient.connected()) {           // loop while the client's connected

      if (myclient.available()) {            // if there's bytes to read from the client,

        char c = myclient.read();            // read a byte, then
        Serial.write(c);                     // print it out the serial monitor

        if (c == '\n') {                     // if the byte is a newline character

          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request
          if (currentLine.length() == 0) {

            if (GETParameter == "") {
              GETParameter = "-";
            };    // if no "GET /?" was found so far in the request bytes, return "-"

            // break out of the while loop:
            break;

          } else {    // if you got a newline, then clear currentLine:
            currentLine = "";
          }

        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }

        if (c == '\r' && currentLine.startsWith("GET /?"))
          // we see a "GET /?" in the HTTP data of the client request
          // user entered ADDRESS/?xxxx in webbrowser, xxxx = GET Parameter
        {
          GETParameter = currentLine.substring(currentLine.indexOf('?') + 1, currentLine.indexOf(' ', 6));    // extract everything behind the ? and before a space
        }
      }
    }
  }
  return GETParameter;
}



// Send HTML page to client, as HTTP response
// client connection must be open (call Webserver_GetRequestGETParameter() first)
void Webserver_SendHTMLPage(String HTMLPage)
{
  String httpResponse = "";

  // begin with HTTP response header
  httpResponse += "HTTP/1.1 200 OK\r\n";
  httpResponse += "Content-type:text/html\r\n\r\n";

  // then the HTML page
  httpResponse += HTMLPage;

  // The HTTP response ends with a blank line:
  httpResponse += "\r\n";

  // send it out to TCP/IP client = webbrowser
  myclient.println(httpResponse);

  // close the connection
  myclient.stop();

  Serial.println("Client Disconnected.");

};

// +++++++++++++++++++ End of Webserver library +++++++++++++++++++++






void RGB_BLUE()
{
  for (int i = 0; i < 4; i++)
  {
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    strip.setPixelColor(i, strip.Color(0, 0, 50));      // blue
    strip.show(); // This sends the updated pixel color to the hardware.
  }
}

void RGB_GREEN()
{
  for (int i = 0; i < 4; i++)
  {
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    strip.setPixelColor(i, strip.Color(0, 50, 0));      // green
    strip.show(); // This sends the updated pixel color to the hardware.
  }
}
void RGB_OFF()
{
  for (int i = 0; i < 4; i++)
  {
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    strip.setPixelColor(i, strip.Color(0, 0, 0));       // off
    strip.show(); // This sends the updated pixel color to the hardware.
  }
}







// +++++++++++++++++++ Configuration Values +++++++++++++++++++

// this section handles configuration values which can be configured via webpage form in a webbrowser

// 8 configuration values max
String ConfigName[8];     // name of the configuration value
String ConfigValue[8];    // the value itself (String)
int    ConfigStatus[8];   // status of the value:    0 = not set    1 = valid   -1 = not valid


// Initalize the values
void InitializeConfigValues()
{
  for (int count = 0; count < 8; count++)
  {
    ConfigName[count] = "";
    ConfigValue[count] = "";
    ConfigStatus[count] = 0;
  }
}


// Build a HTML page with a form which shows textboxes to enter the values
// returns the HTML code of the page
String EncodeFormHTMLFromConfigValues(String TitleOfForm, int CountOfConfigValues)
{
  // Head of the HTML page
  String HTMLPage = "<!DOCTYPE html><html>";

  HTMLPage += "<body><h2>" + TitleOfForm + "</h2><form><table>";

  // for each configuration value
  for (int c = 0; c < CountOfConfigValues; c++)
  {
    // set background color by the status of the configuration value
    String StyleHTML = "";
    if (ConfigStatus[c] == 0)  {
      StyleHTML = " Style =\"background-color: #FFD700;\" " ;
    };   // yellow     NOT SET
    if (ConfigStatus[c] == 1)  {
      StyleHTML = " Style =\"background-color: #98FB98;\" " ;
    };   // green      VALID
    if (ConfigStatus[c] == -1) {
      StyleHTML = " Style =\"background-color: #FF6347;\" " ;
    };   // red        NOT VALID

    // build the HTML code for a table row with configuration value name and the value itself inside a textbox
    String TableRowHTML = "<tr><th>" + ConfigName[c] + "</th><th><input name=\"" + ConfigName[c] + "\" value=\"" + ConfigValue[c] + "\" " + StyleHTML + " /></th></tr>";

    // add the table row HTML code to the page
    HTMLPage += TableRowHTML;
  }

  // add the submit button
  HTMLPage += "</table><br/><input type=\"submit\" value=\"Submit\" />";

  // add a text line
  HTMLPage += "<br><br>enter on or off at Line 1 and press submit";

  // footer of the webpage
  HTMLPage += "</form></body></html>";

  return HTMLPage;
}


// Decodes a GET parameter (expression after ? in URI (URI = expression entered in address field of webbrowser)), like "Country=Germany&City=Aachen"
// and set the ConfigValues
int DecodeGETParameterAndSetConfigValues(String GETParameter)
{

  // GETParameter ist z.B.:  LED1=00&LED2=FF&LED3=FF

  int posFirstCharToSearch = 1;
  int count = 0;

  // while a "&" is in the expression, after a start position to search
  while (GETParameter.indexOf('&', posFirstCharToSearch) > -1)
  {
    int posOfSeparatorChar = GETParameter.indexOf('&', posFirstCharToSearch);  // position of & after start position
    int posOfValueChar = GETParameter.indexOf('=', posFirstCharToSearch);      // position of = after start position

    // Wert holen
    ConfigValue[count] = GETParameter.substring(posOfValueChar + 1, posOfSeparatorChar);  // extract everything between = and & and enter it in the ConfigValue

    posFirstCharToSearch = posOfSeparatorChar + 1;  // shift the start position to search after the &-char
    count++;
  }

  // no more & chars found

  int posOfValueChar = GETParameter.indexOf('=', posFirstCharToSearch);       // search for =

  ConfigValue[count] = GETParameter.substring(posOfValueChar + 1, GETParameter.length());  // extract everything between = and end of string
  count++;

  return count;  // number of values found in GET parameter
}





void setup()
{

  // RGB LED
  strip.begin(); // This initializes the NeoPixel library
  strip.show();  // Initialize all pixels to 'off'
  RGB_OFF();


  // OLED
  Serial.begin(9600);
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  // init done
  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  display.display();
  delay(2000);
  // Clear the buffer.
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(1, 1);
  display.println("Hello ESP32!");
  display.println("");
  display.display();

  // Open serial communications and wait for port to open:
  //Serial.begin(115200);
  Serial.println("Hello ESP32!");

  boolean success = true;


  // connect to WiFi network
  // see https://www.arduino.cc/en/Reference/WiFiBegin

  WiFi.begin(txtSSID, txtPassword);

  // we wait until connection is established
  // or 10 seconds are gone

  int WiFiConnectTimeOut = 0;
  while ((WiFi.status() != WL_CONNECTED) && (WiFiConnectTimeOut < 10))
  {
    delay(1000);
    WiFiConnectTimeOut++;
  }

  // not connected
  if (WiFi.status() != WL_CONNECTED)
  {
    success = false;
  }

  if (success == true)
  {
    RGB_BLUE();
  }
  else
  {
    RGB_OFF();
  }

  // print out local address of ESP32 in LAN
  Serial.println(WiFi.localIP());

  // Display
  display.println(WiFi.localIP());
  display.println("");
  display.display();



  // initialize config values and set first 3 names of values to LED1...LED3
  InitializeConfigValues();
  ConfigName[0] = "LINE1";
  ConfigName[1] = "LINE2";
  ConfigName[2] = "LINE3";

  // start the webserver to listen for request of clients in LAN
  Webserver_Start();

}

// check the ConfigValues and set ConfigStatus
// process the ConfigValues to switch something
void ProcessAndValidateConfigValues(int countValues)
{

  Serial.println("");
  Serial.println(ConfigValue[0]);
  Serial.println(ConfigValue[1]);
  Serial.println(ConfigValue[2]);
  Serial.println("");


  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(1, 1);
  display.print("1: ");
  display.println(ConfigValue[0]);
  display.println("");
  display.print("2: ");
  display.println(ConfigValue[1]);
  display.println("");
  display.print("3: ");
  display.println(ConfigValue[2]);
  display.display();



  if (countValues > 8) {
    countValues = 8;
  };

  // for each ConfigValue
  for (int cn = 0; cn < countValues; cn++)
  {
    // in this application the text string must be "on" or "off"
    if ((ConfigValue[cn].equals("on")) || (ConfigValue[cn].equals("off")))
    {
      ConfigStatus[cn] = 1;         // value is valid = green
    }
    else
    {
      ConfigStatus[cn] = -1;        // value is not valid = red
    }

    if (ConfigValue[cn].equals(""))
    {
      ConfigStatus[cn] = 0;         // value not set 0 yellow
    }

  }


  // first config value is used to switch RGB LED
  if (ConfigValue[0].equals("off"))
  {
    RGB_OFF();
  }
  if (ConfigValue[0].equals("on"))
  {
    RGB_GREEN();
  }






}



void loop() {

  String GETParameter = Webserver_GetRequestGETParameter();   // look for client request

  if (GETParameter.length() > 0)        // we got a request, client connection stays open
  {
    if (GETParameter.length() > 1)      // request contains some GET parameter
    {

      Serial.println("Received:");
      Serial.println(GETParameter);
      Serial.println("");

      /*
        display.clearDisplay();
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(1,1);
        display.print(GETParameter);
        display.display();
      */

      int countValues = DecodeGETParameterAndSetConfigValues(GETParameter);     // decode the GET parameter and set ConfigValues
      ProcessAndValidateConfigValues(countValues);                              // check and process ConfigValues
    }
    String HTMLPageWithConfigForm = EncodeFormHTMLFromConfigValues("ESP32 Webserver Demo", 3);   // build a new webpage with form and new ConfigValues entered in textboxes
    Webserver_SendHTMLPage(HTMLPageWithConfigForm);    // send out the webpage to client = webbrowser and close client connection
  }

  delay(50);
}
