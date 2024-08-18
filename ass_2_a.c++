#include <iostream>
using namespace std;

class employee_database {
    int emp_id;
    string emp_name;
    double emp_salary;

public:
    void input(employee_database e[], int n);
    void quick_sort(employee_database e[], int F, int L);
    void putdata(employee_database e[], int n);
};

void employee_database::input(employee_database e[], int n) {
    cout << "Enter the employee ID, names, and salaries:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> e[i].emp_id >> e[i].emp_name >> e[i].emp_salary;
    }
}

void employee_database::quick_sort(employee_database e[], int F, int L) {
    if (F < L) {
        int pivot = e[F].emp_id; // Use the first element as the pivot
        int i = F + 1;
        int j = L;

        while (i <= j) {
        
            while (i <= L && e[i].emp_id < pivot) {
                i++;
            }
        
            while (j >= F && e[j].emp_id > pivot) {
                j--;
            }
        
            if (i < j) {
                employee_database temp = e[i];
                e[i] = e[j];
                e[j] = temp;
            }
        }
        
        employee_database temp = e[F];
        e[F] = e[j];
        e[j] = temp;

       
        quick_sort(e, F, j - 1);
        quick_sort(e, j + 1, L);
    }
}

void employee_database::putdata(employee_database e[], int n) {
    cout << "Employee Data (Sorted):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "EMP-ID: " << e[i].emp_id << ", EMP-NAME: " << e[i].emp_name << ", EMP-SALARY: " << e[i].emp_salary << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of employees: ";
    cin >> n;
    int F = 0;
    int L = n-1;

    employee_database e[n], x;
    char choice;

    do {
        cout << "1. Input employee data\n";
        cout << "2. Sort employee data using Quick Sort\n";
        cout << "3. Display employee data\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                x.input(e, n);
                break;
            case '2':
                x.quick_sort(e,F,L); 
                break;
            case '3':
                x.putdata(e, n);
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
        cout << "Do you want to continue? (y/n): ";
        cin >> choice;
    } while (choice == 'y');

    return 0;
}
