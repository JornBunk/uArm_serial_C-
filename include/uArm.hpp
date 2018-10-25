#ifndef UARM_HPP
#define UARM_HPP

#include <string>
#include <iostream>
#include <stdlib.h>     //for using the function sleep
#include "serial.hpp"
#include <windows.h>


class uArm
{
private:
Serial conn;
bool verbose;
const int response_size = 1024; // same size as Serial uses.
char response[1024]; // 1024 == response_size -> in macro?
char command_number = 0; // to be used in communication with the uARM. command_number++ -> to get a new unique (enough) number

/**
 * @brief waits till there comes a message that the command is done ("OK")
 *
 * @param command_number
 */
void waitDone(int command_number);

/**
 * @brief sends the command to the uArm and waits till its done.
 *
 * @param command_number
 */
void performCommand(const std::string & command);

public:
	uArm(const char * com, const bool & verbose = true, int mode = 0):
		conn(com), verbose(verbose)
	{
		if(verbose){
			for(int i =0; i<5; i++){
				conn.readData(response, response_size);
				std::cout << response << "\n";
			}
		}
		setMode(mode);
	}
	
	/**
     * @brief moves the arm to the given coordinate
     *
	 * When an illegal position is given the arm will stop moving.
	 * 
     * @param x
	 * @param y
	 * @param z
     * @param speed (0 ~200)
     */
	void move(int x, int y, int z, int speed);
	
	/**
     * @brief moves the arm to the rest position.
     *
	 * Always end your code with this function!
	 * Rest position is defend coordinates (101, 0, 40) with the pump off and the wrist on 90 degrees.
     *
     */
	void move2rest();
	
	/**
     * @brief turns the pump on
     *
     */
	void turnPumpON();
	
	/**
     * @brief turns the pump off
     *
     */
	void turnPumpOFF();
	
	/**
     * @brief moves the wrist. 
     *
	 * The speed parameters seems to have no effect.
	 * When an illegal position is given the arm will stop moving.
	 * Note that you have to connect the uArm wrist seperately. Default it is screwed to the suction cup.
	 * 
     * @param angle (0 ~180)
     * @param speed (0 ~200)
     */
	void moveWrist(int angle, int speed);

	/**
     * @brief moves a specific motor. 
     *
	 * The speed parameters seems to have no effect on motor 3.
	 * When an illegal position is given the arm will stop moving.
	 * Note that you have to connect the uArm wrist (motor 3) seperately. Default it is screwed to the suction cup.
	 * 
     * @param angle (0 ~ 180)
     * @param speed (0 ~200)
     */
	void moveMotor(int motor, int angle, int speed);
	
	/**
     * @brief sets the mode of the uArm 
     *
	 * 0: Standard Suction Mode
	 * 1: Laser Mode
	 * 2: 3D printing Mode
	 * 3: Universal Holder Mode
	 * 4: Pro Suction Mode
	 * 5: Plus Suction Mode
	 * 6: Touch Pen Mode
	 * 
     * @param mode (0 ~ 6)
     */
	void setMode(int mode);
	
};

#endif // UARM_HPP
