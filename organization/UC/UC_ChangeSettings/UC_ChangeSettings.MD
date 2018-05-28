# Use-Case Specification: Change Settings

# Table of Contents
- [Change Settings](#1-change-settings)
    - [Brief Description](#11-brief-description)
    - [Mockup](#12-mockup)
    - [Screenshot](#13-screenshot)
- [Flow of Events](#2-flow-of-events)
    - [Basic Flow](#21-basic-flow)
    - [Alternative Flows](#22-alternative-flows)
- [Special Requirements](#3-special-requirements)
- [Preconditions](#4-preconditions)
    - [Settings File](#41-settings-file)
- [Postconditions](#5-postconditions)
- [Function Points](#6-function-points)
    - [Semester I](#61-semester-i)
    - [Semester II](#62-semester-ii)

# 1. Change Settings
## 1.1 Brief Description
The purpose of this use case is that the user can change the settings according to his personal preferences.
As for now there will be settings regarding the unit system (whether to use the imperial or metric system), the language and which theme the user wants to apply to the Application (Light or Dark theme).
In order to do so the system has to fetch the already saved settings and load them accordingly. Then the user can make his desired changes which will by saved and applied by pressing the button 'Apply'. Then the UI will be redrawn and updated.

## 1.2 Mockup
![Change Settings Mockup](Mockup.png "Mockup")

## 1.3 Screenshot
![Change Settings Screenshot](../../screenshots/Screenshot_Settings.png "Screenshot")

# 2. Flow of Events
## 2.1 Basic Flow
![Change Settings UML](UML.png "UML")

When a user switches to the settings-tab, the system will load the settings from a settings-file to provide them on the UI. Now the user has the possibility to change settings such as "theme", "unit" and "language". After changing the settings, the user can decide if he wants to apply his changes or reset the settings to their default values. To apply the changes we will provide an apply button and a OK button. While the apply button just updates the UI and saves the changes, the OK button additionaly will take the user back to the tab that was open before.

You can see the .feature file that describes this Use-Case [here](../../features/changeSettings.feature) or on the screenshot below:

![Change Settings Narrative](Feature_ChangeSettings.png "Feature")

## 2.2 Alternative Flows
n/a

# 3. Special Requirements
n/a

# 4. Preconditions
## 4.1 Settings file
For the program to display the saved settings, the settings file has to exist in the program directory. Otherwise a new file will be created with the default values.

# 5. Postconditions
As a result of this use case the settings have been changed according to the users preferences.

# 6. Function Points
For calculating the Function Points we used the tool on [this](http://groups.umd.umich.edu/cis/course.des/cis375/projects/fp99/main.html) website.

We split up this Use Case into two parts and worked on one part in the first semester and on the other part during the second semester.

# 6.1 Semester I
For the following Input we got a score of: **15,4 Function Points**.
This Use Case took us *1:53h* to implement

![Settings Tab Semester I Input](settingsTabSem1Input.png "Function Point Calculation Input")
![Settings Tab Semester I Questions](settingsTabSem1Questions.jpg "Function Point Calculation Questions")

# 6.1 Semester II
For the following Input we got a score of: **25.8 Function Points**.
This results in an estimation of *3:16h* to implement.

![Settings Tab Semester II Input](settingsTabSem2Input.png "Function Point Calculation Input")
![Settings Tab Semester II Questions](settingsTabSem1Questions.jpg "Function Point Calculation Questions")