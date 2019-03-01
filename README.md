# IoT_PanicButton
This is a minimal project to connect an IoT button with a server that stores alerts and could trigger another actions. I've used 
M5Stack &amp; Raspberry: M5Stack makes HTTP request for a nodejs microservice deployed on Raspberry to trigger some action. 

*M5Stack* is an Arduino development stack (more info here: https://github.com/m5stack) and could be replaced with ESP32+button or Arduino+Button+WiFi module.

*Raspberry* is mini pc board (https://www.raspberrypi.org/)

*Real life applications:*
This project is a base for multiple solutions/options. I used it to generate notifications in my Android device from IoT events. I have extended the raspberry nodejs microserver script to store requests in a cloud database and I've made an Android app with a service listener for these alerts creation in database (I've used Firebase as Cloud backend for the database, https://firebase.google.com/). You can extend the nodejs microservice for Raspberry to store or trigger whatever you want. And also you can extend the M5Stack script to raise the alert by any other event instead of button click.





