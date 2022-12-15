// Якубовський Владислав, ІКНІ, РІ-11, АП, ЛР 09.1, рівень В, варіант 24
#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

enum Specialization { COMPUTER_SCIENCE, IT, MATH_AND_ECONOMICS, PHYSICS_AND_IT, WORK_EDUCATION };

string specializations[]{ "КН", "Інформатика", "МЕ", "ФІ", "ТН" };

struct Student
{
    string surname = "";
    Specialization specialization = COMPUTER_SCIENCE;

    int course = 1, physicsGrade = 1, mathGrade = 1;

    union
    {
        int programmingGrade = 1, numericalMethodsGrade, pedagogyGrade;
    };
};

void CreateStructure(Student* students, const int studentsCount)
{
    int specialization;

    for (int ii = 0; ii < studentsCount; ii++)
    {
        cout << "Студент  № " << ii + 1 << ":" << endl;
        cin.get(); cin.sync();

        cout << "1) прізвище: "; getline(cin, students[ii].surname);
        cout << "2) курс: "; cin >> students[ii].course;
        cout << "3) спеціальність (1 - KH, 2 - Інформатика, 3 - МЕ, 4 - ФІ, 5 - ТН): "; cin >> specialization;
        cout << "4) оцінка з фізики: "; cin >> students[ii].physicsGrade;
        cout << "5) оцінка з математики: "; cin >> students[ii].mathGrade;

        students[ii].specialization = (Specialization)(specialization - 1);

        switch (students[ii].specialization)
        {
        case COMPUTER_SCIENCE:
            cout << "6) оцінка з програмування: "; cin >> students[ii].programmingGrade;

            break;

        case IT:
            cout << "6) оцінка з чисельних методів: "; cin >> students[ii].numericalMethodsGrade;

            break;

        case MATH_AND_ECONOMICS:
        case PHYSICS_AND_IT:
        case WORK_EDUCATION:
            cout << "6) оцінка з педагогіки: "; cin >> students[ii].pedagogyGrade;

            break;
        }
    }
}

void DisplayStructure(Student* students, const int studentsCount)
{
    cout << "\n============================================================================================================================================================"
        << endl;
    cout << "| № |    Прізвище    | Курс | Спеціальність | Оцінка з фізики | Оцінка з математики | Оцінка з програмування | Оцінка з чис. методів | Оцінка з педагогіки |"
        << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------"
        << endl;

    for (int ii = 0; ii < studentsCount; ii++)
    {
        cout << "| " << setw(2) << ii + 1
            << "| " << setw(15) << students[ii].surname
            << "| " << setw(5) << students[ii].course
            << "| " << setw(14) << specializations[students[ii].specialization]
            << "| " << setw(16) << students[ii].physicsGrade
            << "| " << setw(20) << students[ii].mathGrade;

        switch (students[ii].specialization)
        {
        case COMPUTER_SCIENCE:
            cout << "| " << setw(23) << students[ii].programmingGrade << "|" << setw(24) << "|" << setw(22) << "|";

            break;

        case IT:
            cout << "| " << setw(24) << "|" << setw(23) << students[ii].numericalMethodsGrade << "|" << setw(22) << "|";

            break;

        case MATH_AND_ECONOMICS:
        case PHYSICS_AND_IT:
        case WORK_EDUCATION:
            cout << "| " << setw(24) << "|" << setw(24) << "|" << setw(21) << students[ii].pedagogyGrade << "|";

            break;
        }

        cout << endl;
    }

    cout << "============================================================================================================================================================"
        << endl;
}

int GoodGradesCount(Student* students, const int studentsCount)
{
    int goodGradesCount = 0;

    for (int ii = 0; ii < studentsCount; ii++)
    {
        if (students[ii].physicsGrade == 4) goodGradesCount++;

        if (students[ii].mathGrade == 4) goodGradesCount++;

        if (students[ii].programmingGrade == 4) goodGradesCount++;
        
        if(students[ii].pedagogyGrade == 4) goodGradesCount++;

        if (students[ii].numericalMethodsGrade == 4) goodGradesCount++;
    }

    return goodGradesCount;
}

float WellDoingPhysicsAndMathStudentsPercent(Student* students, const int studentsCount)
{
    int wellDoingPhysicsStudentsCount = 0;

    for (int ii = 0; ii < studentsCount; ii++)
        if (students[ii].physicsGrade == 5 && students[ii].mathGrade == 5) wellDoingPhysicsStudentsCount++;

    float percent = 100 * static_cast<float>(wellDoingPhysicsStudentsCount) / studentsCount;

    return percent;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int studentsCount;

    cout << "Введіть кількість студентів: "; cin >> studentsCount;

    Student* students = new Student[studentsCount];

    CreateStructure(students, studentsCount); DisplayStructure(students, studentsCount);

    cout << "\nКількість оцінок \"добре\" з кожного предмету: " << GoodGradesCount(students, studentsCount)
        << "\nВідсоток студентів, які отримали з фізики та математики оцінку \"5\": "
        << WellDoingPhysicsAndMathStudentsPercent(students, studentsCount) << "%" << endl;
}