/**
 * @file
 * @brief     The uArm module for PC
 * @author    Jorn Bunk
 */
#include "uArm.hpp"
#include "serial.hpp"

int main() {
    uArm arm("\\\\.\\COM12", true);
	
	arm.move(200, 0, 50, 10);
	arm.turnPumpON();
	arm.move(120, 90,60, 10);
	arm.turnPumpOFF();
	
	arm.move(120, 30, 60, 10, 1); // move in a straight line
	arm.moveWrist(180, 50); // only works when wrist is attached.
	
	arm.moveMotor(0,140,50);
	
	arm.move2rest();
}