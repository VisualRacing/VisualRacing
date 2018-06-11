# Use-Case Specification: Analyze Acceleration Behavior

# Table of Contents
- [Analyze Acceleration Behavior](#1-analyze-acceleration-behavior)
    - [Brief Description](#11-brief-description)
    - [Screenshots](#12-screenshots)
- [Flow of Events](#2-flow-of-events)
    - [Basic Flow](#21-basic-flow)
    - [Alternative Flows](#22-alternative-flows)
- [Special Requirements](#3-special-requirements)
- [Preconditions](#4-preconditions)
- [Postconditions](#5-postconditions)

# 1. Analyze Acceleration Behavior
## 1.1 Brief Description
The use case 'Analyze Acceleration Behavior' analyzes whether the driver accelerates the car at it's full potential and gives hints on how to improve it (e.g. Less Throttle, More Throttle, Downshift, ...).
Those calculations are based on the throttle pedal position, RPM and wheel slip.

## 1.2 Screenshots
For Screenshots look at the [UC See Analytics](../UC_SeeAnalytics/UC_SeeAnalytics.MD).

# 2. Flow of Events
## 2.1 Basic Flow
![Analyze Acceleration Behavior UML](UML.png "UML")

## 2.2 Alternative Flows
n/a

# 3. Special Requirements
n/a

# 4. Preconditions
To calculate the acceleration-behavior-metric an input data stream is necessary.

# 5. Postconditions
n/a

# 6. Function Points
For calculating the Function Points we used the tool on [this](http://groups.umd.umich.edu/cis/course.des/cis375/projects/fp99/main.html) website.

For the following Input we got a score of: **62.4 Function Points**.
This results in an estimation of *9:43h* for this Use Case.

![Analyze Acceleration Behavior Input](AnalyzeAccelerationBehaviorInput.png "Function Point Calculation Input")
![Analyze Acceleration Behavior Questions](AnalyzeAccelerationBehaviorQuestions.jpg "Function Point Calculation Questions")

