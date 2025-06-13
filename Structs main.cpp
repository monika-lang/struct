#include <iostream>
#include "structs.h"
using namespace std;

void Point_location(Point point) {
	cout << "( " << point.x << " ; " << point.y << " )";
}


Student Student_init(const char* name, int age, int average_grade) {
	Student temp;
	int temp_size = strlen(name) + 1;
	temp.name = new char[temp_size];
	strcpy_s(temp.name, temp_size, name);

	temp.age = age;

	temp.average_grade = average_grade;

	return temp;

}


Student Student_init(Student& student) {
	char name[250];
	int age;
	int average_grade;
	cout << "\n-------------------Create Student Entry-------------------\n";
	cout << "Enter the name of the student: ";
	gets_s(name, 250);
	cout << "Enter their age: ";
	cin >> age;
	cout << "Enter their average grade: ";
	cin >> average_grade;

	
	return Student_init(name, age, average_grade);

	
}

void Student_print(Student student) {
	cout << "\n------------------------------------------------STUDENT NOTE------------------------------------------------\n\n";
	cout << "Student name: " << student.name << endl;
	cout << "Student age: " << student.age << endl;
	cout << "Student Average grade: " << student.average_grade;
	cout << "\n------------------------------------------------STUDENT NOTE------------------------------------------------\n\n";
}

int Rectangle_Area(Rectangle rect) {
	return (rect.length * rect.width);
}

void time_print(Time time) {
	cout << time.hours / 10 << time.hours % 10 << ":";
	cout << time.minutes / 10 << time.minutes % 10 << ":";
	cout << time.seconds / 10 << time.seconds % 10 << "\n";
}

Car car_init() {
	Car car;

	char * brand_name = new char[250];
	int year;
	double price;

	cout << "Enter the name of the car brand name: ";
	cin.ignore();
	gets_s(brand_name, 250);
	cout << "Enter the year of creation: ";
	cin >> year;
	cout << "Enter the price: ";
	cin >> price;

	car.Brand_name = brand_name;
	car.year_of_manufacture = year;
	car.price = price;

	return car;
}

void Car_print(Car car) {
	cout << "\n------CAR INFO------\n\n";
	cout << "Brand name: " << car.Brand_name << endl;
	cout << "Year of Manufacture: " << car.year_of_manufacture << endl;
	cout << "Price: " << car.price;
	cout << "\n\n------CAR INFO------\n\n";
}

void Date_print(Date date) {
	cout << date.day << "." << date.month << "." << date.year % 100 << "\n";
}

void person_info(Person person) {
	cout << "\n\n------PERSON INFO------\n\n";
	cout << "Name: " << person.name << "\n";
	cout << "Age: " << person.age << "\n";
	cout << "Height: " << person.height_in_meters << " meters\n";
	cout << "\n------PERSON INFO------\n\n";
}

void book_print(Book book) {
	cout << "\n\n------BOOK INFO------\n\n";
	cout << "Book name: " << book.title << "\n";
	cout << "Book author: " << book.author << "\n";
	cout << "Book release: " << book.age << "\n";
	cout << "\n------BOOK INFO------\n\n";
}

void Employee_print(Employee employee) {
	cout << "\n\n------EMPLOYEE INFO------\n\n";
	cout << "Employee name: " << employee.name << "\n";
	cout << "Employee position: " << employee.position << "\n";
	cout << "Employee salary per month: " << employee.salary_per_month << "\n";
	cout << "\n------EMPLOYEE INFO------\n\n";
}

void Correct_Triangle(Triangle tri) {
	if (tri.Side1 + tri.Side2 > tri.Side3 && tri.Side1 + tri.Side3 > tri.Side2 && tri.Side2 + tri.Side3 > tri.Side1) {
		cout << "Correct Triangle\n";
	}
	else {
		cout << "Incorrect Triangle\n";
	}
}

void Deletion (Student& student){
	if (student.name == nullptr) {
		return;
	}
	delete[] student.name;
}

void Deletion(Car& car) {
	if (car.Brand_name == nullptr) {
		return;
	}
	delete[] car.Brand_name;
}

void Deletion(Person person) {
	if (person.name == nullptr) {
		return;
	}
	delete[] person.name;
}

void Deletion(Book& book) {
	if (book.title == nullptr) {
		return;
	}
	delete[] book.title;
	delete[] book.author;
}
void Deletion(Employee& employee) {
	if (employee.name == nullptr) {
		return;
	}
	delete[] employee.name;
	delete[] employee.position;
}

int main() {

	{
		Point point = { 10, -8 };
		Point_location(point);
	}

	{
		Student Jack;

		Jack = Student_init(Jack);
		Student_print(Jack);
		Deletion(Jack);
	}

	{
		Rectangle rect;

		cout << "Enter the length of the rectangle: ";
		cin >> rect.length;
		cout << "Enter the width of the rectangle: ";
		cin >> rect.width;

		cout << "The Area of this recatngle is " << Rectangle_Area(rect) << " square units." << endl;

	}

	{
		Time clock;

		cout << "Enter what hour it is right now: ";
		cin >> clock.hours;
		cout << "Enter how many minutes there are right now: ";
		cin >> clock.minutes;
		cout << "Enter how many seconds there are rn: ";
		cin >> clock.seconds;

		time_print(clock);
	}

	{
		Car Citroen_C3;

		Citroen_C3 = car_init();

		Car_print(Citroen_C3);

		Deletion(Citroen_C3);

	}

	{
		Date date;

		cout << "Enter what year it is right now: ";
		cin >> date.year;
		cout << "Enter what month it is right now, in numbers: ";
		cin >> date.month;
		cout << "Enter what day of the month it is right now: ";
		cin >> date.day;
		Date_print(date);

	}

	{
		Person Fran;

		Fran.name = new char[250];
		cout << "Enter the name of the person: ";
		cin.ignore();
		gets_s(Fran.name, 250);
		cout << "Enter the age of the person: ";
		cin >> Fran.age;
		cout << "Enter the height of the person in meters: ";
		cin >> Fran.height_in_meters;

		person_info(Fran);

		Deletion(Fran);
	}

	{
		Book book;

		book.title = new char[250];
		book.author = new char[250];
		cout << "Enter the name of the book: ";
		cin.ignore();
		gets_s(book.title, 250);
		cout << "Enter the name of the author: ";
		gets_s(book.author, 250);
		cout << "Enter the year of release: ";
		cin >> book.age;

		book_print(book);

		Deletion(book);
	}

	{
		Employee Void;

		Void.name = new char[250];
		Void.position = new char[250];
		cout << "Enter the name of the employee: ";
		cin.ignore();
		gets_s(Void.name, 250);
		cout << "Enter the position of the employee: ";
		gets_s(Void.position, 250);
		cout << "Enter the slaray per month of this employee: ";
		cin >> Void.salary_per_month;

		Employee_print(Void);

		Deletion(Void);
	}

	{
		Triangle tri;

		cout << "Enter the length of the first side: ";
		cin >> tri.Side1;
		cout << "Enter the length of the second side: ";
		cin >> tri.Side2;
		cout << "Enter the length of the third side: ";
		cin >> tri.Side3;

		Correct_Triangle(tri);
	}
}