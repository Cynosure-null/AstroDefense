// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <string>

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>

#include <frc/motorcontrol/MotorControllerGroup.h>
#include "frc/drive/RobotDriveBase.h"
#include "frc/drive/DifferentialDrive.h"
#include <frc/XboxController.h>
#include "rev/CANSparkMax.h"

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void TestInit() override;
  void TestPeriodic() override;

 private:
  frc::XboxController m_stick{0};

  static const int frontLeftMotorDeviceID = 1;
  //static const int midLeftMotorDeviceID = 2;
  static const int backLeftMotorDeviceID = 2;
  static const int frontRightMotorDeviceID = 3;
  //static const int midRightMotorDeviceID = 5;
  static const int backRightMotorDeviceID = 4;

  rev::CANSparkMax m_frontLeftMotor{frontLeftMotorDeviceID, rev::CANSparkMax::MotorType::kBrushless};
  //rev::CANSparkMax m_midLeftMotor{midLeftMotorDeviceID, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_backLeftMotor{backLeftMotorDeviceID, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_frontRightMotor{frontRightMotorDeviceID, rev::CANSparkMax::MotorType::kBrushless};
  //rev::CANSparkMax m_midRightMotor{midRightMotorDeviceID, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_backRightMotor{backRightMotorDeviceID, rev::CANSparkMax::MotorType::kBrushless};

  rev::SparkMaxRelativeEncoder m_frontLeftMotorEncoder = m_frontLeftMotor.GetEncoder();
  //rev::SparkMaxRelativeEncoder m_midLeftMotorEncoder = m_midLeftMotor.GetEncoder();
  rev::SparkMaxRelativeEncoder m_backLeftMotorEncoder = m_backLeftMotor.GetEncoder();
  rev::SparkMaxRelativeEncoder m_frontRightMotorEncoder = m_frontRightMotor.GetEncoder();
  //rev::SparkMaxRelativeEncoder m_midRightMotorEncoder = m_midRightMotor.GetEncoder();
  rev::SparkMaxRelativeEncoder m_backRightMotorEncoder = m_backRightMotor.GetEncoder();


  frc::MotorControllerGroup m_leftDrive{m_frontLeftMotor, m_backLeftMotor};
  frc::MotorControllerGroup m_rightDrive{m_frontRightMotor, m_backRightMotor};

  frc::DifferentialDrive m_drive{m_leftDrive, m_rightDrive};

  //frc::SendableChooser<std::string> m_chooser;
  //const std::string kAutoNameDefault = "Default";
  //const std::string kAutoNameCustom = "My Auto";
  //std::string m_autoSelected;
};
