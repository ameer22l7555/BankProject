# Bank Project

A comprehensive C++ banking system that implements account management and transaction tracking capabilities using modern C++ features and data structures.

## Project Overview

This banking system is built in C++ and provides a robust solution for managing bank accounts and transactions. It utilizes template-based data structures and object-oriented programming principles to create a flexible and maintainable codebase.

### Key Features

- **Account Management**: Create and manage bank accounts
- **Transaction Tracking**: Record and monitor all banking transactions
- **Date and Time Tracking**: Each transaction is timestamped
- **Sorted Data Storage**: Implements sorting algorithms for organized data management
- **Double Linked List Implementation**: Custom template-based double linked list for efficient data storage

## Technical Details

### Core Components

1. **DList Template Class**
   - Custom implementation of a double linked list
   - Generic template-based structure
   - Iterator support for modern C++ compatibility
   - Built-in sorting capabilities

2. **Date Class**
   - Handles date-related operations
   - Supports date input/output
   - Format: DD-MM-YYYY

3. **Time Class**
   - Manages time-related operations
   - Supports time input/output
   - Format: HH:MM

4. **Transaction Class**
   - Unique transaction ID generation
   - Timestamp support
   - Transaction history tracking

5. **Bank Class**
   - Account management functionality
   - Transaction processing
   - Account information display

## Project Structure

```
BankProject/
├── Header.h         # Main header file containing class definitions
├── Program.cpp      # Main program entry point
├── BankProject.sln  # Visual Studio solution file
└── Project Files    # Additional project configuration files
```

## Building and Running

### Prerequisites
- Visual Studio 2019 or later
- C++11 or later compiler
- Windows operating system

### Build Instructions
1. Open `BankProject.sln` in Visual Studio
2. Build the solution (F5 or Ctrl+Shift+B)
3. Run the program

## Usage

The program provides a command-line interface where users can:
1. Create new bank accounts
2. Perform transactions
3. View account details
4. View transaction history

## Contributing

Feel free to fork this repository and submit pull requests. For major changes, please open an issue first to discuss what you would like to change.

## License

This project is open source and available under the [MIT License](LICENSE).