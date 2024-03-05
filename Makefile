# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall

# Source files
SOURCES = driver.cpp animations.cpp \
		  Disk_Scheduling/disk_driver.cpp \
		  Disk_Scheduling/Clook.cpp \
		  Disk_Scheduling/Cscan.cpp \
		  Disk_Scheduling/Fcfs.cpp \
		  Disk_Scheduling/Look.cpp \
		  Disk_Scheduling/Scan.cpp \
		  Memory_Management/memory_driver.cpp \
		  Memory_Management/mft/mft_driver.cpp \
		  Memory_Management/mvt/mvt_driver.cpp \
		  Memory_Management/mvt/bestfit.cpp \
		  Memory_Management/mvt/worstfit.cpp \
		  Memory_Management/mvt/firstfit.cpp \
		  Memory_Management/page_replacement/paging_driver.cpp \
		  Process_Synchronization/proc_sync_driver.cpp \
		  Process_Synchronization/barbershop.cpp \
		  Process_Synchronization/dining_philsophers.cpp \
		  Process_Synchronization/producer_consumer.cpp \
		  Process_Synchronization/reader_writer.cpp \
		  Process_Scheduling/proc_sched_driver.cpp \
		  Process_Scheduling/FCFS.cpp \
		  Process_Scheduling/HRRF.cpp \
		  Process_Scheduling/LJF.cpp \
		  Process_Scheduling/LRTF.cpp \
		  Process_Scheduling/Priority_non.cpp \
		  Process_Scheduling/Priority.cpp \
		  Process_Scheduling/RR.cpp \
		  Process_Scheduling/SJF.cpp \
		  Process_Scheduling/SRTF.cpp \
		  Process_Scheduling/utilities.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Executable
EXECUTABLE = my_os_simulator

# Compile and link
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@

# Compile source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
