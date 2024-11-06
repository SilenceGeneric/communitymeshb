Project Structure

    ESP32 Nodes: Each ESP32 acts as a node in a mesh network, connecting to the Raspberry Pi's WiFi to access the library and services. Each ESP32 will serve a basic interface to access the library and chat functionality.
    Raspberry Pi 4 Server: Acts as the main server with a web interface for a library, video gallery, and chat, accessible by ESP32 nodes, laptops, and phones.

Requirements:

    ESP32 Node Code: ESP32 setup for connecting to the Raspberry Pi server and displaying content.
    Raspberry Pi 4 Server Code: Using Python (Flask) for a web interface with endpoints for library, video gallery, and chat functionalities.
