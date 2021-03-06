// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Center_SingleBallAuto.h"

#include <frc2/command/InstantCommand.h>
#include <frc2/command/ParallelCommandGroup.h>
#include <frc2/command/ParallelDeadlineGroup.h>
#include <frc2/command/ParallelRaceGroup.h>
#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/WaitCommand.h>
#include <frc2/command/PerpetualCommand.h>

#include "Commands/Autonomous/TurnToAngle/TurnToAngle.h"
#include "Commands/Common/PreloadBall/PreloadBall.h"
#include "Commands/Common/SetIntake/SetIntake.h"
#include "Commands/Common/SetShooter/SetShooter.h"
#include "Commands/Common/SetStorageAndDeliver/SetStorageAndDeliver.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
Center_SingleBallAuto::Center_SingleBallAuto(Chassis* chassis, VisionManager* visionManager,
                               Intake* intake,
                               StorageAndDeliver* storageAndDeliver,
                               Shooter* shooter) {
  // Add your commands here, e.g.
  AddCommands(frc2::InstantCommand(
                  [chassis = chassis, visionManager = visionManager] {
                    chassis->resetOdometry({5.96_m, 5.0_m, 180_deg});
                    visionManager->setLeds(false);
                  },
                  {chassis}),
              frc2::ParallelDeadlineGroup(
                  frc2::SequentialCommandGroup(
                      SetIntake(intake, 12, false),
                      chassis->getRamseteCommand(
                          {{5.96_m, 5.0_m, 180_deg}, {4.9_m, 5.0_m, 180_deg}},
                          {2.5_mps, 2.5_mps_sq}),
                      SetShooter(shooter, 390, true), frc2::WaitCommand(0.1_s),
                      SetIntake(intake, 12, false), frc2::WaitCommand(0.5_s),
                      SetIntake(intake, 0, false)),
                  PreloadBall(storageAndDeliver).Perpetually()),

              frc2::InstantCommand([visionManager = visionManager] {
                visionManager->setLeds(true);
              }), AlignToTower(chassis, visionManager),
              AutoShoot(chassis, storageAndDeliver, visionManager, 1)

  );








}


