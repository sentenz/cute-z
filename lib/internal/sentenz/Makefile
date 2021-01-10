
LIB_PATH = ./bin/
GPIO_PATH = ./src/GPIO/
SENSOR_PATH = ./src/Sensor/
SENTENZ_PATH = ./src/Sentenz/
BOARD_PATH = ./src/UniPi/

SRC_PATH=src/
OBJ_PATH=obj/
BIN_PATH=bin/
INC_PATH=/usr/include/

CFLAGS = -I${INC_PATH}eigen3
CXXFLAGS = -std=c++1y
#-std=c++0x


ifeq "$(wildcard obj)" ""
	-include $(shell mkdir obj) $(wildcard obj/*)
endif

ifeq "$(wildcard bin)" ""
	-include $(shell bin) $(wildcard bin/*)
endif


LIBRARIES = sentenz

all: libsentenz.a

libsentenz.a: libGPIO.o libSensor.o libSentenz.o libBoard.o
	ar -rs ${BIN_PATH}libsentenz.a ${OBJ_PATH}libGPIO.o ${OBJ_PATH}libSensor.o ${OBJ_PATH}libSentenz.o ${OBJ_PATH}libBoard.o

libGPIO.o: ${GPIO_PATH}GPIO.cpp ${GPIO_PATH}GPIO.hpp ${GPIO_PATH}GPIOif2.cpp ${GPIO_PATH}GPIOif2.hpp
	g++ $(CXXFLAGS) -c ${GPIO_PATH}GPIO.cpp -o ${OBJ_PATH}GPIO.o ${GPIO_PATH}GPIOif2.cpp -o ${OBJ_PATH}GPIOif2.o -W -lpigpio -lrt -lpigpiod_if2

libSensor.o: ${SENSOR_PATH}HMC5883L.cpp ${SENSOR_PATH}HMC5883L.hpp ${SENSOR_PATH}VertX13.cpp ${SENSOR_PATH}VertX13.hpp
	g++ $(CXXFLAGS) -c ${SENSOR_PATH}HMC5883L.cpp -o ${OBJ_PATH}HMC5883L.o ${SENSOR_PATH}VertX13.cpp -o ${OBJ_PATH}VertX13.o -W -lpigpio -lrt -lpigpiod_if2

libSentenz.o: ${SENTENZ_PATH}IIR/Butterworth.cpp ${SENTENZ_PATH}Butterworth.hpp
	g++ $(CXXFLAGS) -c ${SENTENZ_PATH}IIR/Butterworth.cpp -o ${OBJ_PATH}Butterworth.o  $(CFLAGS) -W -lfftw3 -lm

libBoard.o: ${BOARD_PATH}UniSSR.cpp ${BOARD_PATH}UniSSR.hpp
	g++ $(CXXFLAGS) -c ${BOARD_PATH}UniSSR.cpp -o ${OBJ_PATH}UniSSR.o -W -lpigpio -lrt -lpigpiod_if2


install: libsentenz.a 
	

#---------------------------------------------------
# Demo
#---------------------------------------------------

ADC_VOICE : ${DEMO_PATH}Demo_ADC/ADC_voice.c libsentenz.a
	gcc -o ADC_VOICE ${DEMO_PATH}Demo_ADC/ADC_voice.c -L ${LIB_PATH} -lBBBio -lfftw3 -lm -pthread -O3 -Wall

	
#---------------------------------------------------
# Clean
#---------------------------------------------------

.PHONY: clean
clean :
	rm -rf ${LIB_PATH}*.o ${LIB_PATH}libBBBio.a libBBBio.a ADC_VOICE

