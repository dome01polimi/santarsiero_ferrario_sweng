#!/bin/bash

# Check if a file path is provided as an argument
if [ -z "$1" ]; then
    echo "Usage: $0 path_to_your_file"
    exit 1
fi

file_path="$1"

# Check if the file exists
if [ ! -f "$file_path" ]; then
    echo "The file $file_path does not exist."
    exit 1
fi

# Count unique lines and their occurrences
awk '{ count[$0]++ } END { for (line in count) print count[line], line }' "$file_path"

# Count total unique lines
unique_lines=$(awk '{ count[$0]++ } END { print length(count) }' "$file_path")

# Display the total number of unique lines
echo "Total unique lines: $unique_lines"
