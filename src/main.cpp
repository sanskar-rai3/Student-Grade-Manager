#include "student.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <limits>

#define FILE_PATH "../data/data.csv"

void clearScreen(void);
void pauseScreen_cin(void);
void pauseScreen_getline(void);

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
            char choice;
            std::cout << "Warning: Data will not be saved automatically, Save before exiting\n"
                         "Exit? [y/N]: ";
            std::cin >> choice;
            if (choice == 'y' || choice == 'Y') {
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
                    pauseScreen_cin();
                }
                else {
                    clearScreen();
                    listAllStudent(students);
                    pauseScreen_cin();
                }

                break;

            case 2: // Calculate average GPA
                if (students.empty()) {
                    clearScreen();
                    std::cout << "No Students Added!\n";
                    pauseScreen_cin();
                }
                else {
                    clearScreen();
                    std::cout << "Total student: " << students.size() << '\n'
                              << "Averge GPA: " << averageGPA(students) << '\n';
                    pauseScreen_cin();
                }

                break;

            case 3: // Search student
                break;

            case 4: // Add student
                {
                    clearScreen();
                    std::string name;
                    float gpa;
                    std::cout << "Enter full name: ";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    std::getline(std::cin, name);

                    bool isNew = true;
                    for (const Student &student : students) {
                        if (name == student.getName()) {
                            isNew = false;
                        }
                    }
                    if (isNew) {
                        std::cout << "Enter GPA: ";
                        std::cin >> gpa;
                        addStudent(students, name, gpa);
                    }
                    else {
                        std::cout << "Student already exists!\n";
                        pauseScreen_getline();
                    }
                }

                break;

            case 5: // Remove student
                break;

            case 6: // Load data
                {
                    std::ifstream inFile(FILE_PATH);
                    if (!inFile.is_open()) {
                        clearScreen();
                        std::cerr << "Error opening the file\n";
                        pauseScreen_cin();
                    }
                    else {
                        clearScreen();
                        char choice;
                        std::cout << "The current data will get overwritten\n"
                                     "Continue?[y/N]: ";
                        std::cin >> choice;
                        if (choice == 'y' || choice == 'Y') {
                            clearScreen();
                            loadData(students, inFile);
                            std::cout << "Data loaded successfully\n";
                            pauseScreen_cin();
                        }
                    }
                }
  
                break;

            case 7: //Store data
                {
                    if (students.empty()) {
                        clearScreen();
                        std::cout << "No Students Added!\n";
                        pauseScreen_cin();
                    }
                    else {
                        std::ofstream outFile(FILE_PATH);
                        if (!outFile.is_open()) {
                            clearScreen();
                            std::cerr << "Error opening the file\n";
                            pauseScreen_cin();
                        }
                        else {
                            clearScreen();
                            char choice;
                            std::cout << "The current stored data will get cleared and overwritten\n"
                                         "Continue?[y/N]: ";
                            std::cin >> choice;
                            if (choice == 'y' || choice == 'Y') {
                                clearScreen();
                                storeData(students, outFile);
                                std::cout << "Data saved successfully\n";
                                pauseScreen_cin();
                            }
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

// Pause Screen after std::cin
void pauseScreen_cin(void) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\nPress enter to continue. . .\n";
    std::cin.get();
}

// Pause Screen after std::getline
void pauseScreen_getline(void) {
    std::cout << "\nPress enter to continue. . .\n";
    std::cin.get();
}