#!/bin/bash

# Check if the correct number of arguments is provided
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 input_image.png output_image.pgm"
    exit 1
fi

input_file=$1
output_file=$2

# Convert PNG to grayscale PGM (P2 format)
convert "$input_file" -colorspace Gray -compress none -flatten -define pgm:format=ascii "$output_file"


# Check if the conversion was successful
if [ ! -f "$output_file" ]; then
    echo "Error: Failed to convert PNG to PGM."
    exit 1
fi

echo "Conversion complete: $output_file"