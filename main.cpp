#include <iostream>
#include <string>
#include <vector>

class Student{
private:
    std::string _name;
    std::string _surname;
    int _year;
public:
    Student(std::string name, std::string surname, int year);
    //Student(const Student &student);
    Student(std::string name, std::string surname);
    Student(std::string surname, int year);
    ~Student();
    void getFullName();
    int getCourse();
    int get_year();
    std::string get_name();
    std::string get_surname();
    void set_name(std::string name);
    void set_surname(std::string surname);
    void set_year(int year);

    void display_info();
};
Student::Student(std::string name, std::string surname, int year){
    _name = name;
    _surname = surname;
    _year = year;
}
Student::Student(std::string name, std::string surname)
{
    this->_name = name;
    this->_surname = surname;
    _year = 0;
}
Student::Student(std::string book, int year)
{
    this->_surname = book;
    this->_year = year;
}
void Student::getFullName() {
    if ((!empty(_name))&&(!std::empty(_surname)))
    {
        std::cout << "Полное имя студента: " << _name << " " << _surname << std::endl;
    }
}
int Student::getCourse() {
    return 2022 - _year;
}
int Student::get_year() {
    return _year;
}
std::string Student::get_name() {
    return _name;
}
std::string Student::get_surname() {
    return _surname;
}
void Student::set_name(std::string name) {
    _name =  name;
}
void Student::set_surname(std::string surname) {
    _surname = surname;
}
void Student::set_year(int year) {
    _year = year;
}

void Student::display_info()
{
    if (!empty(_name))
    {
        std::cout << "Имя студента: " << _name << std::endl;
    }
    if (!empty(_surname))
    {
        std::cout << "Фамилия студента: " << _surname << std::endl;
    }
    if (_year != 0)
    {
        std::cout << "Год поступления студента: " << _year << std::endl;
        std::cout << "Курс: " << getCourse() << std::endl;
    }

    std::cout << "-*-*-*-*-*-*-*-*-*-*-*" << std::endl;
}

Student::~Student() {

}

std::string enter_name()
{
    std::string name;
    std::cout << "Введите имя студента:" << std::endl;
    getline(std::cin, name);
    return name;
}

std::string enter_surname()
{
    std::string name;
    std::cout << "Введите фамилию студента:" << std::endl;
    getline(std::cin, name);
    return name;
}

int enter_year()
{
    int year;
    std::cout << "Введите год поступления студента:" << std::endl;
    std::cin >> year;
    return year;
}
int main() {
    std::cout << "\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n";
    std::cout << "Hello, World!" << std::endl;

    std::vector<Student> students_entry;
    std::string name, surname;
    int year, student_index, i;

    students_entry.push_back(Student(name="Иван", surname="Иванов", year=2021));
    students_entry.push_back(Student(name="Пётр", surname="Петров", year=2020));
    students_entry.push_back(Student(name="Степан", surname="Сидоров", year=2019));

    bool exit = false;
    char command;
    while (!exit) {
        std::cout << "\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n";
        std::cout << "Что вы хотите сделать?:\n";
        std::cout << "\t1. Создать запись о студенте.\n";
        std::cout << "\t2. Создать запись о студенте с полными данными - имя, фамилия, год поступления.\n";
        std::cout << "\t3. Создать запись о студенте с частичными данными - имя студента и фамилия.\n";
        std::cout << "\t4. Создать запись о студенте с частичными данными - имя студента и год поступления.\n";
        //std::cout << "\t5. Создать запись о студенте с частичными данными - первая буква имени автора и название книги.\n";
        std::cout << "\t5. Редактировать запись о студенте - изменить или ввести имя студенте.\n";
        std::cout << "\t6. Редактировать запись о студенте - изменить или ввести фамилию студенте.\n";
        std::cout << "\t7. Редактировать запись о студенте - изменить или ввести год поступления студенте.\n";
        std::cout << "\t8. Посмотреть данные о записанных студентaх.\n";
        std::cout << "\t0. Выход из программы\n";
        std::cout << "Команда: ";
        std::cin >> command;
        std::cin.ignore();
        switch (command) {
            case '1':
                students_entry.push_back(Student(name, surname, year));
                break;

            case '2':
                name = enter_name();
                surname = enter_surname();
                year = enter_year();
                students_entry.push_back(Student(name, surname, year));
                break;

            case '3':
                name = enter_name();
                name = enter_surname();
                students_entry.push_back(Student(name, name));
                break;

            case '4':
                name = enter_surname();
                year = enter_year();
                students_entry.push_back(Student(name, year));
                break;

            case '5':
                for (i = 0; i < size(students_entry); i++) {
                    std::cout << i << " ";
                    students_entry[i].getFullName();
                    std::cout << "Курс: " << students_entry[i].getCourse() << std::endl;
                }
                std::cout << "Для которой по номеру записи вы хотите изменить данные?\n";
                std::cin >> student_index;
                std::cin.ignore();
                if (student_index >= 0 && student_index < size(students_entry)) {
                    name = enter_name();
                    students_entry[student_index].set_name(name);
                } else {
                    std::cout << "Введен неверный номер записи." << std::endl;
                }
                break;

            case '6':
                for (i = 0; i < size(students_entry); i++) {
                    std::cout << i << " ";
                    students_entry[i].getFullName();
                    std::cout << "Курс: " << students_entry[i].getCourse() << std::endl;
                }
                std::cout << "Для которой по номеру записи вы хотите изменить данные?\n";
                std::cin >> student_index;
                std::cin.ignore();
                if (student_index >= 0 && student_index < size(students_entry)) {
                    name = enter_surname();
                    students_entry[student_index].set_surname(name);
                } else {
                    std::cout << "Введен неверный номер записи." << std::endl;
                }
                break;

            case '7':
                for (i = 0; i < size(students_entry); i++) {
                    std::cout << i << " ";
                    students_entry[i].getFullName();
                    std::cout << "Курс: " << students_entry[i].getCourse() << std::endl;
                }
                std::cout << "Для которой по номеру записи вы хотите изменить данные?\n";
                std::cin >> student_index;
                std::cin.ignore();
                if (student_index >= 0 && student_index < size(students_entry)) {
                    year = enter_year();
                    students_entry[student_index].set_year(year);
                }
                else {
                    std::cout << "Введен неверный номер записи." << std::endl;
                }
                break;

            case '8':
                for (i = 0; i < size(students_entry); i++) {
                    students_entry[i].display_info();
                }
                break;

            case '0':
                exit = true;
                break;

            default:
                std::cout << "Вы ввели некорректную команду. Введите от 0 до 9." << std::endl;
                break;
        }
    }
    return 0;
}