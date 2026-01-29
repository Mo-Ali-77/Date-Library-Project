# Date Library (C++)
A comprehensive C++ library for date handling and manipulation, designed using Object-Oriented Programming (OOP) principles to provide clean, reusable, and practical solutions for real-world date operations.
---

## Project Overview
This project represents a practical implementation of advanced C++ concepts through building a full-featured Date Library.
The library focuses on managing dates, performing calculations, validations, comparisons, and formatting, all within a structured and maintainable class design.
---

## Educational Objectives (From Knowledge to Experience)

- Practical Application: Applying C++ concepts in a real-world date management system.

- Concept Integration: Combining core OOP concepts into one library:

- Static Members: Shared logic for date calculations and validation.

- Method Overloading: Supporting multiple ways to work with dates.

- Properties: Managing internal date state (Day, Month, Year).

- Skill Development: Moving from understanding syntax to building reusable and scalable software components.

## Technical Features

- Dual-Access Architecture: Each feature is provided in two forms:

- Static Functions: Used without creating an object (utility-style).

- Object Functions: Operate directly on the internal date stored in the object.

- Clean Code Design: Instance methods internally call static methods using overloading to avoid code duplication (DRY principle).

- Robust Validation: Ensures correct dates with leap year handling and range checks.

## Library API Reference

### 1️⃣ Constructors & Initialization

| Function	| Description |
| :--- | ---: |
| clsDate()	|	ينشئ كائن بتاريخ النظام الحالي.
| clsDate(string Date)	|	ينشئ تاريخ من نص بصيغة DD/MM/YYYY.
| clsDate(short Day, short Month, short Year)	|	ينشئ تاريخ يدويًا.
| clsDate(short DayOrderInYear, short Year)	|	ينشئ تاريخًا بناءً على ترتيب اليوم في السنة.	

### 2️⃣ Properties (Getters & Setters)

| Property	| Description |
| :--- | ---: |
| Day	| قراءة أو تعديل اليوم.|
| Month	| قراءة أو تعديل الشهر.|
| Year	| قراءة أو تعديل السنة.|

### 3️⃣ Validation & Leap Year

| Function	| Description |
| :--- | ---: |
| IsValidDate(Date)	|التحقق من صحة تاريخ معين (Static).|
| IsValid()	|التحقق من صحة تاريخ الكائن الحالي.|
| isLeapYear(Year)	|التحقق مما إذا كانت السنة كبيسة (Static).|
| isLeapYear()	|التحقق مما إذا كانت سنة الكائن كبيسة.|	

### 4️⃣ Date Conversion & Display

| Function	| Description |
| :--- | ---: |
| DateToString(Date)	|تحويل التاريخ إلى نص DD/MM/YYYY (Static).|
| DateToString()	|تحويل تاريخ الكائن إلى نص.|
| Print()	|طباعة التاريخ على الشاشة.|
| GetSystemDate()	|إرجاع تاريخ النظام الحالي.|

### 5️⃣ Days, Hours & Time Calculations

| Function	| Description |
| :--- | ---: |
| NumberOfDaysInAYear(Year)	|عدد أيام السنة.|
| NumberOfHoursInAYear(Year)	|عدد الساعات في السنة.|
| NumberOfMinutesInAYear(Year)	|عدد الدقائق في السنة.|
| NumberOfSecondsInAYear(Year)	|عدد الثواني في السنة.|
| NumberOfDaysInAMonth(Month,Year)	|عدد أيام شهر معين.|
| NumberOfHoursInAMonth(Month,Year)	|عدد ساعات شهر معين.|
| NumberOfMinutesInAMonth(Month,Year)	|عدد دقائق شهر معين.|
| NumberOfSecondsInAMonth(Month,Year)	|عدد ثواني شهر معين.|

### 6️⃣ Day & Month Information

| Function	| Description |
| :--- | ---: |
| DayOfWeekOrder(Day,Month,Year)	|إرجاع ترتيب اليوم (0 = Sun).|
| DayShortName()	|إرجاع اسم اليوم المختصر.|
| MonthShortName()	|إرجاع اسم الشهر المختصر.|

### 7️⃣ Calendars

| Function	| Description |
| :--- | ---: |
| PrintMonthCalendar(Month,Year)	|طباعة تقويم شهر معين.|
| PrintMonthCalendar()	|طباعة تقويم شهر الكائن.|
| PrintYearCalendar(Year)	|طباعة تقويم سنة كاملة.|
| PrintYearCalendar()	|طباعة تقويم سنة الكائن.|

### 8️⃣ Date Position & Ordering

| Function	| Description |
| :--- | ---: |
| DaysFromTheBeginingOfTheYear()	|عدد الأيام منذ بداية السنة.|
| GetDateFromDayOrderInYear(Order,Year)	|تحويل ترتيب اليوم إلى تاريخ.|

### 9️⃣ Date Comparison

| Function	| Description |
| :--- | ---: |
| IsDate1BeforeDate2(Date1,Date2)	|التحقق إذا كان تاريخ قبل آخر.|
| IsDate1AfterDate2(Date1,Date2)	|التحقق إذا كان تاريخ بعد آخر.|
| IsDate1EqualDate2(Date1,Date2)	|التحقق من تساوي تاريخين.|
| CompareDates(Date1,Date2)	|مقارنة تاريخين (Before / Equal / After).|

