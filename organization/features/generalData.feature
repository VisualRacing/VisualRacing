Feature: Display general data
    In order to get general information
    As a sim-racer
    I want to see the tab containing the general data

    Scenario: Switch to General-Tab
        Given a racing simulation is running
        And the application is not currently displaying the General-Tab
        When I select the General-Tab 
        Then I should no longer see what was displayed previously
        And I should see the General-Tab containing information like the gear

    Scenario: Display General-Tab
        Given a racing simulation is running
        And the application is currently displaying the General-Tab
        When I select the General-Tab 
        Then I should see the General-Tab containing information like the gear