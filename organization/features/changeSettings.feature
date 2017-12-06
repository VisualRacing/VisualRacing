Feature: Change Settings
    In order to change the settings to my preferences
    As a user
    I want to see the tab to change the Settings and change all settings accordingly

    Scenario: language changed from English to Deutsch
        Given I have selected language English
        When I select language Deutsch
        Then language Deutsch should be applied

    Scenario: theme changed form Dark to Light
        Given I have selected theme Dark
        When I select theme Light
        Then theme Light should be applied

    Scenario: unit changed from Metric to Imperial
        Given I have selected unit system Metric
        When I select unit system Imperial
        Then I unit system Imperial should be applied

    Scenario: language changed from Deutsch to English
        Given I have selected language Deutsch
        When I select language English
        Then language English should be applied

    Scenario: theme changed from Light to Dark
        Given I have selected theme Light
        When I select theme Dark
        Then theme Dark should be applied

    Scenario: unit changed from Imperial to Metric
        Given I have selected unit system Imperial
        When I select unit system Metric
        Then I unit system Metric should be applied