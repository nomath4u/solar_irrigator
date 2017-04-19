#!/usr/bin/python

#print("test")

name = input("Input username: ")
key = input("Input adafruit.io key: ")

f = open("./irrigation.h", 'w')
print("#define AIO_USERNAME " + name,file=f)
print("#define AIO_KEY " + key,file=f)
