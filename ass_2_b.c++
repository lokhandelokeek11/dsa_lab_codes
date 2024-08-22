#include <iostream>
#include <string>
using namespace std;

class employee_database
{
    int emp_id;
    string emp_name;

public:
    void input(employee_database em[], int n);
    void merge(employee_database em[], int l, int m, int r);
    void merge_sort(employee_database em[], int l, int r);
    void putdata(employee_database em[], int l, int r);
};

void employee_database::input(employee_database em[], int n) {
    cout << "Enter the employee ID and names: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> em[i].emp_id >> em[i].emp_name;
    }
}

void employee_database::merge_sort(employee_database em[], int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2;
        merge_sort(em, l, mid);
        merge_sort(em, mid + 1, r);
        merge(em, l, mid, r);
    }
}

void employee_database::putdata(employee_database em[], int l, int r) {
    for (int i = l; i <= r; i++) {
        cout << em[i].emp_id << " " << em[i].emp_name << endl;
    }
}

void employee_database::merge(employee_database em[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    employee_database L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i].emp_id = em[l + i].emp_id;
        L[i].emp_name = em[l + i].emp_name;
    }

    for (int j = 0; j < n2; j++) {
        R[j].emp_id = em[m + 1 + j].emp_id;
        R[j].emp_name = em[m + 1 + j].emp_name;
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        
        if (L[i].emp_name <= R[j].emp_name) {
            em[k].emp_id = L[i].emp_id;
            em[k].emp_name = L[i].emp_name;
            i++;
        } else {
            em[k].emp_id = R[j].emp_id;
            em[k].emp_name = R[j].emp_name;
            j++;
        }
        k++;
    }

    while (i < n1) {
        em[k].emp_id = L[i].emp_id;
        em[k].emp_name = L[i].emp_name;
        i++;
        k++;
    }

    while (j < n2) {
        em[k].emp_id = R[j].emp_id;
        em[k].emp_name = R[j].emp_name;
        j++;
        k++;
    }
}

int main() {
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;
    employee_database em[n];
    char choice;

    do {
        cout << "1. Input employee data\n";
        cout << "2. Sort employee data using Merge Sort\n";
        cout << "3. Display employee data\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                em[0].input(em, n);
                break;
            case '2':
                em[0].merge_sort(em, 0, n - 1);
                break;
            case '3':
                cout << "Sorted Employee Data (by Name):" << endl;
                em[0].putdata(em, 0, n - 1);
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
