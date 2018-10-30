/**
 * @file
 * @brief     The uArm module for PC
 * @author    Jorn Bunk
 */
#include "uArm.hpp"
#include "serial.hpp"

int main() {
    uArm arm("\\\\.\\COM7", true, 0);
	
	arm.move(250, 0, 100, 10);
	arm.turnPumpON();
	arm.move(200, 90,60, 10);
	arm.turnPumpOFF();

	arm.move(200, -30, 60, 30, 1); // move in a straight line
	//arm.moveWrist(30, 50); // only works when wrist is attached.
	
	arm.moveMotor(0,140,50);
	
	
	arm.move(200, 0, 60, 10);

	arm.move(200, 0, 0, 2, 0, true); //move and stop when the limit switch is triggered.
	
	
	arm.move(200, 0, 60, 10);  
	arm.move(200, 45, 60, 10); 
	
	arm.move2rest();
}