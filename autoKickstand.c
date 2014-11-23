#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Hubs,  S2, HTServo,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,     IR,             sensorI2CCustom)
#pragma config(Sensor, S4,     gyro,           sensorI2CHiTechnicGyro)
#pragma config(Motor,  mtr_S1_C1_1,     leftFront,     tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     leftBack,      tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     rightFront,    tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     rightBack,     tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Servo,  srvo_S2_C1_1,    goalCapture,          tServoStandard)
#pragma config(Servo,  srvo_S2_C1_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "rpgCommon.c"
#include "IRsensor.c"
#include "fourWheelMovement.c"
#include "hitechnic-sensormux.h"     //Drivers for IR Beacon
#include "gyroSensor.c"
#include "gyroMovement.c"
#include "MovementCommon.c"
//#include "turnFunction.c"

//distances for finding the kickstand
#define pointA 50
#define pointB 120
#define pointC 150
/*#define pointD 10000*/
#define maxDistance 150
#define distanceA1 45.0
#define distanceA2 200.0
#define distanceD1 55.0
#define distanceD2 55.0
#define distanceC1 160.0
#define distanceC2 200.0
#define distanceB1 230.0
#define distanceB2 18.0
#define distanceB3 13.0
#define maxEncoder 5000


// Finds the IR and displays the encoders
float findIR(tSensors ir_seeker)
{
	resetEncoders();
	int	ir_value = getIRReading(ir_seeker);
	backward(50);
	wait1Msec(100);
	repeatUntil((ir_value == 2)||(ir_value == 3)||(abs(nMotorEncoder(leftFront))>maxEncoder))
	{
		wait1Msec(1);
		ir_value = getIRReading(ir_seeker);
	}
	stopMotors();
	int lfEnc = (abs(nMotorEncoder[leftFront]));// + abs(nMotorEncoder[rightFront])) / 2; broken
	int lbEnc = (abs(nMotorEncoder[leftBack]));// + abs(nMotorEncoder[rightFront])) / 2; brokein
	int rfEnc = (abs(nMotorEncoder[rightFront]));// + abs(nMotorEncoder[rightFront])) / 2;
	int rbEnc = (abs(nMotorEncoder[rightBack]));// + abs(nMotorEncoder[rightFront])) / 2;
	float avgEnc = (lfEnc + rfEnc) / 2.0;

	string text;
	sprintf(text, "lf enc=%i", lfEnc);
	displayCenteredTextLine(2, text);

	sprintf(text, "lb enc=%i", lbEnc);
	displayCenteredTextLine(3, text);

	sprintf(text, "rf enc=%i", rfEnc);
	displayCenteredTextLine(4, text);

	sprintf(text, "rb enc=%i", rbEnc);
	displayCenteredTextLine(5, text);

	sprintf(text, "avg enc = %f", avgEnc);
	displayCenteredTextLine(6, text);

	float distance = calculateDist(avgEnc);

	sprintf(text, "dist = %f", distance);
	displayCenteredTextLine(7, text);

	return distance;
}

void strategyA()//use if in position 1
{
	string text;
	sprintf(text, "Strategy A");
	displayCenteredTextLine(1, text);
	travelDistance(distanceA1);
	leftTurn(50);
	gyroTurn(90);
/*	leftTurn(50);
	wait1Msec(730);*/
	stopMotors();
	travelDistance(distanceA2);
	stopMotors();
}

void strategyD()//use if in position 1
{
	string text;
	sprintf(text, "Strategy D");
	displayCenteredTextLine(1, text);
	wait1Msec(200000000);
	leftTurn(50);
	gyroTurn(90);
	travelDistance(distanceD1);
	leftTurn(50);
	gyroTurn(90);
	travelDistance(distanceD2);
}

void strategyC()//use if in position 2
{
	string text;
	sprintf(text, "Strategy C");
	displayCenteredTextLine(1, text);
	leftTurn(50);
	gyroTurn(90);
	travelDistance(distanceC1);
	stopMotors();
	wait1Msec(500);
	rightTurn(50);
	gyroTurn(70);
	travelDistance(distanceC2);
	}

void strategyB()//use if in position 3
{
	string text;
	sprintf(text, "Strategy B");
	displayCenteredTextLine(1, text);
	/*travelDistance(distanceB1);*/
	leftTurn(50);
	gyroTurn(40);
	travelDistance(distanceB1);
	stopMotors();/*
	leftTurn(50);
	gyroTurn(90);
	travelDistance(distanceB3);*/
}

task main()
{
	disableDiagnosticsDisplay();
//	waitForStartOrButton();
	resetEncoders();
	string text;
	eraseDisplay();
	float travelled = abs(findIR(IR));
	wait1Msec(500);

	if(travelled <= pointA)
	{
		displayCenteredTextLine(2, "Strategy A");
		strategyA();
	}
	else if(travelled <= pointB)
	{
		displayCenteredTextLine(2, "Strategy B");
		strategyB();
	}

	else if(travelled <= pointC)
	{
		displayCenteredTextLine(2, "Strategy C");
		strategyC();
	}
/*	else if(travelled <= pointD)
	{
		displayCenteredTextLine(2, "Strategy D");
		strategyD();
	}
	wait1Msec(30000);*/
}
