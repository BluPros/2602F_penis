using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern smartdrive Drivetrain;
extern digital_out TranSolenoid;
extern digital_out ShootSolenoid;
extern motor_group Intake;
extern motor_group Flywheel;
extern inertial Inertials;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );
