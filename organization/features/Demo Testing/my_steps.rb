Given ("I am on {string}") do |url|
    @browser.navigate.to url
    sleep 1
end

When ("I fill in {string} found by {string} with {string}") do |value, type, keys|
    @element = @browser.find_element(type, value)
    @element.send_keys keys
    sleep 1
end

When ("I submit") do
    @element.submit
    sleep 1
end

Then ("I should see title {string}") do |title|
    sleep 1
    raise "Fail" if @browser.title != title
end