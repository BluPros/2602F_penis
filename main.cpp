/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Drivetrain           drivetrain    1, 2, 3, 4, 5   
// Solenoid             digital_out   A               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;
  
// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  Drivetrain.setDriveVelocity(200, percent);
  Drivetrain.setTurnVelocity(100, percent);
  ShootSolenoid.set(false);
  TranSolenoid.set(true);
  Drivetrain.setHeading(0, degrees);

}

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
    Drivetrain.setDriveVelocity(50, percent);
    Drivetrain.setTurnVelocity(20, percent);
    Flywheel.setVelocity(200, percent);
    Intake.setVelocity(150,percent);
    Flywheel.spin(forward);
    wait(4, sec);
    ShootSolenoid.set(true);
    wait(0.5, sec);
    ShootSolenoid.set(false);
    wait(4, sec);
    ShootSolenoid.set(true);
    wait(0.5, sec);
    ShootSolenoid.set(false);
    wait(1, sec);
    Flywheel.stop();
    Drivetrain.driveFor(forward, 10, inches);
    wait(1, sec);
    Drivetrain.turnToHeading(-60, degrees);
    Intake.spin(forward);
    wait(1, sec);
    Drivetrain.setDriveVelocity(75, percent);
    Drivetrain.driveFor(forward, 40, inches);
    Intake.stop();
    Drivetrain.turnToHeading(40, degrees);

  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  int speed = 100;
  Intake.setVelocity(100, percent);
  Drivetrain.setDriveVelocity(100, percent);
  Drivetrain.setTurnVelocity(100, percent);
  Flywheel.setVelocity(200, percent);
  Intake.setVelocity(150,percent);
  // User control code here, inside the loop
  while (1) {
    Drivetrain.setDriveVelocity(200, percent);
    Drivetrain.setTurnVelocity(150, percent);
  vexcodeInit();
  if(Controller1.ButtonL1.pressing()){
    TranSolenoid.set(true);
  }else if(Controller1.ButtonR1.pressing()){
      TranSolenoid.set(false);
  }else{
  }
  if(Controller1.ButtonL2.pressing()){
    ShootSolenoid.set(true);
  }else if(Controller1.ButtonR2.pressing()){
      ShootSolenoid.set(false);
  }else{
  }
  if(Controller1.ButtonX.pressing()){
    Intake.spin(forward);
  }else if(Controller1.ButtonB.pressing()){
    Intake.stop();
  }else{ 
  }
  if(Controller1.ButtonUp.pressing()){
    Flywheel.spin(forward);
 
  }else if(Controller1.ButtonRight.pressing()){
    speed = speed+20;
    Flywheel.setVelocity(speed, percent);
  }else if(Controller1.ButtonLeft.pressing()){
    speed = speed-20;
    Flywheel.setVelocity(speed, percent);
  }else if(Controller1.ButtonDown.pressing()){
    Flywheel.stop();

    }
  }  
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
}

//
// Main will set up the competition functions and callbacks.
//
int main() {

  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