### 🔟 Date Difference & Age

| Function	| Description |
| :--- | ---: |
| GetDifferenceInDays(Date1,Date2)	|حساب الفرق بالأيام بين تاريخين.|
| CalculateMyAgeInDays(DateOfBirth)	|حساب العمر بالأيام.|

### 1️⃣1️⃣ Date Increase Operations

| Function	| Description |
| :--- | ---: |
| AddOneDay()	|زيادة يوم واحد.|
| AddDays(Days)	|إضافة عدد أيام.|
| IncreaseDateByOneWeek()	|زيادة أسبوع.|
| IncreaseDateByXWeeks(Weeks)	|زيادة عدة أسابيع.|
| IncreaseDateByOneMonth()	|زيادة شهر.|
| IncreaseDateByXMonths(Months)	|زيادة عدة أشهر.|
| IncreaseDateByOneYear()	|زيادة سنة.|
| IncreaseDateByXYears(Years)	|زيادة عدة سنوات.|
| IncreaseDateByOneDecade()	|زيادة 10 سنوات.|
| IncreaseDateByOneCentury()	|زيادة 100 سنة.|
| IncreaseDateByOneMillennium()	|زيادة 1000 سنة.

### 1️⃣2️⃣ Date Decrease Operations

| Function	| Description |
| :--- | ---: |
| DecreaseDateByOneDay()	|إنقاص يوم واحد.|
| DecreaseDateByOneWeek()	|إنقاص أسبوع.|
| DecreaseDateByXWeeks(Weeks)	|إنقاص عدة أسابيع.|
| DecreaseDateByOneMonth()	|إنقاص شهر.|
| DecreaseDateByXMonths(Months)	|إنقاص عدة أشهر.|
| DecreaseDateByOneYear()	|إنقاص سنة.|
| DecreaseDateByXYears(Years)	|إنقاص عدة سنوات.|
| DecreaseDateByOneDecade()	|إنقاص 10 سنوات.|
| DecreaseDateByOneCentury()	|إنقاص 100 سنة.|
| DecreaseDateByOneMillennium()	|إنقاص 1000 سنة.

### 1️⃣3️⃣ Business Days & Week Operations

| Function	| Description |
| :--- | ---: |
| IsWeekEnd()	|التحقق إذا كان اليوم عطلة.|
| IsBusinessDay()	|التحقق إذا كان يوم عمل.|
| IsEndOfWeek()	|التحقق إذا كان نهاية الأسبوع.|
| DaysUntilTheEndOfWeek()	|عدد الأيام حتى نهاية الأسبوع.|
| DaysUntilTheEndOfMonth()	|عدد الأيام حتى نهاية الشهر.|
| DaysUntilTheEndOfYear()	|عدد الأيام حتى نهاية السنة.

### 1️⃣4️⃣ Vacation & Business Calculations

| Function	| Description |
| :--- | ---: |
| CalculateBusinessDays(DateFrom,DateTo)	|حساب أيام العمل بين تاريخين.|
| CalculateVacationDays(DateFrom,DateTo)	|حساب أيام الإجازة.|
| CalculateVacationReturnDate(DateFrom,VacationDays)	|حساب تاريخ العودة من الإجازة.
---

## Source Code

### My Solution
- [DateLibrary.h](./Date%20Library%20Project/clsDate.h)

### Dr. Abu Hadhoud's Solution
- [DateLibrary.h](./Date%20Library%20Project/clsDate_AbuHadhoud.h)

## Developer's Notes
- This project emphasizes design thinking in C++ by combining static utility behavior with object-based state management.

- The goal was to create a reusable Date class suitable for future projects such as scheduling systems, calendars, or financial applications.
---

## 🙏 Acknowledgment
Special thanks and sincere appreciation to Dr. Mohammed Abu Hadhoud,
for his outstanding teaching style, continuous motivation, and practical approach to learning C++.
This project was inspired and guided by his educational platform
ProgrammingAdvices
---

## Translation to Arabic

### Date Library (C++)
مكتبة شاملة للتعامل مع التواريخ بلغة C++، تم تصميمها باستخدام مبادئ البرمجة الكائنية (OOP) لتقديم حلول عملية ومنظمة لمعالجة التواريخ.
عن المشروع
هذا المشروع هو تطبيق عملي لمفاهيم متقدمة في لغة C++ من خلال بناء مكتبة متكاملة لإدارة التواريخ، تشمل التحقق من صحة التاريخ، الحسابات، المقارنات، والتنسيق.
الأهداف التعليمية (تحويل المعرفة إلى خبرة)
---

## 📬 Contact
<p align="left"> <a href="https://www.linkedin.com/in/mohammed-ali-alamoudi" target="_blank"> <img src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white" /> </a> <a href="https://instagram.com/Mo__Ali_77" target="_blank"> <img src="https://img.shields.io/badge/Instagram-E4405F?style=for-the-badge&logo=instagram&logoColor=white" /> </a> <a href="https://x.com/moalialamoudi" target="_blank"> <img src="https://img.shields.io/badge/Twitter-000000?style=for-the-badge&logo=x&logoColor=white" /> </a> <a href="mailto:alamoudimohammedali@gmail.com"> <img src="https://img.shields.io/badge/Email-D14836?style=for-the-badge&logo=gmail&logoColor=white" /> </a> </p> ---
