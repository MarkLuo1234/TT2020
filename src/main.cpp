#include "main.h"
//setup everything
pros::ADIButton limitswitch (1);
pros::ADIButton limitswitch2 (8);
pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Motor LFM(1, true); //left front
pros::Motor RFM(2); //right front
pros::Motor LBM(3, true); //left back
pros::Motor RBM(4); //right back
pros::Motor LLFT(6, true); //left lift
pros::Motor RLFT(5); //right lift
pros::Motor UCLW(7, true); //upper claw
pros::Motor DCLW(8); //down claw

pros::Motor CBLINE(9); //cubeline
//set up sensor
bool name = false;
void LimitSwitch(void*){
while (true) {
if (limitswitch.get_value() ==1 && limitswitch2.get_value() ==1){
name = true;
}
if (name){
LLFT.move_absolute(600, 127);
RLFT.move_absolute(600, 127);
pros::delay(800);
LLFT.move_absolute(-900, 127);
RLFT.move_absolute(-900, 127);
pros::delay(900);
name = false;
}
pros::delay(20);
}
}

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {

}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {

}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {


}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
//auton no loop
/*4 point red autonomous
  LBM.move_absolute(-1000, 100);
  RBM.move_absolute(-1000, 100);
  LFM.move_absolute(-1000, 100);
  RFM.move_absolute(-1000, 100);
  pros::delay(1000);
  LBM.move_relative(620, 100);
  LFM.move_relative(620, 100);
  RBM.move_relative(-620, 100);
  RFM.move_relative(-620, 100);
  pros::delay(1500);
  DCLW.move(100);
  UCLW.move(100);
  pros::delay(500);
  LBM.move_relative(940, 25);
  RBM.move_relative(940, 25);
  LFM.move_relative(940, 25);
  RFM.move_relative(940, 25);
  pros::delay(3500);
  DCLW.move(0);
  UCLW.move(0);
  pros::delay(500);
  LLFT.move_relative(-1000, 100);
  RLFT.move_relative(-1000, 100);
  pros::delay(600);
  LBM.move_relative(-1300, 100);
  LFM.move_relative(-1300, 100);
  RBM.move_relative(-1300, 100);
  RFM.move_relative(-1300, 100);
  pros::delay(1000);
  LBM.move_relative(-550, 25);
  LFM.move_relative(-550, 25);
  RBM.move_relative(550, 25);
  RFM.move_relative(550, 25);
  pros::delay(2000);
  LBM.move_relative(1650, 80);
  LFM.move_relative(1650, 80);
  RBM.move_relative(1650, 80);
  RFM.move_relative(1650, 80);
  pros::delay(2200);
  LLFT.move_relative(1200, 80);
  RLFT.move_relative(1200, 80);
  pros::delay(700);
  UCLW.move(127);
  DCLW.move(127);
  pros::delay(500);
  LBM.move_relative(-1000, 127);
  LFM.move_relative(-1000, 127);
  RBM.move_relative(-1000, 127);
  RFM.move_relative(-1000, 127);
  pros::delay(2000);
*/
/* 4 point blue autonomous
LBM.move_absolute(-800, 100);
RBM.move_absolute(-800, 100);
LFM.move_absolute(-800, 100);
RFM.move_absolute(-800, 100);
pros::delay(1000);
LBM.move_relative(-620, 100);
LFM.move_relative(-620, 100);
RBM.move_relative(620, 100);
RFM.move_relative(620, 100);
pros::delay(1500);
DCLW.move(100);
UCLW.move(100);
pros::delay(500);
LBM.move_relative(900, 25);
RBM.move_relative(900, 25);
LFM.move_relative(900, 25);
RFM.move_relative(900, 25);
pros::delay(3500);
DCLW.move(0);
UCLW.move(0);
pros::delay(500);
LLFT.move_relative(-1200, 100);
RLFT.move_relative(-1200, 100);
pros::delay(1000);
LBM.move_relative(-1500, 50);
LFM.move_relative(-1500, 50);
RBM.move_relative(-1500, 50);
RFM.move_relative(-1500, 50);
pros::delay(1700);
LBM.move_relative(550, 50);
LFM.move_relative(550, 50);
RBM.move_relative(-550, 50);
RFM.move_relative(-550, 50);
pros::delay(1000);
LBM.move_relative(1500, 80);
LFM.move_relative(1500, 80);
RBM.move_relative(1500, 80);
RFM.move_relative(1500, 80);
pros::delay(2000);
LLFT.move_relative(1200, 75);
RLFT.move_relative(1200, 75);
pros::delay(700);
UCLW.move(127);
DCLW.move(127);
pros::delay(500);
LBM.move_relative(-1000, 127);
LFM.move_relative(-1000, 127);
RBM.move_relative(-1000, 127);
RFM.move_relative(-1000, 127);
pros::delay(2000);
*/
// 1 point
pros::Task task1(LimitSwitch, nullptr, "blah");
  LBM.move_absolute(-1000, 100);
  RBM.move_absolute(-1000, 100);
  LFM.move_absolute(-1000, 100);
  RFM.move_absolute(-1000, 100);
  pros::delay(1500);
  LBM.move_absolute(1000, 100);
  RBM.move_absolute(1000, 100);
  LFM.move_absolute(1000, 100);
  RFM.move_absolute(1000, 100);
  pros::delay(1500);




}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */


void opcontrol() {
//controls 
RLFT.set_zero_position(0);
LLFT.set_zero_position(0);
pros::Task task1(LimitSwitch, nullptr, "blah");
DCLW.set_zero_position(0);
CBLINE.set_zero_position(0);

while (true) {
LFM.move(master.get_analog(ANALOG_LEFT_Y));
LBM.move(master.get_analog(ANALOG_LEFT_Y));
RFM.move(master.get_analog(ANALOG_RIGHT_Y));
RBM.move(master.get_analog(ANALOG_RIGHT_Y));


if(RLFT.get_position() <= -1500 && LLFT.get_position() <= -1500)
{
CBLINE.move_absolute(275, 100);
}
if(master.get_digital(DIGITAL_L1)) {
UCLW.move_absolute(100, 75);
DCLW.move_absolute(100, 75);
}
else if (master.get_digital(DIGITAL_L2)) {
UCLW.move_absolute(100, 75);
DCLW.move_absolute(100, 75);
}
else{
DCLW.move(0);
UCLW.move(0);
}

if(master.get_digital(DIGITAL_R1)) {
RLFT.move(127);
LLFT.move(127);
UCLW.move(127);
}
else if (master.get_digital(DIGITAL_R2)) {
RLFT.move(-127);
LLFT.move(-127);
UCLW.move(-127);
}
else if (limitswitch.get_value() ==0 && limitswitch2.get_value() ==0 && master.get_digital(DIGITAL_R1) ==0 && master.get_digital(DIGITAL_R2) ==0 && !name){
RLFT.move_velocity(0);
LLFT.move_velocity(0);
UCLW.move_velocity(0);
}
if(master.get_digital(DIGITAL_X)) {
CBLINE.move_absolute(-450, 100);
}
else if(master.get_digital(DIGITAL_A)) {
CBLINE.move_absolute(275, 100);
}
RLFT.set_brake_mode(MOTOR_BRAKE_HOLD);
LLFT.set_brake_mode(MOTOR_BRAKE_HOLD);
    CBLINE.set_brake_mode(MOTOR_BRAKE_HOLD);
pros::delay(20);
}
}
