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
    ~Student();
    std::string getFullName();
    int getCourse();
    int get_year();
    std::string get_name();
    std::string get_surname();
    void set_name(std::string name);
    void set_surname(std::string surname);
    void set_year(int year);
};
Student::Student(std::string name, std::string surname, int year){
    _name = name;
    _surname = surname;
    _year = year;
}
std::string Student::getFullName() {
    return _name + _surname;
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
Student::~Student() {

}

int main() {
    std::cout << "\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n";
    std::cout << "Hello, World!" << std::endl;

    std::vector<Student> students_entry;
    std::string name, surname;
    int year, student_index, i;

    bool exit = false;
    char command;
    while (!exit) {
        std::cout << "\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n";
        std::cout << "Что вы хотите сделать?:\n";
        std::cout << "\t1. Создать запись о студенте.\n";
        std::cout << "\t2. Создать запись о студенте с полными данными - автор, название, год выпуска.\n";
        //std::cout << "\t3. Создать запись о студенте с частичными данными - имя автора и название книги.\n";
        //std::cout << "\t4. Создать запись о студенте с частичными данными - название книги и год выпуска.\n";
        //std::cout << "\t5. Создать запись о студенте с частичными данными - первая буква имени автора и название книги.\n";
        std::cout << "\t6. Редактировать запись о книге - изменить или ввести имя студенте.\n";
        std::cout << "\t7. Редактировать запись о книге - изменить или ввести фамилию студенте.\n";
        std::cout << "\t8. Редактировать запись о книге - изменить или ввести год поступления студенте.\n";
        std::cout << "\t9. Посмотреть данные о записанных книгах.\n";
        std::cout << "\t0. Выход из программы\n";
        std::cout << "Команда: ";
        std::cin >> command;
        std::cin.ignore();
        switch (command) {
            case '1':
                students_entry.push_back(Student(name, surname, year));
                break;

            /*case '2':
                author = enter_author();
                name = enter_book();
                year = enter_year();
                books_entry.push_back(Book(author, name, year));
                break;

            case '3':
                author = enter_author();
                name = enter_book();
                books_entry.push_back(Book(author, name));
                break;

            case '4':
                name = enter_book();
                year = enter_year();
                books_entry.push_back(Book(name, year));
                break;

            case '5':
                letter = first_letter();
                name = enter_book();
                books_entry.push_back(Book(letter, name));
                break;

            case '6':
                for (i = 0; i < size(books_entry); i++) {
                    std::cout << i << " ";
                    books_entry[i].display_info();
                }
                std::cout << "Для которой по номеру записи вы хотите изменить данные?\n";
                std::cin >> book_index;
                std::cin.ignore();
                if (book_index >= 0 && book_index < size(books_entry)) {
                    author = enter_author();
                    books_entry[book_index].set_author(author);
                } else {
                    std::cout << "Введен неверный номер записи." << std::endl;
                }
                break;

            case '7':
                for (i = 0; i < size(books_entry); i++) {
                    std::cout << i << " ";
                    books_entry[i].display_info();
                }
                std::cout << "Для которой по номеру записи вы хотите изменить данные?\n";
                std::cin >> book_index;
                std::cin.ignore();
                if (book_index >= 0 && book_index < size(books_entry)) {
                    name = enter_book();
                    books_entry[book_index].set_book(name);
                } else {
                    std::cout << "Введен неверный номер записи." << std::endl;
                }
                break;

            case '8':
                for (i = 0; i < size(books_entry); i++) {
                    std::cout << i << " ";
                    books_entry[i].display_info();
                }
                std::cout << "Для которой по номеру записи вы хотите изменить данные?\n";
                std::cin >> book_index;
                std::cin.ignore();
                if (book_index >= 0 && book_index < size(books_entry)) {
                    year = enter_year();
                    books_entry[book_index].set_year(year);
                } else {
                    std::cout << "Введен неверный номер записи." << std::endl;
                }
                break;

            case '9':
                for (i = 0; i < size(books_entry); i++) {
                    books_entry[i].display_info();
                }
                break;
                */

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