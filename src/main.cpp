#include "student.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <limits>

#define FILE_NAME "data.csv"

void clearScreen(void);
void pauseScreen(void);

int main(int argc, char *argv[]) {
    std::vector<Student> students;

    int menu_choice;

    while (true) {
        clearScreen();
        std::cout << "===Student-Grade-Manager===\n"
                     "1. List All Students\n"
                     "2. Calculate Average GPA\n"
                     "3. Search Student\n"
                     "4. Add Student\n"
                     "5. Remove Student\n"
                     "6. Load data\n"
                     "7. Store data\n"
                     "8. Exit\n"
                     "Enter Your Choice: ";
        std::cin >> menu_choice;
        
        if (menu_choice < 1 || menu_choice > 8) continue;

        if (menu_choice == 8) {
            clearScreen();

            char yn;
            std::cout << "Exit? [y/N]: ";
            std::cin >> yn;

            if (yn == 'y' || yn == 'Y') {
                clearScreen();

                std::cout << "Exited Successfully\n";
                exit(EXIT_SUCCESS);
            }
        }

        switch (menu_choice) {
            case 1: // List all students
                if (students.empty()) {
                    clearScreen();
                    std::cout << "No Students Added!\n";
                    pauseScreen();
                }
                else {
                    clearScreen();
                    listAllStudent(students);
                    pauseScreen();
                }

                break;

            case 2: // Calculate average GPA
                if (students.empty()) {
                    clearScreen();
                    std::cout << "No Students Added!\n";
                    pauseScreen();
                }
                else {
                    clearScreen();
                    std::cout << "Total student: " << students.size() << '\n'
                              << "Averge GPA: " << averageGPA(students) << '\n';
                    pauseScreen();
                }

                break;

            case 3: // Search student
                break;

            case 4: // Add student
                break;

            case 5: // Remove student
                break;

            case 6: // Load data
            {
                std::ifstream inFile("../data/data.csv");
                if (!inFile.is_open()) {
                    clearScreen();
                    std::cerr << "Error opening the file\n";
                    pauseScreen();
                }
                else {
                    loadData(students, inFile);
                    clearScreen();
                    std::cout << "Data loaded successfully\n";
                    pauseScreen();
                }
            }
  
                break;

            case 7: //Store data
            {
                if (students.empty()) {
                    clearScreen();
                    std::cout << "No Students Added!\n";
                    pauseScreen();
                }
                else {
                    std::ofstream outFile("../data/data.csv");
                    if (!outFile.is_open()) {
                        clearScreen();
                        std::cerr << "Error opening the file\n";
                        pauseScreen();
                    }
                    else {
                        storeData(students, outFile);
                        clearScreen();
                        std::cout << "Data saved successfully\n";
                        pauseScreen();
                    }
                }
            }

                break;
        }
    }

    return 0;
}

void clearScreen(void) {
    std::cout << "\033[2J\033[H" << std::flush;
}

void pauseScreen(void) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\nPress enter to continue. . .\n";
    std::cin.get();
}