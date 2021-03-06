#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Hubs,  S2, HTServo,  HTMotor,  none,     none)
#pragma config(Sensor, S3,     gyro,           sensorI2CHiTechnicGyro)
#pragma config(Sensor, S4,     HTSMUX,         sensorI2CCustom)
#pragma config(Motor,  mtr_S1_C1_1,     leftFront,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     leftBack,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     liftMotor,     tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     spinner,       tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S2_C2_1,     rightFront,    tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S2_C2_2,     rightBack,     tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Servo,  srvo_S2_C1_1,    spinnerServo,         tServoStandard)
#pragma config(Servo,  srvo_S2_C1_5,    tipperServo,          tServoStandard)
#pragma config(Servo,  srvo_S2_C1_6,    goalCapture,          tServoStandard)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define MUX1 		 msensor_S4_1 //Definitions for mux sensors
#define touch 	 msensor_S4_2
#define sonar    msensor_S4_3

#include "IRsensor.c" //IR functions
#include "fourWheelMovement.c" //Big robot movement functions
#include "liftFunctions.c" //Lift and spinner functions
#include "gyroSensor.c" //gyro functions
#include "MovementCommon.c" //Math or calculation functions
#include "sonarSensor.c" //Sonar functions
#include "autoProgramQuestions.c" //Question functions
#include "servoFunctions.c" //servo functions
#include "autoFloor.c"
#include "autoKickstand.c"

task main()
{
	disableDiagnosticsDisplay();
/*
motor[leftFront] = 50;
	wait1Msec(1000);
	motor[leftFront] = 0;
	motor[rightFront] = 50;
	wait1Msec(1000);
	motor[rightFront] = 0;
	motor[leftBack] = 50;
	wait1Msec(1000);
	motor[leftBack] = 0;
	motor[rightBack] = 50;
	wait1Msec(1000);
	motor[rightBack] = 0;
*/
 //travelDistance(45, dForward);
	//gyroTurn(50, 35, dLeft);
forward(75);
wait1Msec(1000);
stopMotors();
	displayCenteredTextLine(1, "lf = %i", nMotorEncoder[leftFront]);
	displayCenteredTextLine(2, "lb = %i", nMotorEncoder[leftBack]);
	displayCenteredTextLine(3, "rf = %i", nMotorEncoder[rightFront]);
	displayCenteredTextLine(4, "rb = %i", nMotorEncoder[rightBack]);
	wait1Msec(30000);
}
