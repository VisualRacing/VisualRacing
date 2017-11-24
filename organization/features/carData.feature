Feature: Display car data
    In order to get detailed information about the car
    As a sim-racer
    I want to see the tab containing the car data

    Scenario: Switch to Car-Tab
        Given a racing simulation is running
        And the application is not currently displaying the Car-Tab
        When I select the Car-Tab 
        Then I should no longer see what was displayed previously
        And I should see the Car-Tab containing information like tire temperatures

    Scenario: Display Car-Tab
        Given a racing simulation is running
        And the application is currently displaying the Car-Tab
        When I select the Car-Tab 
        Then I should see the Car-Tab containing information like tire temperatures