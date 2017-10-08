################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Mail.cpp \
../src/PostOffice.cpp \
../src/Postman.cpp \
../src/Test.cpp 

OBJS += \
./src/Mail.o \
./src/PostOffice.o \
./src/Postman.o \
./src/Test.o 

CPP_DEPS += \
./src/Mail.d \
./src/PostOffice.d \
./src/Postman.d \
./src/Test.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1y -I"/home/sofia/Documentos/teste_aeda/cute" -I"/home/sofia/Documentos/teste_aeda/boost" -O0 -g3 -Wall -c -fmessage-length=0 -Wno-attributes -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


