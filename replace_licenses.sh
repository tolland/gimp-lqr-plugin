#!/bin/bash
set -eu
set -o pipefail

# Script to replace license headers with placeholders
# Usage: ./replace_licenses.sh

# Directory containing the license templates
LICENSE_DIR="replacments"

# Create the license directory if it doesn't exist
mkdir -p "$LICENSE_DIR"

# Function to process a file
process_file() {
    local file="$1"
    local temp_file="${file}.tmp"
    
    # Skip binary files and the scripts themselves
    if file "$file" | grep -q "text"; then
        # Look for license headers in the file
        if grep -q "Permission is hereby granted" "$file"; then
            # Extract the license text
            local license_text=$(awk '/Permission is hereby granted/,/authorization from the Author./' "$file")
            
            # Generate a unique identifier for this license
            local license_hash=$(echo "$license_text" | md5sum | cut -d' ' -f1)
            local license_file="${LICENSE_DIR}/LICENSE.${license_hash}"
            
            # Save the license text if it doesn't exist
            if [ ! -f "$license_file" ]; then
                echo "$license_text" > "$license_file"
            fi
            
            # Replace the license text with the placeholder
            local filename=$(basename "$file")
            sed -e "/Permission is hereby granted/,/authorization from the Author./c\\/* ${filename} @replacement: ${LICENSE_DIR}/LICENSE.${license_hash}  */" "$file" > "$temp_file"
            
            # Replace the original file
            mv "$temp_file" "$file"
            echo "Processed: $file"
        fi
    fi
}

# Find all files in the project (excluding .git, build, and other non-source directories)
find . -type f \
    -not -path "*/\.*" \
    -not -path "*/build/*" \
    -not -path "*/autom4te.cache/*" \
    -not -path "*/windows_installer_files/*" \
    -not -path "*/debian.in/*" \
    -not -path "*/replacments/*" \
    -not -name "replace_licenses.sh" \
    -not -name "restore_licenses.sh" | while read -r file; do
    process_file "$file"
done

echo "License replacement complete. Check the ${LICENSE_DIR} directory for the extracted licenses." 