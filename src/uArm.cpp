#include "uArm.hpp"

void uArm::move(int x, int y, int z, int speed){
		std::string command = 	"G0 X" + std::to_string(x) + " Y" + std::to_string(y) + 
												" Z" + std::to_string(z) + " F" + std::to_string(speed) +  "\n";
		performCommand(command);
}

void uArm::move2rest(){
	turnPumpOFF();
	moveWrist(90, 5);
	move(200, 0, 50, 10);
	move(101, 0, 40, 10);
	conn.writeData("M2019\n", 7); // detach motors
}

void uArm::turnPumpON(){
	performCommand("M2231 V1\n");
}

void uArm::turnPumpOFF(){
	performCommand("M2231 V0\n");
}

void uArm::moveWrist(int angle, int speed){
	moveMotor(3, angle, speed);
}

void uArm::moveMotor(int motor, int angle, int speed){
	performCommand("G2202 N" + std::to_string(motor) + " V" + std::to_string(angle) + " F" + std::to_string(speed) + "\n");
}

void uArm::setMode(int mode){
	performCommand("M2400 S" + std::to_string(mode) + "\n");
}

//private:
void uArm::waitDone(int command_number){
	conn.clearReadBuffer();
	conn.readData(response, response_size);
	while(!strstr(response, (std::to_string(command_number) + " ok").c_str())){
		conn.readData(response, response_size);
	}
	if(verbose){
		std::cout << response << "\n";
	}
}

void uArm::performCommand(const std::string & command){
		command_number++;
		std::string command_with_n = "#" + std::to_string(command_number) + " " + command;
		
		conn.writeData(command_with_n.c_str(), command_with_n.size());
		
		if(verbose){
			std::cout << command_with_n;
		}
		waitDone(command_number);
}
