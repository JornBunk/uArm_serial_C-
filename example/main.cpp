/**
 * @file
 * @brief     The uArm module for PC
 * @author    Jorn Bunk
 */
#include "uArm.hpp"
#include <iostream>
#include <stdlib.h>     //for using the function sleep
#include "serial.hpp"
#include <windows.h>

int main() {
    uArm arm("\\\\.\\COM7", true);
	
	arm.moveWrist(90, 1);
	arm.moveWrist(60, 1);
	arm.moveWrist(120, 1);
	
	arm.move(150, 180, 100, 5);
	
	arm.turnPumpON();
	
	arm.move(250, -180,50, 5);
	
	arm.turnPumpOFF();
	
	arm.moveWrist(180, 5);
	
	arm.moveMotor(3,110,5);
	
	arm.move2rest();
}