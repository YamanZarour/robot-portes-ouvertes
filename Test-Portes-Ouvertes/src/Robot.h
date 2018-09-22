/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <string>

#include <SmartDashboard/SendableChooser.h>
#include <TimedRobot.h>
#include <Joystick.h>
#include <Spark.h>
#include <SpeedController.h>
#include <SpeedControllerGroup.h>
#include <Solenoid.h>
#include "C:\Users\lenovo i5 2\wpilib\user\cpp\include\ctre\Phoenix.h"
#include "C:\Users\lenovo i5 2\wpilib\cpp\current\include\Drive\DifferentialDrive.h"
#include "C:\Users\lenovo i5 2\wpilib\user\cpp\include\ctre\phoenix\MotorControl\CAN\WPI_TalonSRX.h"
#include <Timer.h>












//MAJEED WAS HERE






class Robot : public frc::TimedRobot {
public:
	void RobotInit() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
	void TestPeriodic() override;

private:
	Timer timer;

	double oldTime;
	double deltaTime;
	double soleCharge;
	double soleCooldown;

	WPI_TalonSRX motor0{0};
	WPI_TalonSRX motor1{1};
	WPI_TalonSRX motor2{2};
	WPI_TalonSRX motor3{3};

	Solenoid sole{0};

	frc::SpeedControllerGroup leftSide{motor0, motor1};
	frc::SpeedControllerGroup rightSide{motor2, motor3};

	DifferentialDrive Drive{leftSide, rightSide};

	frc::Joystick joystick0{0};
	frc::Joystick joystick1{1};


	frc::SendableChooser<std::string> m_chooser;
	const std::string kAutoNameDefault = "Default";
	const std::string kAutoNameCustom = "My Auto";
	std::string m_autoSelected;
};
