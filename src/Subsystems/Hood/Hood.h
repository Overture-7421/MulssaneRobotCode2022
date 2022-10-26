// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/DigitalInput.h>
#include <ctre/phoenix/motorcontrol/can/TalonSRX.h>

class Hood : public frc2::SubsystemBase {
 public:
  Hood();

  bool getSwitch(){
    if (hoodSwitch.Get() == 0){
      return true; 
    }else{
      return false;
    }
  }

  void voltageMotor(){

    hoodMotor.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0.5);
  }

  void NevoltageMotor(){

    hoodMotor.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, -0.5);
  }

  void NovoltageMotor(){

    hoodMotor.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0);
  }

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
 frc::DigitalInput hoodSwitch {2};
 ctre::phoenix::motorcontrol::can::TalonSRX hoodMotor {9};

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};


