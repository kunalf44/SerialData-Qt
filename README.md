# SerialData-Qt

SerialData-Qt is a Qt Quick application that reads and writes serial data through serial ports. This project utilizes C++ and QML to provide an efficient and user-friendly interface for handling serial communication.

## Features

- **Serial Data Reading**: Reads data from serial ports.
- **Baud Rate Configuration**: Change baud rate settings in `serial.cpp`.
- **Automatic Serial Port Detection**: Detects serial ports based on product manufacturer name.
- **Manual Port Entry**: Option to manually enter the port in `usbport` QString.
- **Error Handling**: Automatically reconnects and resumes reading data if the serial port disconnects.
- **Data Writing**: Write data to the same port using the `writeport` function.

## Installation

1. **Clone the repository:**

    ```sh
    git clone https://github.com/yourusername/serialdata-Qt.git
    ```

2. **Navigate to the project directory:**

    ```sh
    cd serialdata-Qt
    ```

3. **Open the project with Qt Creator:**

    ```sh
    qtcreator serialdata-Qt.pro
    ```

4. **Build and run the project:**

    Follow the usual steps in Qt Creator to build and run the project.

## Usage

1. **Configure Baud Rate and Serial Port:**

    - Open `serial.cpp`.
    - Change the baud rate settings as needed.
    - Enter the product manufacturer name for automatic detection or manually set the port in the `usbport` QString.

2. **Run the Application:**

    - Execute the application to start reading serial data.
    - If the serial port disconnects, the application will wait for it to reconnect and resume reading data automatically.
    - Use the `writeport` function to write data to the same port.

## File Structure

- **serialdata-Qt/**
  - **serialdata-Qt.pro**: Project file.
  - **serial.cpp**: Contains the main serial communication logic.
  - **serial.h**: Header file for serial communication.
  - **main.cpp**: Entry point of the application.
  - **qml/**: Directory containing QML files for the user interface.
  - **resources/**: Directory containing application resources.

## Contributing

Contributions are welcome! Please open an issue or submit a pull request for any improvements or bug fixes.

## Contact

For any questions or support, please contact [your-email@example.com](mailto:your-email@example.com).

