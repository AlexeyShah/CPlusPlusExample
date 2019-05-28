#include <algorithm>
#include <iostream>
#include <string>
#include <ctime>
#include <vector>
using namespace std;

bool checkDate(int month, int day, int year);

struct employee {
public:

	string fistName = "";
	string lastName = "";
	string patronymic = "";
	string position = "";
	time_t t = time(NULL);
	struct tm* dateReciept = localtime(&t);
	struct tm* appointmentDate = localtime(&t);
	double amountCasing = 0.;

	employee() {};

	employee(string fistName, string lastName, string patronymic, string position, tm* dateReciept, tm* appointmentDate, double amountCasing) {
		this->fistName = fistName;
		this->lastName = lastName;
		this->patronymic = patronymic;
		this->position = position;
		this->dateReciept = dateReciept;
		this->appointmentDate = appointmentDate;
		this->amountCasing = amountCasing;
	};
	
	~employee() {};
	
	virtual void ShowEmployee() {
		cout << "Employee description." << endl;
		cout << "Employee fistName: " << this->fistName << endl;
		cout << "Employee lastName: " << this->lastName << endl;
		cout << "Employee patronymic: " << this->patronymic << endl;
		cout << "Employee position: " << this->position << endl;
		cout << "Employee date reciept: " << this->dateReciept << endl;
		cout << "Employee appointment date: " << this->appointmentDate << endl;
		cout << "Employee amount casing: " << this->amountCasing << endl;
	}
};

struct less_than_key
{
	inline bool operator() (const employee& struct1, const employee& struct2)
	{
		return dateReciept;// (struct1.key < struct2.key);
	}
};

int main()
{
	vector<employee> empl;

	while (true) {
		string command;
		cout << "press enter Q for exit" << endl;
		cout << "press enter I for insert employee" << endl;
		cout << "press enter S for show employee" << endl;
		cout << "press enter sort for show employee" << endl;
		cout << "press enter Q for exit" << endl;
		getline(cin, command);

		if (command == "S") {

			cout << endl;

			for (int i = 0; i < empl.size(); i++) {
				cout << empl[i].ShowEmployee;
			}

			cout << endl;

		}
		else if (command == "Q") {
			break;
		}
		else if (command == "I") {

			time_t t = time(NULL);
			struct tm* dateReciept = localtime(&t);
			struct tm* appointmentDate = localtime(&t);

			cout << endl << endl;
			string fistName, lastName, patronymic, position, dateRecieptStr, appointmentDateStr;
			double amountCasing;

			cout << "enter fistName :"; cin >> fistName;
			cout << "enter lastName :"; cin >> lastName;
			cout << "enter patronymic :"; cin >> patronymic;
			cout << "enter position :"; cin >> position;
			cout << "enter date reciept [dd:mm:yyyy] :"; cin >> dateRecieptStr;
			cout << "enter appointment date [dd:mm:yyyy] :"; cin >> appointmentDateStr;
			cout << "enter amount casing :"; cin >> amountCasing;

			if (dateRecieptStr.length == 10) {
				int dd = atoi(dateRecieptStr.substr(0, 2).c_str());
				int mm = atoi(dateRecieptStr.substr(3, 2).c_str());
				int yy = atoi(dateRecieptStr.substr(6, 4).c_str());

				dateReciept->tm_year = yy;
				dateReciept->tm_mon = mm - 1;
				dateReciept->tm_mday = dd;
			}

			if (appointmentDateStr.length == 10) {
				int dd = atoi(appointmentDateStr.substr(0, 2).c_str());
				int mm = atoi(appointmentDateStr.substr(3, 2).c_str());
				int yy = atoi(appointmentDateStr.substr(6, 4).c_str());

				appointmentDate->tm_year = yy;
				appointmentDate->tm_mon = mm - 1;
				appointmentDate->tm_mday = dd;
			}

			employee emplPerson = employee(fistName, lastName, patronymic, position, dateReciept, appointmentDate, amountCasing);
			empl.push_back(emplPerson);

			sort(empl.begin(), empl.end(), less_than_key());
		}
		else {
			cout << "unknown command";
		}
	}

	return 0;
}



bool checkDate(int month, int day, int year)
{
	time_t t = time(NULL);
	struct tm* aTime = localtime(&t);
	bool valid = true;
	if ((month = 1) || (month = 3) || (month = 5) || (month = 7) ||
		(month = 8) || (month = 10) || (month = 12))
	{
		valid &= day <= 31;
	}
	else if ((month = 4) || (month = 6) || (month = 9) || (month = 11))
	{
		valid &= day <= 30;
	}
	else if ((month = 2) && (year % 4 == 0))
	{
		valid &= day <= 29;
	}
	else if ((month = 2) && (year % 4 != 0))
	{
		valid &= day <= 28;
	};

	if (year > (aTime->tm_year + 1900))
	{
		valid &= false;
	}

	if ((month < 1) || (month > 12))
	{
		valid &= false;
	}
	return valid;
};