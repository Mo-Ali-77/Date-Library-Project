#pragma once
#pragma warning(disable: 4996)
#include<iostream>
#include<string>
#include<vector>

using namespace std;


// My Solution: Mo Ali
class clsDate
{
	short _Year = 0;
	short _Month = 0;
	short _Day = 0;
	short _DayIndex = 0;


	clsDate _SystemDateNow()
	{
		time_t t_bySecond = time(NULL);
		tm* TimeNow = localtime(&t_bySecond);
		
		_Day = TimeNow->tm_mday;
		_Month = TimeNow->tm_mon + 1;
		_Year = TimeNow->tm_year + 1900;

		return *this;

		/*_Day = TimeNow->tm_mday;
		_Month = TimeNow->tm_mon + 1;
		_Year = TimeNow->tm_year + 1900;*/
	}

	vector<int> _SplitString(string Date, string Seperate= "/")
	{
		vector<int> vDate;
		string SubWord;
		short pos;
		while ((pos = Date.find(Seperate)) != std::string::npos)
		{
			SubWord = Date.substr(0, pos);

			if (SubWord != "")
			{
				vDate.push_back(stoi(SubWord));
			}

			Date.erase(0, pos + Seperate.length());
		}

		if (Date != "")
		{
			vDate.push_back(stoi(Date));
		}

		return vDate;
	}

	void _JoinDate(vector <int> vDate)
	{
		_Day = vDate[0];
		_Month = vDate[1];
		_Year = vDate[2];
	}

	enum _enMonths { Jan = 1, Feb = 2, Mar = 3, Apr = 4, May = 5, Jun = 6, Jul = 7, Aug = 8, Sep = 9, Oct = 10, Nov = 11, Dec = 12 };

	void _DrowMonthHeader(short Month)
	{
		printf("\n --------------- %s ---------------\n\n", MonthName(Month).c_str());
	}

	void _DrawingTheInnerShapeOfTheMonth(clsDate Date)
	{	
		short DayOrder = GetWeekdayIndex(Date);

		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

		short i;
		for (i = 0; i < DayOrder; i++)
		{
			printf("     ");
		}

		short NumberOfDaysinMonth = GetDaysInMonth(Date._Year, Date._Month);

		for (short j = 1; j <= NumberOfDaysinMonth; j++)
		{
			printf("%5d", j);

			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}
		}
	}

	void _DrowMonthFooter()
	{
		printf("\n -----------------------------------\n\n");
	}

	void _DrowYearHeader(short Year)
	{
		printf(" \n--------------------------------------------------\n");
		printf("\n			Calender - %d\n", Year);
		printf(" \n--------------------------------------------------\n\n");
	}

	void _DrawingTheInnerShapeOfTheYear(short Year)
	{
		for (short i = 1; i <= 12; i++)
		{
			PrintMonthCalender(Year, i);
		}
	}

	enum _enWeekDays { Sun = 0, Mon = 1, Tue = 2, Wed = 3, Thu = 4, Fri = 5, Sat = 6 };

	enum _eCompareDate { Before = -1, Equal = 0, After = 1 };

	string _ReplaceWordInString(string S1, string StringToReplace, string sRepalceTo)
	{
		short pos = S1.find(StringToReplace);
		while (pos != std::string::npos)
		{
			S1 = S1.replace(pos, StringToReplace.length(), sRepalceTo);
			pos = S1.find(StringToReplace);
		}
		return S1;
	}

