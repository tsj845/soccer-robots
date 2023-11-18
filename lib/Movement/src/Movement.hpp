#include "zirconLib.h"
#include "Positioning.hpp"

namespace Movement {
    double U1 = 0.8660254037844386467;
    double U2 = 0.5;
    vector2 U = vector2(U1, U2);

    double V1 = 0.8660254037844386467;
    double V2 = -0.5;
    vector2 V = vector2(V1, V2);

    double W1 = -0.0;
    double W2 = 1.0;
    vector2 W = vector2(W1, W2);

    double m1, m2, m3, x1, x2;

    int move_flags = 0;

    double target_x, target_y; // for moveToPoint

    double tolerance = 5;

    // does unchecked moves, prevents rechecking flags
    void imoveInDirection(double angle) {
        x1 = cos(angle);
        x2 = sin(angle);

        m1 = x1*U1+x2*U2;
        m2 = x1*V1+x2*V2;
        m3 = x1*W1+x2*W2;

        motor1(abs(m1*100), m1 < 0);
        motor2(abs(m2*100), m2 < 0);
        motor3(abs(m3*100), m3 < 0);
    }
    
    /**
     * @brief moves the bot in the specified direction, will not move if `stopMovement` was invoked with a non-zero `restart` parameter
     * @param angle direction to move in
     */
    // void moveInDirection(double angle) {
    //     if (move_flags & 2) {
    //         return;
    //     }
    //     imoveInDirection(angle);
    // }
    const double speed = 100;
    void moveInDirection(vector2 direction) {
        m1 = direction.dot(&U);
        m2 = direction.dot(&V);
        m3 = direction.dot(&W);
        motor1(abs(m1*speed), m1 < 0);
        motor2(abs(m2*speed), m2 < 0);
        motor3(abs(m3*speed), m3 < 0);
    }
    
    /**
     * @brief sets all motor speeds to `0`
     */
    void stopMovement() {
        motor1(0, 0);
        motor2(0, 0);
        motor3(0, 0);
    }

    /**
     * @brief sets all motor speed to `0` and provides option to prevent restarting them
     * @param restart if non-zero, prevent motors from being started using the functions defined here
     */
    void stopMovement(int restart) {
        if (restart) {
            move_flags |= 0b10;
        }
        stopMovement();
    }

    void clearFlag(int flag) {
        if (flag > 7) {
            return;
        }
        move_flags &= !(1<<flag);
    }

    /**
     * @brief checks if the value is within bot tolerance
     * @param p value to check
     * @return `0` if not within tolerance, else `1`
     */
    int withinTolerance(vector2* p) {
        if (p->magnitude() < tolerance) {
            return 1;
        }
        return 0;
    }

    /**
     * @brief moves the bot to the target, uses `withinTolerance` to check if the target has already been reached
     * @return `1` when bot reaches target, else `0`
     */
    int moveToPoint(vector2* target) {
        if (move_flags & 2) { // not strictly necessary, but will prevent unnecessary calculations
            return;
        }
        vector2 p = getPosition() - target;
        if (withinTolerance(&p)) {
            return 1;
        }
        moveInDirection(p);
        return 0;
    }
}

// using Movement::moveInDirection;
using Movement::stopMovement;
using Movement::moveToPoint;
using Movement::withinTolerance;
using Movement::clearFlag;