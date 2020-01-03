#include "mode.h"
#include "Rover.h"

void ModeHold::update()
{
    float throttle = 0.0f;
    float brake = 100.0f;

    // if vehicle is balance bot, calculate actual throttle required for balancing
    if (rover.is_balancebot()) {
        rover.balancebot_pitch_control(throttle);
        brake = 0;
    }

    // relax mainsail
    g2.motors.set_mainsail(100.0f);

    // hold position - stop motors and center steering
    rover.set_throttle(throttle);
    rover.set_brake(brake);
    set_steering(0.0f);
}
