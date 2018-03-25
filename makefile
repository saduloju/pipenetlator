#
#         Make file for Project 1
#         Author: Sunday Aduloju
#         Last modified : 3/9/2018
C++  = g++
C++FLAGS =  -c -w
#
OBJECTS = scan.o  main.o trace.o debug.o user_messages.o error_messages.o  read_project.o\
          process_number.o create_vectors.o vectors_free.o process_reservoir.o parameters.o \
          properties.o external.o initial_heads.o convergence.o linkup.o \
		  iterations.o output.o output_data.o output_results.o process_solve.o\
		  data_check.o solution_status.o solve_data.o compute_fvec.o compute_f.cc compute_Jmat.o compute_j.o\
		  solver.o compute_flows.o
#
project1 : ${OBJECTS}
	 ${C++} $(OBJECTS) -o project1.go
#
#         list each source file and any dependencies
#
main.o: main.cc prototypes.h header.h arrays.h scanlib.h
trace.o: trace.cc prototypes.h header.h arrays.h scanlib.h
debug.o: debug.cc prototypes.h header.h arrays.h scanlib.h
read_project.o: read_project.cc prototypes.h header.h arrays.h scanlib.h
process_number.o: process_number.cc prototypes.h header.h arrays.h scanlib.h
create_vectors.o: create_vectors.cc prototypes.h header.h arrays.h scanlib.h
vectors_free.o: vectors_free.cc prototypes.h header.h arrays.h scanlib.h
process_reservoir.o: process_reservoir.cc prototypes.h header.h arrays.h scanlib.h
parameters.o: parameters.cc prototypes.h header.h arrays.h scanlib.h
properties.o: properties.cc prototypes.h header.h arrays.h scanlib.h
error_messages.o: error_messages.cc prototypes.h header.h arrays.h scanlib.h
user_messages.o: user_messages.cc prototypes.h header.h arrays.h scanlib.h
external.o: external.cc prototypes.h header.h arrays.h scanlib.h
initial_heads.o: initial_heads.cc prototypes.h header.h arrays.h scanlib.h
convergence.o: convergence.cc prototypes.h header.h arrays.h scanlib.h
iterations.o: iterations.cc prototypes.h header.h arrays.h scanlib.h
output.o: output.cc prototypes.h header.h arrays.h scanlib.h 
output_data.o: output_data.cc prototypes.h header.h arrays.h scanlib.h 
output_results.o: output_results.cc prototypes.h header.h arrays.h scanlib.h 
process_solve.o: process_solve.cc prototypes.h header.h arrays.h scanlib.h
data_check.o: data_check.cc prototypes.h header.h arrays.h scanlib.h
solution_status.o: solution_status.cc prototypes.h header.h arrays.h scanlib.h
solve_data.o: solve_data.cc prototypes.h header.h arrays.h scanlib.h
linkup.o: linkup.cc prototypes.h header.h arrays.h scanlib.h 
compute_fvec.o: compute_fvec.cc prototypes.h header.h arrays.h scanlib.h
compute_f.o: compute_f.cc prototypes.h header.h arrays.h scanlib.h
compute_Jmat.o: compute_Jmat.cc prototypes.h header.h arrays.h scanlib.h
compute_j.o: compute_j.cc prototypes.h header.h arrays.h scanlib.h
solver.o: solver.cc prototypes.h header.h arrays.h scanlib.h
compute_flows.o: compute_flows.cc prototypes.h header.h arrays.h scanlib.h
#
#
.SUFFIXES : .o .cc
.cc.o:
	/bin/rm -f $@
	$(C++) $(C++FLAGS) $<
