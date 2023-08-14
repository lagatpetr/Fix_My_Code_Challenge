#!/usr/bin/node

/*
    Print a square with the character #

    The size of the square must be the first argument
    of the program.
*/

// Check if the number of arguments is less than 3
if (process.argv.length < 3) {
    // Display an error message to stderr
    console.error("Missing argument");
    console.error("Usage: ./1-print_square.js <size>");
    console.error("Example: ./1-print_square.js 8");
    // Exit with a non-zero status code
    process.exit(1);
}

// Parse the size argument as an integer
const size = parseInt(process.argv[2]);

// Loop to print the square
for (let i = 0; i < size; i++) {
    // Loop to print each row of the square
    for (let j = 0; j < size; j++) {
        // Print a single "#" character without a newline
        process.stdout.write("#");
    }
    // Print a newline to move to the next row
    process.stdout.write("\n");
}

