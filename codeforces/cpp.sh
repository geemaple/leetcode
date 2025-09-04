if ! command -v brew &> /dev/null; then
  # Install Homebrew + python
  echo "--installing Homebrew"
  /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
fi
eval "$(brew shellenv)"
brew_dir=$(brew --prefix)
brew_install=$(brew list)

if ! echo "$brew_install" | grep -q 'gcc'; then
  echo "--installing gcc"
  brew install gcc
fi


latest_gpp=$(ls $brew_dir/bin/g++-* | sort -V | tail -n 1)
echo "select $latest_gpp"

if [ -z "$1" ] || [ -z "$2" ]; then
    echo "Usage: $0 <source_file> <test_case_file>"
    exit 1
fi

# Extract the source file and test case file from the arguments
SOURCE_FILE="$1"
TEST_CASE_FILE="$2"

# Compile the source file with g++ and C++20 standard
$latest_gpp -std=c++20 -O2 "$SOURCE_FILE" -o main

# Check if compilation was successful
if [ $? -eq 0 ]; then
    # Execute the compiled program with input from the test case file
    echo "Running the program with test cases from $TEST_CASE_FILE..."
    ./main < "$TEST_CASE_FILE"
    rm main
else
    echo "Compilation failed. Please check the source file."
    exit 1
fi