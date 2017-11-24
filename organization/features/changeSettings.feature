Feature: Change Settings
    In order to change the settings to my preferences
    As a user
    I want to see the tab to change the Settings and change all settings accordingly

    Scenario: press OK, language changed
        Given I have changed language settings
        When I press the OK button
        Then I should see the previous tab
        And I should see the new language

    Scenario: press OK, theme changed
        Given I have changed theme settings
        When I press the OK button
        Then I should see the previous tab
        And I should see the new theme

    Scenario: press OK, unit changed
        Given I have changed unit settings
        When I press the OK button
        Then I should see the previous tab
        And I should see the new unit system

    Scenario: press Apply, language changed
        Given I have changed language settings
        When I press the apply button
        Then I should see the Settings-Tab
        And I should see the new language

    Scenario: press Apply, theme changed
        Given I have changed theme settings
        When I press the apply button
        Then I should see the Settings-Tab
        And I should see the new theme

    Scenario: press Apply, unit changed
        Given I have changed unit settings
        When I press the apply button
        Then I should see the Settings-Tab

    Scenario: press Reset
        Given I have changed Settings in Settings-Tab
        When I press the reset button
        Then I should see the Settings-Tab
        And I should see the default settings selected