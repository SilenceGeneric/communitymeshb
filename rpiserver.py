# rpi4server.py
from flask import Flask, render_template, request, jsonify
import os

app = Flask(__name__)

# Route for main library page
@app.route('/')
def home():
    return render_template('index.html')

# Library route to fetch and display files
@app.route('/library')
def library():
    # Fetch file list in library folder
    library_files = os.listdir('/home/pi/library')  # Ensure this path exists on your Pi
    return jsonify(files=library_files)

# Video Gallery route to fetch video files
@app.route('/gallery')
def gallery():
    video_files = os.listdir('/home/pi/gallery')  # Ensure this path exists on your Pi
    return jsonify(videos=video_files)

# Chat route to handle chat messages
@app.route('/chat', methods=['POST'])
def chat():
    message = request.json.get('message')
    # Log or handle message processing
    print("Received message:", message)
    return jsonify(success=True)

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)
