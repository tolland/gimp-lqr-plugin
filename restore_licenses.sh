#!/bin/bash
set -eu
set -o pipefail

# Script to restore license headers from placeholders
# Usage: ./restore_licenses.sh

# Directory containing the license templates
LICENSE_DIR="replacments"

# Function to process a file
process_file() {
    local file="$1"
    local temp_file="${file}.tmp"
    
    # Skip binary files and the scripts themselves
    if file "$file" | grep -q "text"; then
        # Look for replacement markers in the file
        if grep -q "@replacement:" "$file"; then
            # Extract the license file path from the marker
            local license_file=$(grep -o "@replacement: [^ ]*" "$file" | cut -d' ' -f2)
            
            if [ -f "$license_file" ]; then
                # Read the license text
                local license_text=$(cat "$license_file")
                
                # Replace the marker with the license text
                sed -e "/@replacement:/c\\${license_text}" "$file" > "$temp_file"
                
                # Replace the original file
                mv "$temp_file" "$file"
                echo "Restored: $file"
            else
                echo "Warning: License file $license_file not found for $file"
            fi
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

echo "License restoration complete." 