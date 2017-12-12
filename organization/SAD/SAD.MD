# Software Architecture Document

# Table of Contents
- [Introduction](#1-introduction)
    - [Purpose](#11-purpose)
    - [Scope](#12-scope)
    - [Definitions, Acronyms and Abbreviations](#13-definitions-acronyms-and-abbreviations)
    - [References](#14-references)
    - [Overview](#15-overview)
- [Architectural Representation](#2-architectural-representation)
- [Architectural Goals and Constraints](#3-architectural-goals-and-constraints)
- [Use-Case View](#4-use-case-view)
- [Logical View](#5-logical-view)
    - [Overview](#51-overview)
    - [Architecturally Significant Design Packages](#52-architecturally-significant-design-packages)
- [Process View](#6-process-view)
- [Deployment View](#7-deployment-view)
- [Implementation View](#8-implementation-view)
- [Data View](#9-data-view)

## 1. Introduction
### 1.1 Purpose
This document provieds an overview of the system architecture. It contains a quick overview of the realization of the MVC-pattern as well as class diagrams which are relevant for the implementaion.  

### 1.2 Scope
This document describes the architecture of the VisualRacing-Analytics-Tool.

### 1.3 Definitions, Acronyms and Abbreviations
|Term||
|-|-|
|**SRS**|Software Requirements Specification|
|**Qt**|cross-platform application framework for developing applications that can be run on various hardware platforms with no change in the underlying codebase|
|**MVC**|Model–view–controller (MVC) is a software architectural pattern for implementing user interfaces on computers|
|**QML**|QML (Qt Meta Language or Qt Modeling Language) is a user interface markup language|

### 1.4 References
|Title|Date|
|-|-|
|[Blog](https://visualracing.wordpress.com/)|10/05/2017|
|[GitHub](https://github.com/VisualRacing/VisualRacing)|10/23/2017|
|[Software Requirements Specification](https://github.com/VisualRacing/VisualRacing/blob/master/organization/SRS.MD)|12/10/2017|
|[Use Case Diagram](UC/Use%20Case%20Diagram.png)|10/23/2017|
|[UC Change Settings](UC/UC_ChangeSettings/UC_ChangeSettings.MD)|10/25/2017|
|[UC Read Data Stream](UC/UC_ReadDataStream/UC_ReadDataStream.MD)|10/25/2017|
|[UC Car Data](UC/UC_CarData/UC_CarData.MD)|11/13/2017|
|[UC Timing Data](UC/UC_TimingData/UC_TimingData.MD)|11/27/2017|
|[UC General Data](UC/UC_GeneralData/UC_GeneralData.MD)|11/28/2017|

### 1.5 Overview
n/a

## 2. Architectural Representation
In our project we are using the Qt-Framework. In fact Qt is misusing the MVC-terminology a little bit. All views are implemented in QML, which is a javascript based ui-modeling language. Some parts of the controller (for example event handling) is realized in the QML-part. The model is represented by the C++ backend and provides all the data to QML. As the C++ part is also the backend, it implements also the event-handlers from QML.

![Qt-MVC](qt_mvc.png "Qt-MVC")

## 3. Architectural Goals and Constraints
With using Qt Quick we have the possibility to develop a C++ application in an MVC-like way. The QML-Layer should only be responsible for the view, ui-components and the user-event-catching. All the event-handler-implementation should be realized in the C++ Layer to provide consitensy and a faster implementation (C++ is faster than javascript). All QML-Objects should get bound to C++ properties. As a result the model is a C++ Object. As in other MVC-implementations we have only dependencies from QML (the view) to C++ (our backend).  

## 4. Use-Case View
You can see our Use-Case diagram below. For further details make sure to check out our [SRS](../SRS.MD).

![UML Use Case Diagram](../UC/Use%20Case%20Diagram.png  "UML Use Case Diagram")

## 5. Logical View
All QML objects are internally implemented as C++ Classes. The following graphic gives an overview of our custom QML-Object implementations. Because our analytics tool provides many graphical visualiziations we use our own plot implementation, for this we developed our optimized base class VRPlotItem. General window properties get managed by the MainWindow class. In the future there will be some more QML-Object implementations.

![UML Class Diagram](VisualRacing.svg "UML Class Diagram")

As our application is based on data which is provided by an external racing simulation, we additionally need a data interface that reads the data outputted by the simulation and provides this data as a model to our view and controller. This data interface has no connection to the visualization-code of our application, so we created a separate class diagram for our data interface.

![UML Class Diagram Data Interface](VisualRacing_DataInterface.svg "UML Class Diagram Data Interface")

As we are currently working on the data mapping, there will be some further changes to the class VRData. We will update the diagram accordingly.

![QML View Files](QML_View_Files.png "QML View Files")

These are our QML Files which represent the different views.

### 5.2 Architecturally Significant Design Packages
n/a
## 6. Process View
n/a
## 7. Deployment View
![Deployment View](deployment.png "Deployment View")

## 8. Implementation View
n/a
## 9. Data View
n/a
