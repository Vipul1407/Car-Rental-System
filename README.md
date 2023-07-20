# Car-Rental-System
This is a C++based project that allows users to rent cars for specified durations. It includes admin features like adding and deleting cars, managing available cars, and user functionalities such as renting cars as new or existing customers. The system also calculates rental costs based on the duration.

**Car Rental System**

This car rental system is a command-line-based application that allows users to rent cars for a specified duration. It offers two main user roles: Admin and User.

**Admin Features:**
1. **Add Admin**: Admin can add new admin users by assigning them a unique ID and a password. These admin users can log in to access administrative functionalities.
2. **Show Car Data**: Admin can view the details of all available cars, including the plate number, brand, model, capacity, color, and rental rates per hour, 12 hours, and 24 hours.
3. **Add Car**: Admin can add new cars to the rental system. The admin must input details such as plate number, brand, model, capacity, color, and rental rates.
4. **Delete Car**: Admin can remove a car from the system by providing its plate number.
5. **Reset Available Cars**: Admin can reset the list of available cars to remove any rented cars from the system.

**User Features:**
1. **New Customer**: New customers can use this option to rent a car. The system will prompt them to provide their details, including name, phone number, IC (Identification Card) number, and address. They can then select a car from the list of available cars and specify the rental duration (in hours).
2. **Existing Customer**: Existing customers can rent a car by providing their user ID. The system will retrieve their details and allow them to select a car and specify the rental duration.
3. **Total Cost Calculation**: The system calculates the total cost based on the rental duration and the chosen car's rental rates (per hour, 12 hours, and 24 hours).

**Additional Features:**
1. **Date and Time Display**: The system displays the current date and time during user interaction.
2. **Art and Animation**: The system displays ASCII art and simple animations for an aesthetically pleasing user experience.
3. **Password Protection**: The system implements password protection for admin access.
4. **Data Persistence**: The system stores car and customer data in text files for future use.

**How to Use:**
1. Upon running the application, the user is presented with a main menu where they can choose to log in as an admin or a regular user.
2. Admins can log in using their unique ID and password to access admin functionalities.
3. Regular users can either choose to rent a car as a new customer or as an existing customer.
4. New customers must provide their details, select a car, and specify the rental duration to complete the rental process.
5. Existing customers need to provide their user ID, select a car, and specify the rental duration to rent a car.
6. The system calculates the total cost of the rental and displays it to the user.
7. Upon completing the rental process, the system updates the list of available cars.

**Technologies Used:**
1. C++ Programming Language: The core logic of the application is implemented using C++.
2. File Handling: Car and customer data are stored and retrieved using text files.
