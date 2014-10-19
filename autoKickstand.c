#pragma config(Sensor, S3,     IR,             sensorI2CCustom)
#pragma config(Sensor, S4,     gyro,           sensorI2CHiTechnicGyro)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorB,          leftFront,     tmotorNXT, PIDControl)
#pragma config(Motor,  motorC,          rightFront,    tmotorNXT, PIDControl)

//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
#include "JoystickDriver.c"
#include "twoWheelMovement.c"
#include "hitechnic-sensormux.h"     //Drivers for IR Beacon
#include "hitechnic-irseeker-v2.h"
#include "hitechnic-gyro.h"
#include "Common.c"
#include "IRsensor.c"
#include "gyroMovement.c"
#include "MovementCommon.c"
//#include "turnFunction.c"

#define pointA 3
#define pointB 8
#define pointC 15
#define pointD 20
#define distanceA1 36.0
#define distanceA2 24.0
#define distanceB1 23.0
#define distanceB2 10.0
#define distanceC1 15.0
#define distanceC2 13.0
#define distanceD1 3.0
#define distanceD2 18.0
#define distanceD3 13.0



float findIR(tSensors ir_seeker)
{
	int	ir_value = getIRReading(ir_seeker);
	repeatUntil(ir_value == 2)
	{
		backward(50);
		wait1Msec(1);
		ir_value = getIRReading(ir_seeker);
	}
	stopMotors();
	int encoderValue = (nMotorEncoder[leftFront] + nMotorEncoder[rightFront]) / 2;
	return calculateDist(encoderValue);
}

void strategyA()
{
	leftTurnDegrees(90, 50);
	travelDistance(distanceA1);
	leftTurnDegrees(90, 50);
	travelDistance(distanceA2);
}

void strategyB()
{
	leftTurnDegrees(90, 50);
	travelDistance(distanceB1);
	leftTurnDegrees(90, 50);
	travelDistance(distanceB2);
}

void strategyC()
{
	leftTurnDegrees(90, 50);
	travelDistance(distanceC1);
	rightTurnDegrees(45, 50);
	travelDistance(distanceC2);
}

void strategyD()
{
	travelDistance(distanceD1);
	leftTurnDegrees(90, 50);
	travelDistance(distanceD2);
	leftTurnDegrees(90, 50);
	travelDistance(distanceD3);
}

task main()
{
//	waitForStartOrButton();
	string text;
	eraseDisplay();
	float travelled = abs(findIR(IR));
	sprintf(text, "distance = %f", calculateDist(travelled));
	displayCenteredTextLine(1, text);

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
	else if(travelled <= pointD)
	{
		displayCenteredTextLine(2, "Strategy D");
		strategyD();
	}
}
