#include "v5.h"
#include "v5_vcs.h"
#include "MiniPID.h"

using namespace vex;

extern brain Brain;
extern controller Controller;

//Right
extern motor front_right;
extern motor mid_right;
extern motor back_right(PORT3, ratio18_1);

//Left
extern motor front_left;
extern motor mid_left;
extern motor back_left;

//Drive Groups
extern motor_group right_drive;
extern motor_group left_drive;

extern motor_group DT;

extern MiniPID drivePID_Left;
extern MiniPID drivePID_Right;

extern MiniPID turnPID;