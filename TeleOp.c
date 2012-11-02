#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     fLeft,         tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     rLeft,         tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     fRight,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     rRight,        tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                           Tele-Operation Mode Code Template
//
// This file contains a template for simplified creation of an tele-op program for an FTC
// competition.
//
// You need to customize two functions with code unique to your specific robot.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.


/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                    initializeRobot
//
// Prior to the start of tele-op mode, you may want to perform some initialization on your robot
// and the variables within your program.
//
// In most cases, you may not have to add any code to this function and it will remain "empty".
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

void initializeRobot()
{
  // Place code here to sinitialize servos to starting positions.
  // Sensors are automatically configured and setup by ROBOTC. They may need a brief time to stabilize.

  return;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                         Main Task
//
// The following is the main code for the tele-op robot operation. Customize as appropriate for
// your specific robot.
//
// Game controller / joystick information is sent periodically (about every 50 milliseconds) from
// the FMS (Field Management System) to the robot. Most tele-op programs will follow the following
// logic:
//   1. Loop forever repeating the following actions:
//   2. Get the latest game controller / joystick settings that have been received from the PC.
//   3. Perform appropriate actions based on the joystick + buttons settings. This is usually a
//      simple action:
//      *  Joystick values are usually directly translated into power levels for a motor or
//         position of a servo.
//      *  Buttons are usually used to start/stop a motor or cause a servo to move to a specific
//         position.
//   4. Repeat the loop.
//
// Your program needs to continuously loop because you need to continuously respond to changes in
// the game controller settings.
//
// At the end of the tele-op period, the FMS will autonmatically abort (stop) execution of the program.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

task main()
{
  initializeRobot();

  waitForStart();   // wait for start of tele-op phase

  while (true)
  {
	  getJoystickSettings(joystick);
	  //controls: right analog stick controls robot movement
	  //					left analog stick controls lift, claw
	  // |x|<10 -> no turn
	  // |y|<10 -> no forward/reverse
	  // to turn: left motors forward, right motors reverse (or opposite)
	  // referring to positions at http://i.imgur.com/QwNXg.png
	  // 1 ->
	  // 2 -> left1&2, right 1&2 = joy1_y2
	  // 3 ->
	  // 4 -> left1&2 = -joy1_x2, right1&2 = joy1_x2
	  // 5 ->
	  // 6 -> left1&2 = joy1_x2, right1&2 = -joy1_x2
	  // 7 ->
	  // 8 -> left1&2, right 1&2 = joy1_y2
	  // 9 ->
	  if (abs(joystick.joy1_y1)>20) {
	  	startMotor(fLeft, (joystick.joy1_y1/128)*100);
	  	startMotor(rLeft, (joystick.joy1_y1/128)*100);
	  } else {
	  	stopMotor(fLeft);
	  	stopMotor(rLeft);
	  }
    if (abs(joystick.joy1_y2)>20) {
	  	startMotor(fRight, (joystick.joy1_y2/128)*100);
	  	startMotor(rRight, (joystick.joy1_y2/128)*100);
	  } else {
	  	stopMotor(fRight);
	  	stopMotor(rRight);
	  }
	  /*startMotor(left1,20);
	  startMotor(left2,20);
	  startMotor(right1,20);
	  startMotor(right2,20);
	  motor[fLeft]=joystick.joy1_y1;
	  motor[rLeft]=joystick.joy1_y1;
	  motor[fRight]=joystick.joy1_y2;
	  motor[rRight]=joystick.joy1_y2;*/

  }
}
