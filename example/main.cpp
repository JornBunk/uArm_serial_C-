/**
 * @file
 * @brief     The uArm module for PC
 * @author    Jorn Bunk
 */
#include "uArm.hpp"
#include "serial.hpp"

int main() {
    uArm arm("\\\\.\\COM12", true);
	
	arm.move(150, 180, 100, 5);
	arm.turnPumpON();
	arm.move(250, -180,50, 5);
	arm.turnPumpOFF();
	
	arm.moveWrist(180, 5); // only works when wrist is attached.
	
	arm.moveMotor(0,110,5);
	
	arm.move2rest();
}