#include <iostream>
#include <bitset>
using namespace std;

class ALU {
public:
    void add(int a, int b) {
        cout << "[Addition] Step-by-step:\n";
        printOperand("Operand A", a);
        printOperand("Operand B", b);
        int result = a + b;
        cout << "Step 3: Add A and B: " << a << " + " << b << " = " << result << endl;
        printResult(result);
    }

    void subtract(int a, int b) {
        cout << "[Subtraction] Step-by-step:\n";
        printOperand("Operand A", a);
        printOperand("Operand B", b);
        int result = a - b;
        cout << "Step 3: Subtract B from A: " << a << " - " << b << " = " << result << endl;
        printResult(result);
    }

    void bitwiseAND(int a, int b) {
        cout << "[AND] Step-by-step:\n";
        printOperand("Operand A", a);
        printOperand("Operand B", b);
        int result = a & b;
        cout << "Step 3: A & B = " << result << endl;
        printResult(result);
    }

    void bitwiseOR(int a, int b) {
        cout << "[OR] Step-by-step:\n";
        printOperand("Operand A", a);
        printOperand("Operand B", b);
        int result = a | b;
        cout << "Step 3: A | B = " << result << endl;
        printResult(result);
    }

    void bitwiseNOT(int a) {
        cout << "[NOT] Step-by-step:\n";
        printOperand("Operand A", a);
        int result = ~a;
        cout << "Step 2: ~A = " << result << " (in binary: " << bitset<8>(result) << ")" << endl;
        cout << "Result: " << result << endl;
    }

private:
    void printOperand(string label, int value) {
        cout << label << " = " << value << " (binary: " << bitset<8>(value) << ")\n";
    }

    void printResult(int result) {
        cout << "Step 4: Result in binary: " << bitset<8>(result) << endl;
        cout << "Result: " << result << endl;
    }
};

int main() {
    ALU alu;
    int a, b;
    int choice;
    
    while (true) {
        cout << "\nChoose operation:\n";
        cout << "1. Addition (+)\n";
        cout << "2. Subtraction (-)\n";
        cout << "3. AND (&)\n";
        cout << "4. OR (|)\n";
        cout << "5. NOT (~) [applied to the first number only]\n";
        cout << "6. Exit application\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 6) {
            cout << "----------------------------------\n";
            cout << "Application closed.\n";
            break;
        }

        cout << "Enter first number: ";
        cin >> a;

        if (choice != 5) {
            cout << "Enter second number: ";
            cin >> b;
        }

        cout << "----------------------------------\n";
        switch (choice) {
            case 1:
                alu.add(a, b);
                break;
            case 2:
                alu.subtract(a, b);
                break;
            case 3:
                alu.bitwiseAND(a, b);
                break;
            case 4:
                alu.bitwiseOR(a, b);
                break;
            case 5:
                alu.bitwiseNOT(a);
                break;
            default:
                cout << "Invalid choice." << endl;
        }

        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get(); 
    }

    return 0;
}