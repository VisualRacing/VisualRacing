# VisualRacing - Test Plan

# Table of Contents
- [Introduction](#1-introduction)
    - [Purpose](#11-purpose)
    - [Scope](#12-scope)
    - [Intended Audience](#13-intended-audience)
    - [Document Terminology and Acronyms](#14-document-terminology-and-acronyms)
    - [References](#15-references)
    - [Document Structure](#16-document-structure)
- [Evalutaion Mission and Test Motivation](#2-evalutaion-mission-and-test-motivation)
    - [Background](#21-background)
    - [Evaluation Mission](#22-evaluation-mission)
    - [Test Motivators](#23-test-motivators)
- [Target Test Items](#3-target-test-items)
- [Outline of Planned Tests](#4-outline-of-planned-tests)
    - [Outline of Test Inclusions](#41-outline-of-test-inclusions)
    - [Outline of Other Candidates for Potential Inclusion](#42-outline-of-other-candidates-for-potential-inclusion)
    - [Outline of Test Exclusions](#43-outline-of-test-exclusions)
- [Test Approach](#5-test-approach)
    - [Initial Test-Idea Catalogs and Other Reference Sources](#51-initial-test-idea-catalogs-and-other-reference-sources)
    - [Testing Techniques and Types](#52-testing-techniques-and-types)
- [Entry and Exit Criteria](#6-entry-and-exit-criteria)
    - [Test Plan](#61-test-plan)
    - [Test Cycles](#62-test-cylces)
- [Deliverables](#7-deliverables)
    - [Test Evaluation Summaries](#71-test-evaluation-summaries)
    - [Reporting on Test Coverage](#72-reporting-on-test-coverage)
    - [Percieved Quality Reports](#73-percieved-quality-reports)
    - [Incident Logs and Change Requests](#74-incident-logs-and-change-requests)
    - [Smoke Test Suite and Supporting Test Scripts](#75-smoke-test-suite-and-supporting-test-scripts)
    - [Additional Work Products](#76-additional-work-products)
- [Testing Workflow](#8-testing-workflow)
- [Environmental Needs](#9-environmental-needs)
    - [Base System Hardware](#91-base-system-hardware)
    - [Base Software Elements in the Test Environment](#92-base-software-elements-in-the-test-environment)
    - [Productivity and Support Tools](#93-productivity-and-support-tools)
    - [Test Environment Configurations](#94-test-environment-configurations)
- [Responsibilites, Staffing and Training Needs](#10-responsibilities-staffing-and-training-needs)
    - [People and Roles](#101-people-and-roles)
    - [Staffing and Training Needs](#102-staffing-and-training-needs)
- [Iteration Milestones](#11-iteration-milestones)
- [Risks, Dependencies, Assumptions and Constraints](#12-risks-dependencies-assumptions-and-constraints)
- [Management Process and Procedures](#13-management-process-and-procedures)
    - [Measuring and Assessing the Extent of Testing](#131-measuring-and-assessing-the-extent-of-testing)
    - [Assessing the Deliverables of this Test Plan](#132-assessing-the-deliverables-of-this-test-plan)
    - [Problem Reporting, Escalation and Issue Resoltion](#133-problem-reporting-escalation-and-issue-resolution)
    - [Managing Test Cycles](#134-managing-test-cycles)
    - [Traceability Strategies](#135-traceability-strategies)
    - [Approval and Signoff](#136-approval-and-signoff)

## 1. Introduction
### 1.1 Purpose
The purpose of the Iteration Test Plan is to gather all of the information necessary to plan and control the test effort for a given iteration. 
It describes the approach to testing the software.
This Test Plan for VisualRacing supports the following objectives:

- Identifies the items that should be targeted by the tests.
- Identifies the motivation for and ideas behind the test areas to be covered.
- Outlines the testing approach that will be used.
- Identifies the required resources and provides an estimate of the test efforts.

### 1.2 Scope
The Visual Racing application is tested using unit test for testing methods to ensure that the implementation is working correctly through the development.

The qml user interface components will not be tested except of logical implementation components.
In this document the unit tests are described.

### 1.3 Intended Audience
This test plan contains technically more detailed information and do not provide a describtion of the application itself. From this it follows that this document is for advanced readers with the necessary background knowledge and should be used primarily by active developers of the project.

### 1.4 Document Terminology and Acronyms

| Abbr | Abbreviation                        |
|------|-------------------------------------|
| CI   | Continuous Integration              |
| n/a  | not applicable                      |
| SRS  | Software Requirements Specification |
| tbd  | to be determined                    |
| TDD  | Test Driven Development             |
| UI   | User Interface                      |

### 1.5  References

|Title|Date|
|-|-|
|[Blog](https://visualracing.wordpress.com/)|10/05/2017|
|[GitHub](https://github.com/VisualRacing/VisualRacing)|10/23/2017|
|[Software Architecture Document](https://github.com/VisualRacing/VisualRacing/blob/master/organization/SAD/SAD.MD)|12/10/2017|
|[Use Case Diagram](UC/Use%20Case%20Diagram.png)|10/23/2017|
|[UC Change Settings](UC/UC_ChangeSettings/UC_ChangeSettings.MD)|10/25/2017|
|[UC Read Data Stream](UC/UC_ReadDataStream/UC_ReadDataStream.MD)|10/25/2017|
|[UC Car Data](UC/UC_CarData/UC_CarData.MD)|11/13/2017|
|[UC Timing Data](UC/UC_TimingData/UC_TimingData.MD)|11/27/2017|
|[UC General Data](UC/UC_GeneralData/UC_GeneralData.MD)|11/28/2017|
|[UC Record and Save/Load Data](UC/UC_RecordSaveLoad/UC_RecordSaveLoad.MD)|04/09/2018|
|[UC Analyze Laptime Improvement](UC/UC_AnalyzeLaptimeImprovement/UC_AnalyzeLaptimeImprovement.MD)|04/09/2018|
|[UC Analyze Driving Behavior](UC/UC_AnalyzeDrivingBehavior/UC_AnalyzeDrivingBehavior.MD)|04/09/2018|
|[UC Display Analytics](UC/UC_SeeAnalytics/UC_SeeAnalytics.MD)|04/16/2018|

## 2. Evaluation Mission and Test Motivation
### 2.1 Background
Test coverage for our project gives us the possibility to be sure that future changes does not lead to functional problems. With the integraten of testing into the deployment process we can ensure that just stable versions of our project which accomplish the quality requirements are getting deployed. This leads to a better control of new implementations and the deployment process.

### 2.2 Evaluation Mission
Test are necessary for providing stable and working versions of our project and to ensure that bugs or other problems could be identified earlier. The functionality of our methods and implementations can be verified automatically with the concept of continuous testing. With Test Driven Development (TDD) the tests are getting written before the functionality itself gets implemented. TDD helps a lot to prevent problems and bugs before they occur.

### 2.3 Test Motivators
Quality as well as stability and functional risk gives the motivation to testing the project. To fullfil the requirements to our application it is very important to test the functionality. Additionally it helps implementing the usecases to provide a correct working result.

## 3. Target Test Items
In the following list the tested parts of our application are listed. Tests will cover the main backend functionality as well as the logical implementations in the qml ui part.

Tested parts:

- C++ backend functionality 
- qml logical / algorithmic components

## 4. Outline of Planned Tests
### 4.1 Outline of Test Inclusions
Backend functionality will be tested through unit test.

Qml functionality will be tested through unit test.

The tests themselves are not going to be tested and will not be part of the calculation of code coverage.

### 4.2 Outline of Other Candidates for Potential Inclusion
User interface testing would be additional options to provide a working application. Furthermore performance testing of the application might be an interesting part of quality management to ensure a stable application that accomplish the performance requirements.

### 4.3 Outline of Test Exclusions
n/a

## 5. Test Approach

### 5.1 Testing Techniques and Types

#### 5.1.1 Unit Testing
The concept of unit testing structure the code into pieces that are as small as possible. These little units are going to be tested to check functionality on the lowest possible level. With this partitioning of the implementation bugs and problems are found an a level, that could be proved to work correct or not much better. If a granular functionality could be approved the units can be put together to modules wich then are going to be tested on this higher level. Unit testing could be proven as a good and working way to find bugs and problems early and reliable.

For unit testing QTest and Qt Quick Test are used in this project.

|                        | Description                         | 
|------------------------|-------------------------------------|
| Technique Objective    | Ensure that the implemented functions are working as expected. |
| Technique              | Implement QTests and Qt Quick tests |
| Oracles                | Test Logs, console printings and code coverage calculations |
| Required Tools         | QtCreator |
| Success Criteria       | The tests pass and the required code coverage is given |
| Special Considerations | - |

#### 5.1.2 Performance testing
Performance is not going to be tested at the moment.

## 6. Entry and Exit Criteria
### 6.1 Test Plan

#### 6.1.1 Test Plan Entry Criteria
The process of testing is going to be executed when a new version of the application will be builded

#### 6.1.2 Test Plan Exit Criteria
The process of testing leads to a passing of all tests without errors.

## 7. Deliverables

## 7.1 Test Evaluation Summaries
For testing multiple continuous integration services to build and executes the tests are used. This leads to a automatic testing on every deployment.

| Continuous Integration Service      |  Badge |
|-------------------------------------|---------------|
|TravisCI|[![Build Status](https://travis-ci.org/VisualRacing/VisualRacing.svg?branch=master)](https://travis-ci.org/VisualRacing/VisualRacing)|
|AppVeyor|[![Build status](https://ci.appveyor.com/api/projects/status/t4nq99t1kk1saw2s?svg=true)](https://ci.appveyor.com/project/ChristopherKlammt/visualracing)|

## 7.2 Reporting on Test Coverage
After AppVeyor has built the application successfully the code coverage through tests will be calculated out of the test results. 

## 7.3 Perceived Quality Reports
For calculating quality reports Codacy is used. This tool calulates the amount of errors and many more metrics wich can be used to measure the code quality. 

The following badge shows the latest status of the reports:

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/69efb80d2d864d6ebffd7b27bae84bf5)](https://www.codacy.com/app/ChristopherKlammt/VisualRacing?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=VisualRacing/VisualRacing&amp;utm_campaign=Badge_Grade)

## 7.4 Incident Logs and Change Requests

## 7.5 Smoke Test Suite and Supporting Test Scripts

## 8. Testing Workflow
For testing parts of new code each developer can use the option of running the test from the IDE. This helps a lot to check if new code works as expected. 

Additionally the test process is executed with the deployment.
## 9. Environmental Needs

### 9.1 Base System Hardware

### 9.2 Base Software Elements in the Test Environment

### 9.3 Productivity and Support Tools

## 10. Responsibilities, Staffing and Training Needs

### 10.1 People and Roles

### 10.2 Staffing and Training Needs

## 11. Iteration Milestones

## 12. Risks, Dependencies, Assumptions and Constraints
