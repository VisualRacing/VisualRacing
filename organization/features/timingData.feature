Feature: Display Timing Data
    In order to get detailed information about the laptimes
    As a sim-racer
    I want to see the tab containing the car Data
    
    Scenario: Switch to Timing-Tab
        Given a racing simulation is running
        And the application is not currently displaying the Timing-Tab
        When I select the Timing-Tab
        Then I should no longer see what was displayed previously
        And I should see the Timing-Tab containing information like laptimes

    Scenario: Display Timing-Tab
        Given a racing simulation is running
        And the application is currently displaying the Timing-Tab
        When I select the Timing-tab
        Then I should see the Timing-Tab containing information like laptimes