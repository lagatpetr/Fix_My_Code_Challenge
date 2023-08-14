###
# Sort integer arguments (ascending)
###

# Initialize an empty array to store the sorted integers
result = []

# Iterate through each argument passed
ARGV.each do |arg|
    # Skip if the argument is not an integer
    next if arg !~ /^-?[0-9]+$/
    
    # Convert the argument to an integer
    i_arg = arg.to_i
    
    # Insert the integer at the right position in the result array
    is_inserted = false
    i = 0
    while !is_inserted do
        if i == result.size || result[i] > i_arg
            result.insert(i, i_arg)
            is_inserted = true
        end
        i += 1
    end
end

# Print the sorted integers joined by newline
puts result.join("\n")

