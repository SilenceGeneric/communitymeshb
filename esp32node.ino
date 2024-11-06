#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <ArduinoJson.h>

const char* ssid = "Your_SSID";  // Replace with your network SSID
const char* password = "Your_PASSWORD";  // Replace with your network Password
const char* serverIP = "192.168.1.100";  // Replace with your Raspberry Pi IP address

AsyncWebServer server(80);

// Root URL handler
void handleRoot(AsyncWebServerRequest *request) {
    String html = "<h1>ESP32 Node - Library Access</h1>"
                  "<a href='/library'>View Library</a><br>"
                  "<a href='/gallery'>Video Gallery</a><br>"
                  "<h2>Chat</h2>"
                  "<div id='chat-window'></div>"
                  "<input type='text' id='message-input' placeholder='Type your message...'>"
                  "<button onclick='sendMessage()'>Send</button>"
                  "<script>"
                  "function sendMessage() {"
                  "   const message = document.getElementById('message-input').value;"
                  "   fetch('/sendChat', { method: 'POST', body: JSON.stringify({ message: message }) })"
                  "       .then(response => response.text())"
                  "       .then(data => document.getElementById('chat-window').innerHTML += '<div>' + message + '</div>');"
                  "   document.getElementById('message-input').value = '';"
                  "}"
                  "</script>";
    request->send(200, "text/html", html);
}

// Handler for Library
void handleLibrary(AsyncWebServerRequest *request) {
    request->send(200, "text/html", "<h1>Loading Library...</h1>");
    // Make an HTTP request to Raspberry Pi to fetch library content and display it here
}

// Setup function
void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi");

    server.on("/", HTTP_GET, handleRoot);
    server.on("/library", HTTP_GET, handleLibrary);

    server.begin();
}

void loop() {
    // Placeholder for additional mesh logic
}
