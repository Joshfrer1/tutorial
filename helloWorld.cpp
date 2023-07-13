#include <iostream>
#include <cstdlib>
#include <chrono>
#include <cmath>
using namespace std;
using namespace std::chrono;

double power(double num1, double num2) {
    return pow(num1, num2);
}

double add(double num1, double num2) {
    return num1 + num2;
}

double subtract(double num1, double num2) {
    return num1 - num2;
}

double multiply(double num1, double num2) {
    return num1 * num2;
}

double divide(double num1, double num2) {
    return num1 / num2;
}

void printResult(double result) {
    printf("%.2f\n", result);
}

double getPercentage(double value, double sum) {
    return (value / sum) * 100.0;
}

int countPower(){
    static int count = 0;
    return count++;
}

int countAdd() {
    static int count = 0;
    return count++;
}

int countSubtract() {
    static int count = 0;
    return count++;
}

int countMultiply() {
    static int count = 0;
    return count++;
}

int countDivide() {
    static int count = 0;
    return count++;
}

void getStats(double add, double subtract, double multiply, double divide, double powers) {
    int sum = add + subtract + multiply + divide + powers;
    printf("\n");
    cout << "Percent of times addition called: " << getPercentage(add, sum) << "%" << endl;
    cout << "Percent of times subtraction called: " << getPercentage(subtract, sum) << "%" << endl;
    cout << "Percent of times multiplication called: " << getPercentage(multiply, sum) << "%" << endl;
    cout << "Percent of times division called: " << getPercentage(divide, sum) << "%" << endl;
    cout << "Percent of times power called: " << getPercentage(powers, sum) << "%" << endl;
    printf("\n");
}

void compute(double num1, double num2, int operation) {

    switch(operation) {
        case 1:
            countAdd();
            cout << "Addition: ";
            printResult(add(num1, num2));
            break;
        case 2:
            countSubtract();
            cout << "Subtraction: ";
            printResult(subtract(num1, num2));
            break;
        case 3:
            countMultiply();
            cout << "Multiplication: ";
            printResult(multiply(num1, num2));
            break;
        case 4:
            countDivide();
            cout << "Division: ";
            printResult(divide(num1, num2));
            break;
        case 5:
            countPower();
            cout << "Power: ";
            printResult(power(num1, num2));
            break;
        default:
            printf("\nOperation was not between 1 and 5: %d", operation);
    }
}

void simulate(double simulations) {
    
    // Seed the randomizer such that everytime I run the program
    // the numbers inputed will change
    srand(time(0));

    // start the clock
    auto start = high_resolution_clock::now();
    for (double i = 0; i < simulations; i++) {
        // I tried to put them doubleo variables but realized quickly that since they were
        // stored in memory they would never randomize again so I would output the same
        // values as many times as I simulated.
        compute(((rand() % (10 - 1 + 1)) + 1), ((rand() % (10 - 1 + 1)) + 1), ((rand() % (5 - 1 + 1)) + 1));
        // the parameters are set such that a range can be defined for the randomizers.
        // Parameter 1 and 2 take in value randomly from 1 to 100.
        // Parameter 3 takes in a value for the switch case from 1 to 4.
    }

    // end the clock
    auto end = high_resolution_clock::now();

    // get the difference and report
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "\n" << "Execution time: " << duration.count() << " milliseconds" << endl;
    getStats(countAdd(), countSubtract(), countMultiply(), countDivide(), countPower());
}

int main() {
    simulate(1000);
    return 0;
}

// if (operation == 1) {
    //     countAdd();
    //     cout << "Addition: ";
    //     printResult(add(num1, num2));
    // }
    // else if (operation == 2) {
    //     countSubtract();
    //     cout << "Subtraction: ";
    //     printResult(subtract(num1, num2));
    // }
    // else if (operation == 3) {
    //     countMultiply();
    //     cout << "Multiplication: ";
    //     printResult(multiply(num1, num2));
    // }
    // else if (operation == 4) {
    //     countDivide();
    //     cout << "Division: ";
    //     printResult(divide(num1, num2));
    // }
    // else {
    //     printf("\nOperation was not between 1 and 4: %f", operation);
    // }
