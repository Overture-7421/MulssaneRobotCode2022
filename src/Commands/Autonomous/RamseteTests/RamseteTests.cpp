// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RamseteTests.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
RamseteTests::RamseteTests(Chassis* chassis) {
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
  
  AddCommands(
    chassis ->getRamseteCommand({

      {0_m, 0_m, 0_deg},
      {2_m, -1_m, 0_deg},
      {3_m, 0_m, 90_deg},
      {2_m, 1_m, 180_deg},
      {0_m, 0_m, 180_deg},
    },{3_mps, 1.5_mps_sq}),
    
    TurnToAngle(chassis, 0.0)
  );
}

/*
      {0_m, 0_m, 0_deg},
      {5.5_m, -1_m, 0_deg},
      {7_m, 0_m, 0_deg},
      {5.5_m, 1_m, 90_deg},
*/