public:

	clsDate()
	{
		_SystemDateNow();
	}

	clsDate(string Date)
	{
		_JoinDate(_SplitString(Date));
	}

	clsDate(short Day, short Month, short Year)
	{
		_Day = Day;
		_Month = Month;
		_Year = Year;
	}

	clsDate(short DayOrder, short Year)
	{
		_Year = Year;
		*this = AddDaysToDate(*this,DayOrder);
	}

	short Year()
	{
		return _Year;
	}

	void SetYear(short Year)
	{
		_Year = Year;
	}

	__declspec(property(get = Year, put = SetYear)) short Year;

	short Month()
	{
		return _Month;
	}

	void SetMonth(short Month)
	{
		_Month = Month;
	}

	__declspec(property(get = Month, put = SetMonth)) short Month;

	short Day()
	{
		return _Day;
	}

	void SetDay(short Day)
	{
		_Day = Day;
	}

	__declspec(property(get = Day, put = SetDay)) short Day;

	static short ReadDay(const string Message)
	{
		short Number;
		cout << Message;
		cin >> Number;
		while (cin.fail() || Number < 1 || Number > 31)
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "\nInvaild the number, Please enter a vaild one? [1 to 31] or enter [1 to 29] if Month is Februry? ";
			cin >> Number;
		}
		return Number;
	}

	void ReadDay()
	{
		_Day = ReadDay("Please enter Day: ");
	}

	static short ReadMonth(const string Message)
	{
		int Number;
		cout << Message;
		cin >> Number;

		while (cin.fail() || (Number < 1 || Number > 12))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "\nInvaild the number, Please enter a vaild one? [1 to 12]? ";
			cin >> Number;
		}

		return Number;
	}

	void ReadMonth()
	{
		_Month = ReadMonth("Please enter Month: ");
	}

	static short ReadYear(const string Message)
	{
		short Number;
		cout << Message;
		cin >> Number;

		while (cin.fail() || Number <= 0)
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "\nInvaild the number, Please enter a vaild one? ";
			cin >> Number;
		}

		return Number;
	}

	void ReadYear()
	{
		_Year = ReadYear("Please enter Year: ");
	}

	static bool IsLeapYear(short Year)
	{
		return ((Year % 400 == 0) || ((Year % 4 == 0) && (Year % 100 != 0)));
	}

	bool IsLeapYear()
	{
		return IsLeapYear(_Year);
	}

	static short GetDaysInMonth(short Year, short Month)
	{
		short arrLastDayOfeachMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		return (Month == 2) ? IsLeapYear(Year) ? 29 : arrLastDayOfeachMonth[Month - 1] : arrLastDayOfeachMonth[Month - 1];
	}

	short GetDaysInMonth()
	{
		return GetDaysInMonth(_Year, _Month);
	}

	static short TotalDaysFromtheBeginningOfYear(short Year, short Month, short Day)
	{
		short i, Count = 0;
		for (i = 1; i <= Month - 1; i++)
		{
			Count += GetDaysInMonth(Year, i);
		}
		Count += Day;

		return Count;
	}
	
	short TotalDaysFromtheBeginningOfYear()
	{
		return TotalDaysFromtheBeginningOfYear(_Year, _Month, _Day);
	}

	static clsDate AddDaysToDate(clsDate Date, short Days)
	{
		short RemainingDays = Days + TotalDaysFromtheBeginningOfYear(Date._Year, Date._Month, Date._Day);
		short MonthDays = 0;
		Date._Month = 1;

		while (true)
		{
			MonthDays = GetDaysInMonth(Date._Year, Date._Month);
			if (MonthDays < RemainingDays)
			{
				RemainingDays -= MonthDays;
				Date._Month++;

				if (Date._Month > 12)
				{
					Date._Month = 1;
					Date._Year++;
				}
			}
			else
			{
				Date._Day = RemainingDays;
				break;
			}
		}

		return Date;
	}

	void AddDaysToDate(short Day)
	{
		*this =  AddDaysToDate(*this, Day);
	}

	static void ReadFullDate(clsDate &Date)
	{
		Date._Day = ReadDay("\nPlease enter a Day? ");
		Date._Month = ReadMonth("\nPlease enter a Month? ");
		Date._Year = ReadYear("\nPlease enter a Year? ");
	}

	void ReadFullDate()
	{
		ReadFullDate(*this);
	}

	static short GetWeekdayIndex(clsDate Date)
	{
		short a, y, m;
		a = (14 - Date._Month) / 12;
		y = Date._Year - a;
		m = Date._Month + (12 * a) - 2;
		return (Date._Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}

	short GetWeekdayIndex()
	{
		return GetWeekdayIndex(*this);
	}

	static string MonthName(short Month)
	{
		switch (Month)
		{
		case _enMonths::Jan:
			return "Jan";
		case _enMonths::Feb:
			return "Feb";
		case _enMonths::Mar:
			return "Mar";
		case _enMonths::Apr:
			return "Apr";
		case _enMonths::May:
			return "May";
		case _enMonths::Jun:
			return "Jun";
		case _enMonths::Jul:
			return "Jul";
		case _enMonths::Aug:
			return "Aug";
		case _enMonths::Sep:
			return "Sep";
		case _enMonths::Oct:
			return "Oct";
		case _enMonths::Nov:
			return "Nov";
		case _enMonths::Dec:
			return "Dec";
		}
	}

	string MonthName()
	{
		return MonthName(_Month);
	}

	static void PrintMonthCalender(short Year, short Month)
	{
		clsDate Temp;
		Temp._Year = Year;
		Temp._Month = Month;
		Temp._Day = 1;
		Temp._DrowMonthHeader(Month);
		Temp._DrawingTheInnerShapeOfTheMonth(Temp);
		Temp._DrowMonthFooter();
	}

	void PrintMonthCalender()
	{
		PrintMonthCalender(_Year, _Month);
	}

	static void PrintYearCalender(short Year)
	{
		clsDate temp;
		temp._DrowYearHeader(Year);
		temp._DrawingTheInnerShapeOfTheYear(Year);
	}

	void PrintYearCalender()
	{
		PrintYearCalender(_Year);
	}

	static bool IsValideDate(clsDate Date)
	{
		if ((Date._Day < 1 || Date._Day > 31) || (Date._Month < 1 || Date._Month > 12))
			return false;
		if (Date._Month == 2)
		{
			if (IsLeapYear(Date._Year) && (Date._Day > 28))
				return true;
			else if (Date._Day > 28)
				return false;

		}

		short MonthDays = GetDaysInMonth(Date._Year, Date._Month);
		if (Date._Day > MonthDays)
			return false;

		return true;
	}

	bool IsValideDate()
	{
		return IsValideDate(*this);
	}

	static string DayName(short dayIndex)
	{
		switch (dayIndex)
		{
		case _enWeekDays::Sun:
			return "Sun";
		case _enWeekDays::Mon:
			return "Mon";
		case _enWeekDays::Tue:
			return "Tue";
		case _enWeekDays::Wed:
			return "Wed";
		case _enWeekDays::Thu:
			return "Thu";
		case _enWeekDays::Fri:
			return "Fri";
		case _enWeekDays::Sat:
			return "Sat";
		default:
			"Out of Range.";
			break;
		}
	}

	string DayName()
	{
		return DayName(_DayIndex);
	}

	static clsDate GetDateFromDayOrderInYear(short TotalDays, short Year)
	{
		clsDate Date;
		short RemainingDays = TotalDays;
		short MonthDays = 0;
		Date._Year = Year;
		Date._Month = 1;

		while (true)
		{
			MonthDays = GetDaysInMonth(Year, Date._Month);
			if (MonthDays < RemainingDays)
			{
				RemainingDays -= MonthDays;
				Date._Month++;
			}
			else
			{
				Date._Day = RemainingDays;
				break;
			}
		}

		return Date;
	}

	void GetDateFromDayOrderInYear(short TotalDays)
	{
		*this = GetDateFromDayOrderInYear(TotalDays, _Year);
	}

	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
	{
		return Date1._Year < Date2._Year ? true : Date1._Year == Date2._Year ? Date1._Month < Date2._Month ? true : Date1._Month == Date2._Month ? Date1._Day < Date2._Day : false : false;
	}

	bool IsCurrentDateBeforEnterDate(clsDate EnterDate)
	{
		return IsDate1BeforeDate2(*this, EnterDate);
	}

	static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1._Year == Date2._Year) && (Date1._Month == Date2._Month) && (Date1._Day == Date2._Day) ? true : false;
	}

	bool IsCurrentDateEqualEnterDate(clsDate EnterDate)
	{
		return IsDate1EqualDate2(*this, EnterDate);
	}

	static bool IsLastDayInMonth(clsDate Date)
	{
		return (Date._Day == GetDaysInMonth(Date._Year, Date._Month));
	}

	bool IsLastDayInMonth()
	{
		return IsLastDayInMonth(*this);
	}

	static bool IsLastMonthInYear(short Month)
	{
		return (Month == 12);
	}

	bool IsLastMonthInYear()
	{
		return IsLastMonthInYear(_Month);
	}

	static clsDate IncreaseDateByOneDay(clsDate Date)
	{
		
		if (IsLastDayInMonth(Date))
		{
			if (IsLastMonthInYear(Date._Month))
			{
				Date._Day = 1;
				Date._Month = 1;
				Date._Year++;
			}
			else
			{
				Date._Day = 1;
				Date._Month++;
			}
		}
		else
		{
			Date._Day++;
		}

		return Date;
	}
	
	void IncreaseDateByOneDay()
	{
		*this = IncreaseDateByOneDay(*this);
	}

	static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
	{
		int Days = 0;
		while (IsDate1BeforeDate2(Date1, Date2))
		{
			Days++;
			Date1 = IncreaseDateByOneDay(Date1);
		}

		return IncludeEndDay ? ++Days : Days;
	}

	int GetDifferenceInDays(clsDate Date2, bool IncludeEndDay = false)
	{
		return GetDifferenceInDays(*this, Date2, IncludeEndDay);
	}

	static int YourAgeByDays(clsDate YourBirthDate)
	{
		clsDate Temp;
		return GetDifferenceInDays(YourBirthDate, Temp._SystemDateNow(), true);
	}

	int YourAgeByDays()
	{
		
		return YourAgeByDays(*this);
	}

	static clsDate IncreaseDateByXDays(clsDate Date, int DaysNumber)
	{
		for (int i = 0; i < DaysNumber; i++)
		{
			Date = IncreaseDateByOneDay(Date);
		}

		return Date;
	}

	void IncreaseDateByXDays(int DaysNumber)
	{
		*this = IncreaseDateByXDays(*this, DaysNumber);
	}

	static clsDate IncreaseDateByOneWeek(clsDate Date)
	{
		Date = IncreaseDateByXDays(Date, 7);

		return Date;
	}

	void IncreaseDateByOneWeek()
	{
		*this = IncreaseDateByOneWeek(*this);
	}

	static clsDate IncreaseDateByXWeeks(clsDate Date, int WeeksNumber)
	{
		for (int i = 0; i < WeeksNumber; i++)
		{
			Date = IncreaseDateByOneWeek(Date);
		}

		return Date;
	}

	void IncreaseDateByXWeeks(int WeeksNumber)
	{
		*this = IncreaseDateByXWeeks(*this, WeeksNumber);
	}

	static clsDate IncreaseDateByOneMonth(clsDate Date)
	{
		if (IsLastMonthInYear(Date._Month))
		{
			Date._Month = 1;
			Date._Year++;
		}
		else
		{
			Date._Month++;
		}

		short LastDayInMonth = GetDaysInMonth(Date._Year, Date._Month);
		if (Date._Day > LastDayInMonth)
		{
			Date._Day = LastDayInMonth;
		}

		return Date;
	}

	void IncreaseDateByOneMonth()
	{
		*this = IncreaseDateByOneMonth(*this);
	}

	static clsDate IncreaseDateByXMonths(clsDate Date, int MonthsNumber)
	{
		for (int i = 0; i < MonthsNumber; i++)
		{
			Date = IncreaseDateByOneMonth(Date);
		}

		return Date;
	}

	void IncreaseDateByXMonths(int MonthsNumber)
	{
		*this = IncreaseDateByXMonths(*this, MonthsNumber);
	}

	static clsDate IncreaseDateByOneYear(clsDate Date)
	{
		Date._Year++;
		return Date;
	}

	void IncreaseDateByOneYear()
	{
		*this = IncreaseDateByOneYear(*this);
	}

	static clsDate IncreaseDateByXYear(clsDate Date, int YearsNumber)
	{
		for (int i = 0; i < YearsNumber; i++)
		{
			Date = IncreaseDateByOneYear(Date);
		}

		return Date;
	}

	void IncreaseDateByXYear(int YearsNumber)
	{
		*this = IncreaseDateByXYear(*this, YearsNumber);
	}

	static clsDate IncreaseDateByXYearFaster(clsDate Date, int YearsNumber)
	{
		for (int i = 0; i < YearsNumber; i++)
		{
			Date._Year++;
		}

		return Date;
	}

	void IncreaseDateByXYearFaster(int YearsNumber)
	{
		*this = IncreaseDateByXYearFaster(*this, YearsNumber);
	}

	static clsDate IncreaseDateByOneDecade(clsDate Date)
	{
		Date = IncreaseDateByXYearFaster(Date, 10);

		return Date;
	}

	void IncreaseDateByOneDecade()
	{
		*this = IncreaseDateByOneDecade(*this);
	}

	static clsDate IncreaseDateByXDecade(clsDate Date, int DecadesNumber)
	{
		for (int i = 0; i < DecadesNumber; i++)
		{
			Date = IncreaseDateByOneDecade(Date);
		}

		return Date;
	}

	void IncreaseDateByXDecade(int DecadesNumber)
	{
		*this = IncreaseDateByXDecade(*this, DecadesNumber);
	}

	static clsDate IncreaseDateByXDecadeFaster(clsDate Date, int DecadesNumber)
	{
		for (int i = 0; i < DecadesNumber; i++)
		{
			Date._Year += 10;
		}

		return Date;
	}

	void IncreaseDateByXDecadeFaster(int DecadesNumber)
	{
		*this = IncreaseDateByXDecadeFaster(*this, DecadesNumber);
	}

	static clsDate IncreaseDateByOneCentury(clsDate Date)
	{
		Date._Year += 100;

		return Date;
	}

	void IncreaseDateByOneCentury()
	{
		*this = IncreaseDateByOneCentury(*this);
	}

	static clsDate IncreaseDateByXCentury(clsDate Date, int CenturyNumber)
	{
		for (int i = 0; i < CenturyNumber; i++)
		{
			Date._Year += 100;
		}

		return Date;
	}

	void IncreaseDateByXCentury(int CenturyNumber)
	{
		*this = IncreaseDateByXCentury(*this, CenturyNumber);
	}

	static clsDate IncreaseDateByOneMillennium(clsDate Date)
	{
		Date._Year += 1000;

		return Date;
	}

	void IncreaseDateByOneMillennium()
	{
		*this = IncreaseDateByOneMillennium(*this);
	}

	static clsDate IncreaseDateByXMillennium(clsDate Date, int MillenniumNumber)
	{
		for (int i = 0; i < MillenniumNumber; i++)
		{
			Date._Year += 1000;
		}

		return Date;
	}

	void IncreaseDateByXMillennium(int MillenniumNumber)
	{
		*this = IncreaseDateByXMillennium(*this, MillenniumNumber);
	}

	static clsDate DecreaseDateByOneDay(clsDate Date)
	{
		if (Date._Day == 1)
		{
			if (Date._Month == 1)
			{
				Date._Day = 31;
				Date._Month = 12;
				Date._Year--;
			}
			else
			{
				Date._Month--;
				Date._Day = GetDaysInMonth(Date._Year, Date._Month);
			}
		}
		else
		{
			Date._Day--;
		}

		return Date;
	}

	void DecreaseDateByOneDay()
	{
		*this = DecreaseDateByOneDay(*this);
	}

	static clsDate DecreaseDateByXDays(clsDate Date, int DaysNumber)
	{
		for (int i = 0; i < DaysNumber; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}

		return Date;
	}

	void DecreaseDateByXDays(int DaysNumber)
	{
		*this = DecreaseDateByXDays(*this, DaysNumber);
	}

	static clsDate DecreaseDateByOneWeek(clsDate Date)
	{
		Date = DecreaseDateByXDays(Date, 7);

		return Date;
	}

	void DecreaseDateByOneWeek()
	{
		*this = DecreaseDateByOneWeek(*this);
	}

	static clsDate DecreaseDateByXWeeks(clsDate Date, int WeeksNumber)
	{
		for (int i = 0; i < WeeksNumber; i++)
		{
			Date = DecreaseDateByOneWeek(Date);
		}

		return Date;
	}

	void DecreaseDateByXWeeks(int WeeksNumber)
	{
		*this = DecreaseDateByXWeeks(*this, WeeksNumber);
	}

	static clsDate DecreaseDateByOneMonth(clsDate Date)
	{
		if (Date._Month == 1)
		{		 
			Date._Month = 12;
			Date._Year--;
		}
		else
		{
			Date._Month--;
		}


		if (Date._Day == 1)
		{
			Date._Day = GetDaysInMonth(Date._Year, Date._Month);
		}

		return Date;
	}

	void DecreaseDateByOneMonth()
	{
		*this = DecreaseDateByOneMonth(*this);
	}

	static clsDate DecreaseDateByXMonths(clsDate Date, int MonthsNumber)
	{
		for (int i = 0; i < MonthsNumber; i++)
		{
			Date = DecreaseDateByOneMonth(Date);
		}

		return Date;
	}

	void DecreaseDateByXMonths(int MonthsNumber)
	{
		*this = DecreaseDateByXMonths(*this, MonthsNumber);
	}

	static clsDate DecreaseDateByOneYear(clsDate Date)
	{
		Date._Year--;
		return Date;
	}

	void DecreaseDateByOneYear()
	{
		*this = DecreaseDateByOneYear(*this);
	}

	static clsDate DecreaseDateByXYear(clsDate Date, int YearsNumber)
	{
		for (int i = 0; i < YearsNumber; i++)
		{
			Date = DecreaseDateByOneYear(Date);
		}

		return Date;
	}
	
	void DecreaseDateByXYear(int YearsNumber)
	{
		*this = DecreaseDateByXYear(*this, YearsNumber);
	}

 	static clsDate DecreaseDateByXYearFaster(clsDate Date, int YearsNumber)
	{
		for (int i = 0; i < YearsNumber; i++)
		{
			Date._Year--;
		}

		return Date;
	}

	void DecreaseDateByXYearFaster(int YearsNumber)
	{
		*this = DecreaseDateByXYearFaster(*this, YearsNumber);
	}

	static clsDate DecreaseDateByOneDecade(clsDate Date)
	{
		Date = DecreaseDateByXYearFaster(Date, 10);

		return Date;
	}

	void DecreaseDateByOneDecade()
	{
		*this = DecreaseDateByOneDecade(*this);
	}

	static clsDate DecreaseDateByXDecade(clsDate Date, int DecadesNumber)
	{
		for (int i = 0; i < DecadesNumber; i++)
		{
			Date = DecreaseDateByOneDecade(Date);
		}

		return Date;
	}

	void DecreaseDateByXDecade(int DecadesNumber)
	{
		*this = DecreaseDateByXDecade(*this, DecadesNumber);
	}

	static clsDate DecreaseDateByXDecadeFaster(clsDate Date, int DecadesNumber)
	{
		for (int i = 0; i < DecadesNumber; i++)
		{
			Date._Year -= 10;
		}

		return Date;
	}

	void DecreaseDateByXDecadeFaster(int DecadesNumber)
	{
		*this = DecreaseDateByXDecadeFaster(*this, DecadesNumber);
	}

	static clsDate DecreaseDateByOneCentury(clsDate Date)
	{
		Date._Year -= 100;

		return Date;
	}

	void DecreaseDateByOneCentury()
	{
		*this = DecreaseDateByOneCentury(*this);
	}

	static clsDate DecreaseDateByXCentury(clsDate Date, int CenturyNumber)
	{
		for (int i = 0; i < CenturyNumber; i++)
		{
			Date._Year -= 100;
		}

		return Date;
	}

	void DecreaseDateByXCentury(int CenturyNumber)
	{
		*this = DecreaseDateByXCentury(*this, CenturyNumber);
	}

	static clsDate DecreaseDateByOneMillennium(clsDate Date)
	{
		Date._Year -= 1000;

		return Date;
	}

	void DecreaseDateByOneMillennium()
	{
		*this = DecreaseDateByOneMillennium(*this);
	}

	static clsDate DecreaseDateByXMillennium(clsDate Date, int MillenniumNumber)
	{
		for (int i = 0; i < MillenniumNumber; i++)
		{
			Date._Year -= 1000;
		}

		return Date;
	}

	void DecreaseDateByXMillennium(int MillenniumNumber)
	{
		*this = DecreaseDateByXMillennium(*this, MillenniumNumber);
	}

	static short DayPerYear(short Year)
	{
		return IsLeapYear(Year) ? 366 : 365;
	}

	short DayPerYear()
	{
		return IsLeapYear(_Year) ? 366 : 365;
	}

	static bool IsEndOfWeek(clsDate Date)
	{
		
		return GetWeekdayIndex(Date) == 6;
	}

	bool IsEndOfWeek()
	{
		return IsEndOfWeek(*this);
	}

	static bool IsWeekEnd(clsDate Date)	
	{
		short DayIndex = GetWeekdayIndex(Date);
		return (DayIndex == 5) || (DayIndex == 6);
	}

	bool IsWeekEnd()
	{
		return IsWeekEnd(*this);
	}

	static bool IsBusineesDay(clsDate Date)
	{
		return !IsWeekEnd(Date);
	}

	bool IsBusineesDay()
	{
		return IsBusineesDay(*this);
	}

	static short DaysUntilTheEndOfWeek(clsDate Date)
	{
		return 6 - GetWeekdayIndex(Date);
	}

	short DaysUntilTheEndOfWeek()
	{
		return DaysUntilTheEndOfWeek(*this);
	}

	static short DaysUntilTheEndOfMonth(clsDate Date)
	{
		clsDate EndOfMonth;
		EndOfMonth._Day = GetDaysInMonth(Date._Year, Date._Month);
		EndOfMonth._Month = Date._Month;
		EndOfMonth._Year = Date._Year;

		return GetDifferenceInDays(Date, EndOfMonth, true);
	}

	short DaysUntilTheEndOfMonth()
	{
		return DaysUntilTheEndOfMonth(*this);
	}

	static short DaysUntilTheEndOfYear(clsDate Date)
	{
		clsDate EndOfMonth;
		EndOfMonth._Day = 31;
		EndOfMonth._Month = 12;
		EndOfMonth._Year = Date._Year;

		return GetDifferenceInDays(Date, EndOfMonth, true);
	}

	short DaysUntilTheEndOfYear(clsDate Date)
	{
		return  DaysUntilTheEndOfYear(*this);
	}

	static short CaculateVacationDays(clsDate DateFrom, clsDate DateTo)
	{
		short Days = 0;
		while (IsDate1BeforeDate2(DateFrom, DateTo))
		{
			if (IsBusineesDay(DateFrom))
				Days++;

			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		return Days;
	}

	short CaculateVacationDays(clsDate DateTo)
	{
		return CaculateVacationDays(*this, DateTo);
	}

	static clsDate CalculateVacationReturnDate(clsDate DateFrom, short VacationDays)
	{
		short WeekEndCounter = 0;

		while (IsWeekEnd(DateFrom))
		{
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		for (short i = 1; i <= VacationDays + WeekEndCounter; i++)
		{

			if (IsWeekEnd(DateFrom))
				WeekEndCounter++;

			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		while (IsWeekEnd(DateFrom))
		{
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		return DateFrom;
	}

	void CalculateVacationReturnDate(short VacationDays)
	{
		*this = CalculateVacationReturnDate(*this, VacationDays);
	}

	static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
	{
		return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
	}

	bool IsDate1AfterDate2(clsDate Date2)
	{
		return IsDate1AfterDate2(*this, Date2);
	}

	static _eCompareDate CompareDates(clsDate Date1, clsDate Date2)
	{
		return IsDate1EqualDate2(Date1, Date2) ? _eCompareDate::Equal : IsDate1AfterDate2(Date1, Date2) ? _eCompareDate::After : _eCompareDate::Before;
	}

	_eCompareDate CompareDates(clsDate Date2)
	{
		return CompareDates(*this, Date2);
	}

	static bool IsValideDate(clsDate Date)
	{
		if ((Date._Day < 1 || Date._Day > 31) || (Date._Month < 1 || Date._Month > 12))
			return false;
		if (Date._Month == 2)
		{
			if (IsLeapYear(Date._Year) && (Date._Day > 28))
				return true;
			else if (Date._Day > 28)
				return false;

		}

		short MonthDays = GetDaysInMonth(Date._Year, Date._Month);
		if (Date._Day > MonthDays)
			return false;

		return true;
	}

	bool IsValideDate()
	{
		return IsValideDate(*this);
	}

	static clsDate StringToDate(string FullDate)
	{
		clsDate Date;
		vector <int> vDate;
		vDate = Date._SplitString(FullDate, "/");
		Date._Day = vDate[0];
		Date._Month = vDate[1];
		Date._Year = vDate[2];

		return Date;
	}

	static string DateToString(clsDate Date)
	{
		return to_string(Date._Day) + "/" + to_string(Date._Month) + "/" + to_string(Date._Year);
	}

	string DateToString(clsDate Date)
	{
		return DateToString(*this);
	}

	static string FormatDate(clsDate Date, string Format = "dd/mm/yyyy")
	{
		clsDate Temp;
		string FormattedDateString = "";
		FormattedDateString = Temp._ReplaceWordInString(Format, "dd", to_string(Date._Day));
		FormattedDateString = Temp._ReplaceWordInString(FormattedDateString, "mm", to_string(Date._Month));
		FormattedDateString = Temp._ReplaceWordInString(FormattedDateString, "yyyy", to_string(Date._Year));

		return FormattedDateString;
	}


	void Print()
	{
		cout << DateToString(*this) << endl;
	}

};
