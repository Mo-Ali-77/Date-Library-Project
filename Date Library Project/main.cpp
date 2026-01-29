#include<iostream>
#include "clsDate.h"
using namespace std;

int main()
{
	clsDate Date1(22,4,2003);

	cout << "Your age by Days = " << Date1.YourAgeByDays();

	cout << "Date Now:\n";
	Date1.Print();
	cout << endl << endl;

	clsDate Date2 ("5/6/2026");

	cout << "String Date:\n";
	Date2.Print();
	cout << Date2.IsValideDate();
	cout << endl << endl;

	clsDate Date3(28,12,2026);

	cout << "int Date:\n";
	Date3.Print();
	cout << endl << endl;
	Date3.PrintYearCalender();


	cout << "\nAdd Days To Date:\n";
	clsDate Date4(250,2022);
	Date4.Print();

	Date4.PrintMonthCalender();


	clsDate Date5;

	Date5.IncreaseDateByOneDay();

	Date5.Print();


	clsDate Date6;

	Date6.IncreaseDateByXDays(10);

	Date6.Print();


	clsDate Date7;

	Date7.IncreaseDateByOneWeek();

	Date7.Print();

	clsDate Date8(31,1,2026);

	cout << Date8.GetWeekdayIndex() << endl;
	cout << Date8.IsEndOfWeek();
	Date8.Print();

	clsDate Date9;
	Date9.PrintMonthCalender();
	Date9.Print();

	system("pause>0");
	return 0;
}