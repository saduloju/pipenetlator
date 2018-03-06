#
#         Make file for Project 1
#         Author: Sunday Aduloju
#         Last modified : 3/1/2018
C++  = g++
C++FLAGS =  -c -w
#
OBJECTS = scan.o  main.o messages.o trace.o nodal_data.o nodal_loads.o \
          read_project.o process_number.o process_reservoir.o   \
          parameters.o properties.o external.o convergence.o  
#
project1 : ${OBJECTS}
	 ${C++} $(OBJECTS) -o project1.go
#
#         list each source file and any dependencies
#
main.o: main.cc prototypes.h system.h arrays.h scanlib.h
read_project.o: read_project.cc prototypes.h system.h arrays.h scanlib.h
nodal_data.o: nodal_data.cc prototypes.h system.h arrays.h scanlib.h #
nodal_loads.o: nodal_loads.cc prototypes.h system.h scanlib.h   #
process_number.o: process_number.cc prototypes.h system.h arrays.h scanlib.h
process_reservoir.o: process_reservoir.cc prototypes.h system.h arrays.h scanlib.h
parameters.o: parameters.cc prototypes.h system.h arrays.h scanlib.h
properties.o: properties.cc prototypes.h system.h arrays.h scanlib.h
messages.o: messages.cc prototypes.h system.h arrays.h scanlib.h
trace.o: trace.cc prototypes.h system.h arrays.h scanlib.h
external.o: external.cc prototypes.h system.h arrays.h scanlib.h
convergence.o: convergence.cc prototypes.h system.h arrays.h scanlib.h
#
#
.SUFFIXES : .o .cc
.cc.o:
	/bin/rm -f $@
	$(C++) $(C++FLAGS) $<
