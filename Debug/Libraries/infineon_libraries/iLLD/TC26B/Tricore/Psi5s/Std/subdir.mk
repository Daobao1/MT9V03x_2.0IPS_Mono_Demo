################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/infineon_libraries/iLLD/TC26B/Tricore/Psi5s/Std/IfxPsi5s.c 

OBJS += \
./Libraries/infineon_libraries/iLLD/TC26B/Tricore/Psi5s/Std/IfxPsi5s.o 

COMPILED_SRCS += \
./Libraries/infineon_libraries/iLLD/TC26B/Tricore/Psi5s/Std/IfxPsi5s.src 

C_DEPS += \
./Libraries/infineon_libraries/iLLD/TC26B/Tricore/Psi5s/Std/IfxPsi5s.d 


# Each subdirectory must supply rules for building sources it contributes
Libraries/infineon_libraries/iLLD/TC26B/Tricore/Psi5s/Std/%.src: ../Libraries/infineon_libraries/iLLD/TC26B/Tricore/Psi5s/Std/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -D__CPU__=tc26xb "-fE:/17thzhinengche/MT9V03x_2.0IPS_Mono_Demo/Debug/TASKING_C_C___Compiler-Include_paths.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc26xb -o "$@"  "$<"  -cs --dep-file="$(@:.src=.d)" --misrac-version=2012 -N0 -Z0 -Y0 2>&1;
	@echo 'Finished building: $<'
	@echo ' '

Libraries/infineon_libraries/iLLD/TC26B/Tricore/Psi5s/Std/%.o: ./Libraries/infineon_libraries/iLLD/TC26B/Tricore/Psi5s/Std/%.src
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -o  "$@" "$<" --list-format=L1 --optimize=gs
	@echo 'Finished building: $<'
	@echo ' '

