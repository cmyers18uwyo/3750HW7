##################################
#Makefile
#Charles Myers
#COSC 3750 Spring 2021
#Homework 7
#April 6, 2021
#
#This file will compile the  files for HW7
##################################
CC=gcc
CFLAGS=-ggdb -Wall
RM=/bin/rm -f
#tidy and clean are not files
.PHONY : tidy clean
#wytalk will use the wytalk files and create an executable called wytalk
wytalkD : wytalkD.c $(OBJS)
	$(CC) $(CFLAGS) -o wytalkd wytalkD.c socketfun.c $(OBJS)
wytalkC : wytalkC.c $(OBJS)
	$(CC) $(CFLAGS) -o wytalkc wytalkC.c socketfun.c $(OBJS)
#tidy will remove any object files in the directory
tidy :
	$(RM) *.o
#clean will run tidy and remove the executable approxe
clean : tidy
	$(RM) wytalk
