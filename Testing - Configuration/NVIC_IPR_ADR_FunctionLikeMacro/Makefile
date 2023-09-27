#Main application file name
MAIN_APP = main

# Compiler and other Section
CC = gcc

# Sources files needed for building the application 
Sfile = $(MAIN_APP).c
#Sfile += Linked_list.c
#Sfile += Output.c
#Sfile += Scheduling.c


# commands Section
all: $(MAIN_APP).exe $(MAIN_APP).o $(MAIN_APP).asm $(MAIN_APP).i

main.exe: $(Sfile)
	$(CC) $^ -o $@

main.o: $(MAIN_APP).c
	$(CC) -c $^ -o $@

main.asm: $(MAIN_APP).c
	$(CC) -S $^ -o $@

main.i: $(MAIN_APP).c
	$(CC) -E $^ -o $@
	
run:
	$(MAIN_APP).exe
	
clean:
	del *.exe *.o *.asm *.i