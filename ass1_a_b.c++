#include <iostream>
using namespace std;

class student_database
{
    int roll_no;
    string name;

public:
    void input(student_database s[], int n);
    void insertion_sort(student_database s[], int n);
    void shell_sort(student_database s[], int n);
    void putdata(student_database s[], int n);
};

// Function definitions outside the class

void student_database::input(student_database s[], int n)
{
    cout << "Enter the roll numbers and names (space-separated):" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i].roll_no >> s[i].name;
    }
}

void student_database::insertion_sort(student_database s[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        student_database val = s[i];
        while (j >= 0 && s[j].roll_no > val.roll_no)
        {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = val;
    }
}

void student_database::shell_sort(student_database s[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int j = gap; j < n; j++)
        {
            for (int i = j - gap; i >= 0; i -= gap)
            {
                if (s[i + gap].name > s[i].name)
                {
                    break;
                }
                else
                {
                    student_database temp = s[i + gap];
                    s[i + gap] = s[i];
                    s[i] = temp;
                }
            }
        }
    }
}

void student_database::putdata(student_database s[], int n)
{
    cout << "Student Names (Sorted):" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Roll No: " << s[i].roll_no << ", Name: " << s[i].name << endl;
    }
}

int main()
{
    const int n = 5; // Fixed size of array
    student_database s[n], x;

    char ch;
    int choice;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Input student data\n";
        cout << "2. Sort student data using Insertion Sort\n";
        cout << "3. Sort student using Shell Sort\n";
        cout << "4. Display student data\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            x.input(s, n);
            break;
        case 2:
            x.insertion_sort(s, n);
            break;
        case 3:
            x.shell_sort(s, n);
            break;
        case 4:
            x.putdata(s, n);
            break; // Added break statement
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        cout << "Do you want to continue? (y/n): ";
        cin >> ch;
    } while (ch == 'y');

    return 0;
}
