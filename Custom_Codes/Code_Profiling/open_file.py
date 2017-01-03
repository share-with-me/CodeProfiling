#!/usr/bin/python

#Code to take in the file name from the user and ouput it on the console or process it accordingly.

print "\nPlease enter the name of the file you want to open!\n"
name = raw_input()

try:
	fname = open(name, "r")
except IOError:
	print "\nFile does not exist. Aborting!\n"
	exit(0)

content = fname.read()
print content