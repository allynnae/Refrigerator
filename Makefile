#********************************************
#
# Makefile for CS2401 Project 3, Groceries
# Made by Kaeden Saunders, ks679318@ohio.edu
# Last updated 10/1/2023
# For automatic grading to work, do not change this file.
# Students are encouraged to read through to understand project requirements, however.
#
#********************************************

CC=g++
CFLAGS=-Wall -std=c++11
OBJECTS=_TEST/date_new.o _TEST/refrigerator.o _TEST/fooditem.o

a.out: date_new.o refrigerator.o fooditem.o
	$(CC) $(CFLAGS) main.cc $(OBJECTS) -o a.out

date_new.o: date_new.cc
	$(CC) $(CFLAGS) -c $< -o _TEST/$@

refrigerator.o: refrigerator.cc
	$(CC) $(CFLAGS) -c $< -o _TEST/$@

fooditem.o: fooditem.cc
	$(CC) $(CFLAGS) -c $< -o _TEST/$@

run_tests: date_new.o refrigerator.o fooditem.o oldandurgent itemcounts listbycat findall
	$(CC) $(CFLAGS) _TEST/TEST_cases.cc $(OBJECTS) -o _TEST/run_tests && ./_TEST/run_tests

oldandurgent:
	$(CC) $(CFLAGS) _TEST/oldandurgent.cc $(OBJECTS) -o _TEST/oldandurgent
	./_TEST/oldandurgent > _TEST/oldandurgent.txt.tmp

itemcounts:
	$(CC) $(CFLAGS) _TEST/itemcounts.cc $(OBJECTS) -o _TEST/itemcounts
	./_TEST/itemcounts > _TEST/itemcounts.txt.tmp

listbycat:
	$(CC) $(CFLAGS) _TEST/listbycat.cc $(OBJECTS) -o _TEST/listbycat
	./_TEST/listbycat > _TEST/listbycat.txt.tmp

findall:
	$(CC) $(CFLAGS) _TEST/findall.cc $(OBJECTS) -o _TEST/findall
	./_TEST/findall > _TEST/findall.txt.tmp


clean:
	rm -f _TEST/*.o a.out _TEST/run_tests _TEST/oldandurgent _TEST/itemcounts _TEST/listbycat _TEST/findall _TEST/*.txt.tmp _TEST/fridge_saved.txt

