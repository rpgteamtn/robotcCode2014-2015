#pragma config(Sensor, S3,     sonar,          sensorSONAR)
#pragma config(Sensor, S4,     gyro,           sensorI2CHiTechnicGyro)
#pragma config(Motor,  motorA,          rightFront,    tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          leftFront,     tmotorNXT, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "rpgCommon.c"
#include "twoWheelMovement.c"
#include "gyroSensor.c"
#include "sonarSensor.c"

task main()
{
	wait1Msec(500);
	findGoal(100);
	stopMotors();
	wait1Msec(500);
	approach(15);
}
