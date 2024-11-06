#!/bin/bash

# Setup script for Raspberry Pi server with Flask

# Step 1: Update and upgrade the system
echo "Updating and upgrading system packages..."
sudo apt update && sudo apt upgrade -y

# Step 2: Install Python 3 and pip
echo "Installing Python3 and pip3..."
sudo apt install -y python3 python3-pip

# Step 3: Install Flask and dependencies
echo "Installing Flask and dependencies..."
sudo pip3 install Flask

# Optional: Set up a virtual environment for the project
echo "Setting up a virtual environment..."
python3 -m venv rpi_server_env
source rpi_server_env/bin/activate

# Install dependencies within virtual environment
pip install Flask

# Step 4: Copy `rpi4server.py` to the project directory
echo "Copying rpi4server.py to /home/pi/project..."
mkdir -p /home/pi/project
cp rpi4server.py /home/pi/project/rpi4server.py

# Step 5: Set executable permissions for `rpi4server.py`
chmod +x /home/pi/project/rpi4server.py

# Step 6: Add a run command in a shell script to start the server
echo "Creating start_server.sh script..."
echo "#!/bin/bash
source /home/pi/project/rpi_server_env/bin/activate
python3 /home/pi/project/rpi4server.py" > /home/pi/project/start_server.sh
chmod +x /home/pi/project/start_server.sh

# Step 7: Inform the user
echo "Setup complete. To start the server, run:"
echo "    /home/pi/project/start_server.sh"
