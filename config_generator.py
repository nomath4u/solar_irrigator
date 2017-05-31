#!/usr/bin/python

#print("test")

name = input("Input Adafruit username: ")
key = input("Input adafruit.io key: ")
home_ip = input("Input private MQTT Broker IP: ")
home_port = input("Input private MQTT Broker port: ")
home_user = input("Input private MQTT Broker user: ")
home_pass = input("Input priivate MQTT Broker password: ")

f = open("./irrigation.h", 'w')
print("#define AIO_USERNAME \"" + name +"\"",file=f)
print("#define AIO_KEY \"" + key +"\"",file=f)
print("#define HOME_SERVER \"" +home_ip +"\"",file=f)
print("#define HOME_SERVERPORT " +home_port ,file=f)
print("#define HOME_USERNAME \"" +home_user +"\"",file=f)
print("#define HOME_PASSWORD \"" +home_pass +"\"",file=f)
