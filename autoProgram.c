#pragma config(Sensor, S3,     IR,             sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S4,     gyro,           sensorI2CHiTechnicGyro)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorB,          leftFront,     tmotorNXT, PIDControl)
#pragma config(Motor,  motorC,          rightFront,    tmotorNXT, PIDControl)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "functions\AutoProgramQuestions.c"
#include "functions\twoWheelMovement.c"

task main()
{
	setBluetoothOff();

	bool check = false;
	int timeDelay;
	bool RPGKickStand;
	bool RPGStart;


	do
	{
		timeDelay = questionInt("Amount of delay", "left = -1 sec","right = +1 sec", 0 , 30);//asks the questions and sets RPGtime as the answer either true or false
		repeatUntil(nNxtButtonPressed == noButton)
		{}
		eraseDisplay();
		RPGStart = questionBool("r u starting:","left = floor","right = ramp");
		repeatUntil(nNxtButtonPressed == noButton)
		{}
		eraseDisplay();
		RPGKickStand = questionBool("do kickstand?","left = no","right = yes");
		repeatUntil(nNxtButtonPressed == noButton)
		{}
		eraseDisplay();

		string test1;// = "delay = " + timeDelay;
		string test2;// = RPGStart;
		string test3;// = "kickstand = " + RPGKickStand;

		sprintf(test1, "delay = %i", timeDelay);
		sprintf(test2, "location = %i", RPGStart);
		sprintf(test3, "Kickstand = %i", RPGKickStand);

		displayCenteredTextLine(1, "your values are:");
		displayCenteredTextLine(5,  test1);
		displayCenteredTextLine(6,  test2);
		displayCenteredTextLine(7, test3);

		check = questionBool("is this right","left = no","right = yes");
		repeatUntil(nNxtButtonPressed == noButton)
		{}
	}
	while (false == check);
	wait1Msec(5000);
	forward(50);
	wait1Msec(500);
	stopMotors();
	//eraseDisplay();
	forward(50);
  wait1Msec(500);
  stopMotors();
  turn(90, dRight);
}
