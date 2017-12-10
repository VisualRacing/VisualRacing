Feature: Google can search

Background:
	Given I am on "http://www.google.com"

Scenario: Search for a term
	When I fill in "q" found by "name" with "VisualRacing"
	And I submit
	Then I should see title "VisualRacing - Google-Suche"