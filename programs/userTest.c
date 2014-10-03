#pragma config(Hubs,  S1, HTMotor,  none,     none,     none)
#pragma config(Hubs,  S2, HTMotor,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     leftFront,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     leftBack,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_1,     rightFront,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_2,     rightBack,      tmotorTetrix, openLoop)

//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*This is a set of movement functions.  Goals: make the robot go forward, backwards, turn,
and go to the side.  */
#include "JoystickDriver.c"
#include "functions\fourWheelMovement.c"

task main()
{
	while(true)
	{
		getJoystickSettings(joystick);  // Update Buttons and Joysticks
		setMotion(joystick.joy1_y1, joystick.joy1_y2);
	}
}