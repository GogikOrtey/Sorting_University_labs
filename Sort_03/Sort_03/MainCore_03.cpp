//// Рабочий код версия 3.0
//
//// Я не разделил этот файл на заголовочный и несколько основных, потому что это вызывает неустранимую ошибку:
//// "Ссылка на неразрешённый внешний символ" - и указывает на первую строку кода. 
//// Поиск в интернете по названию и коду ошибки результатов не дал.
//
//#include <iostream>
//#include <cmath>
//#include <time.h>
//#include <fstream> 
//#include <stdlib.h>
//#include <iomanip>
//#include <string>
//#include <Windows.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdio.h>     
//#include <errno.h>   
//
//using namespace std; 
//
//#define MAXSTACK 2048 // максимальный размер стека
//
//#pragma warning(disable : 4996)
//
//int const AllCount = 13; // Столько записей мы будем создавать и сортировать
//
//bool isCreateNewDataFile = true;	// Если true, то создастся новый файл данных, и уже он будет отсотрирован
//									// Если false - то будет использоватся имеющийся файл данных. Если его не найдётся - выведется ошибка.
//
//bool mainCreateData(int AllCount) // Генерируем данные текстового файла из 4х других текстовых файлов
//{
//	const int size = 250; // Максимальная длинна строки (Имени или профессии)
//
//	string S[size];
//	string str;
//	int n = 0;
//	int r;
//	bool genderMan = true;
//
//	fstream OutFile("OutFile.txt", ios::out);  // открываем файл для записи в конец //app - в конец файла
//
//	cout << "count = " << AllCount << endl;
//
//	int turCount = 0;
//
//	while (turCount < AllCount)
//	{
//		turCount++;
//
//		fstream Famil("Rus Famil.txt", fstream::in);
//		fstream ManName("Rus MenName.txt", fstream::in);
//		fstream WomenName("Rus FaName.txt", fstream::in);
//		fstream Prof("Proffesion.txt", fstream::in);
//
//		if (Famil.is_open() && ManName.is_open() && WomenName.is_open() && Prof.is_open())
//		{
//			if ((rand() % 2 + 0) == 1)
//			{
//				genderMan = false;
//			}
//
//			r = rand() % 20 + 0;
//			n = 0;
//			while (!Famil.eof())
//			{
//				getline(Famil, S[n]);
//				if (n == r)
//				{
//					if (genderMan == true) OutFile << S[n] << " ";
//					else OutFile << S[n] << "а" << " ";
//					break;
//				}
//				n++;
//			}
//
//			if (genderMan == true)
//			{
//				r = rand() % 25 + 0;
//				n = 0;
//				while (!ManName.eof())
//				{
//					getline(ManName, S[n]);
//					if (n == r)
//					{
//						OutFile << S[n] << " ";
//						break;
//					}
//					n++;
//				}
//
//				ManName.close(); WomenName.close();
//				fstream ManName("Rus MenName.txt", fstream::in);
//				fstream WomenName("Rus FaName.txt", fstream::in);
//
//				r = rand() % 25 + 0;
//				n = 0;
//				while (!ManName.eof())
//				{
//					getline(ManName, S[n]);
//					if (n == r)
//					{
//						OutFile << S[n] << "ович";
//						break;
//					}
//					n++;
//				}
//			}
//			else
//			{
//				r = rand() % 25 + 0;
//				n = 0;
//				while (!WomenName.eof())
//				{
//					getline(WomenName, S[n]);
//					if (n == r)
//					{
//						OutFile << S[n] << " ";
//						break;
//					}
//					n++;
//				}
//
//				ManName.close(); WomenName.close();
//				fstream ManName("Rus MenName.txt", fstream::in);
//				fstream WomenName("Rus FaName.txt", fstream::in);
//
//				r = rand() % 25 + 0;
//				n = 0;
//				while (!WomenName.eof())
//				{
//					getline(WomenName, S[n]);
//					if (n == r)
//					{
//						OutFile << S[n] << "овна";
//						break;
//					}
//					n++;
//				}
//			}
//
//			OutFile << ", ";
//
//			r = rand() % 25 + 0;
//			n = 0;
//			while (!Prof.eof())
//			{
//				getline(Prof, S[n]);
//				if (n == r)
//				{
//					OutFile << S[n];
//					break;
//				}
//				n++;
//			}
//
//			//22.08.2020
//
//			int dd, mm, gg;
//
//			dd = rand() % 29 + 1;
//			mm = 11; //rand() % 11 + 1;
//			gg = 2021; //rand() % 20 + 2000;
//
//			OutFile << ", " << dd << "." << mm << "." << gg;
//
//			int MainDat = 2022 * 12 * 30;
//			int AllDat = gg * 12 * 30 + mm * 30 + dd;
//			int currStaj = MainDat - AllDat;
//
//			OutFile << ", " << currStaj << " дней";
//
//			OutFile << endl;
//
//			Famil.close(); ManName.close(); WomenName.close(); Prof.close();
//		}
//		else return false;
//	}
//
//	OutFile.close();
//	return true;
//}
//
//struct Data
//{
//	int dd;
//	int mm;
//	int gg;
//};
//
//Data data;
//
//struct Dann
//{
//	string Name;
//	string Famil;
//	string Otth;
//	string Proff;
//	Data Data;
//	int Staj;
//};
//
//Dann dann;
//
//bool Processing_data_from_the_input_file(Dann* mass)
//// Распознаём и записываем данные из файла во внутреннй массив программы, для дальнеёшей сортировки
//{
//	string S[AllCount];
//	int n = 0;
//
//	if (isCreateNewDataFile == true)
//	{
//		if (mainCreateData(AllCount)) // Генерируем записи
//		{
//			cout << "Данные успешно сгенерированы!" << endl;
//			cout << endl;
//		}
//		else
//		{
//			return false;
//		}
//
//	}
//
//	fstream DataFile("OutFile.txt", fstream::in);
//
//	if (DataFile.is_open())
//	{
//		string str = "";
//		int intMass = 0;
//		n = 0;
//
//		while (n < AllCount) //(!DataFile.eof())
//		{
//			getline(DataFile, S[n]);
//			cout << S[n] << endl;
//
//			string input = S[n];
//
//			char r;
//			int y = 0;
//
//			str = "";
//			r = input[y];
//
//			while (r != ' ')
//			{
//				r = input[y];
//				if (r != ' ')
//				{
//					str = str + r;
//				}
//				y++;
//			}
//
//			//cout << "Имя (str) = " << str << endl;
//
//			mass[intMass].Name = str;
//			str = "";
//
//			r = input[y];
//
//			while (r != ' ')
//			{
//				r = input[y];
//				if (r != ' ')
//				{
//					str = str + r;
//				}
//				y++;
//			}
//
//			//cout << "Фамилия (str) = " << str << endl;
//
//			mass[intMass].Famil = str;
//			str = "";
//
//			r = input[y];
//
//			while (r != ',')
//			{
//				r = input[y];
//				if (r != ',')
//				{
//					str = str + r;
//				}
//				y++;
//			}
//
//			//cout << "Отество (str) = " << str << endl;
//			mass[intMass].Otth = str;
//
//			str = "";
//
//			r = input[y];
//
//			while (r != ',')
//			{
//				r = input[y];
//				if (r != ',')
//				{
//					str = str + r;
//				}
//				y++;
//			}
//
//			//cout << "Профессия (str) = " << str << endl;
//			mass[intMass].Proff = str;
//
//			str = "";
//			r = input[y];
//
//			while (r != '.')
//			{
//				r = input[y];
//				if (r != '.')
//				{
//					str = str + r;
//				}
//				y++;
//			}
//
//			//cout << "Число (str) = " << str << endl;
//
//			char* strng = new char[str.length() + 1];
//			strcpy(strng, str.c_str());
//
//			mass[intMass].Data.dd = atoi(strng);
//
//			str = "";
//			r = input[y];
//
//			while (r != '.')
//			{
//				r = input[y];
//				if (r != '.')
//				{
//					str = str + r;
//				}
//				y++;
//			}
//
//			//cout << "Месяц (str) = " << str << endl;
//
//			strng = new char[str.length() + 1];
//			strcpy(strng, str.c_str());
//
//			mass[intMass].Data.mm = atoi(strng);
//
//			str = "";
//			r = input[y];
//
//			while (r != ',')
//			{
//				r = input[y];
//				if (r != ',')
//				{
//					str = str + r;
//				}
//				y++;
//			}
//
//			//cout << "Год (str) = " << str << endl;
//
//			strng = new char[str.length() + 1];
//			strcpy(strng, str.c_str());
//
//			mass[intMass].Data.gg = atoi(strng);
//
//			str = "";
//			y++;
//			r = input[y];
//
//			while (r != ' ')
//			{
//				r = input[y];
//				if (r != ' ')
//				{
//					str = str + r;
//				}
//				y++;
//			}
//
//			//cout << "Стаж (str) = " << str << endl;
//
//			strng = new char[str.length() + 1];
//			strcpy(strng, str.c_str());
//
//			mass[intMass].Staj = atoi(strng);
//
//			n++;
//			intMass++;
//		}
//	}
//	else return false;
//
//	DataFile.close();
//	return true;
//}
//
//Dann* DataCreator()
//{
//	setlocale(LC_ALL, "rus");
//	srand(time(0));
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//
//	Dann* mass = new Dann[AllCount]; // Массив для храниения записей как структуру полей
//
//	if (Processing_data_from_the_input_file(mass)) // Загружаем во внутренний массив записи из файла
//	{
//		cout << endl;
//		cout << "Данные успешно обработаны!" << endl;
//
//		return mass;
//
//		//outputDann(mass[19]);
//	}
//	else
//	{
//		cout << "Файл, необходимый для обработки записей, не открывается." << endl;
//		return NULL;
//	}
//}
//
//// Далее я создаю другую структуру массива данных, и перезаписываю в неё все данные из моего 1го массива.
//// Это делается потому, что код генерации и распознавания данных, и код сортировки данных я писал отдельно друг от друга
//
//struct AQ // Стандартная структура нужных нам данных
//{
//	string d; // Должность
//	int s;	  // Стаж
//	string f; // Фамилия
//	string i; // Имя
//	string o; // Отчество
//};
//
//struct AQ2 // Структура данны, с дополнительным индексом, для проверки устойчивости сортировок
//{
//	string d; // Должность
//	int s;	  // Стаж
//	string f; // Фамилия
//	string i; // Имя
//	string o; // Отчество
//	int ind;
//};
//
//// У нас сортировка по: Должность, Стаж, Фамилия, Имя, Отчество (5шт.)
//
//bool RepeatAZ_1(AQ a, AQ b) // if(a >= b)
//{
//	if (a.d == b.d)
//	{
//		if (a.s == b.s)
//		{
//			if (a.f == b.f)
//			{
//				if (a.i == b.i)
//				{
//					if (a.o == b.o)
//					{
//						return true;
//					}
//					else if (a.o > b.o) return true;
//					else return false;
//				}
//				else if (a.i > b.i) return true;
//				else return false;
//			}
//			else if (a.f > b.f) return true;
//			else return false;
//		}
//		else if (a.s > b.s) return true;
//		else return false;
//	}
//	else if (a.d > b.d) return true;
//	else return false;
//}
//
//bool RepeatAZ_2(AQ a, AQ b)  // if(a < b)
//{
//	if (a.d == b.d)
//	{
//		if (a.s == b.s)
//		{
//			if (a.f == b.f)
//			{
//				if (a.i == b.i)
//				{
//					if (a.o == b.o)
//					{
//						return false;
//					}
//					else if (a.o < b.o) return true;
//					else return false;
//				}
//				else if (a.i < b.i) return true;
//				else return false;
//			}
//			else if (a.f < b.f) return true;
//			else return false;
//		}
//		else if (a.s < b.s) return true;
//		else return false;
//	}
//	else if (a.d < b.d) return true;
//	else return false;
//}
//
//bool RepeatAZ_3(AQ a, AQ b)  // if(a > b)
//{
//	if (a.d == b.d)
//	{
//		if (a.s == b.s)
//		{
//			if (a.f == b.f)
//			{
//				if (a.i == b.i)
//				{
//					if (a.o == b.o)
//					{
//						return false;
//					}
//					else if (a.o > b.o) return true;
//					else return false;
//				}
//				else if (a.i > b.i) return true;
//				else return false;
//			}
//			else if (a.f > b.f) return true;
//			else return false;
//		}
//		else if (a.s > b.s) return true;
//		else return false;
//	}
//	else if (a.d > b.d) return true;
//	else return false;
//}
//
//void Tinsert(AQ* InputMass, int n) // Сортировка Двухпутевыми вставками
//{								   // n - размер исходного массива
//	int i, j, left, right, newN;
//
//	AQ t;
//
//	left = n - 1;		// Устанавливаем указатели на правую и левую границу в середину нового массива
//	right = n - 1;		// И сдвигаем их по мере добавления элементов
//	newN = 2 * n;
//
//	AQ* NewMass = new AQ[newN];
//
//	NewMass[n - 1] = InputMass[0];	// Центральный элемент расширенного массива - начальный исходного массива.
//
//	for (i = 0; i < n; i++)			// Проходим исходный массив слева направо
//	{
//		t = InputMass[i];
//
//		if (RepeatAZ_1(t, InputMass[0])) // if (t >= InputMass[0])
//		{
//			for (j = right; (j >= 0) && RepeatAZ_2(t, NewMass[j]); j--)
//				NewMass[j + 1] = NewMass[j];
//			// Сдвигаем все значения массива вправо (от правой границы), пока наше взятое значение не станет больше итерационного
//
//			NewMass[j + 1] = t;
//			right++;
//		}
//		else
//		{
//			for (j = left; (j <= newN) && RepeatAZ_3(t, NewMass[j]); j++)
//				NewMass[j - 1] = NewMass[j];
//			// Сдвигаем все значения массива влево (от левой границы), пока наше взятое значение не станет меньше итерационного
//
//			NewMass[j - 1] = t;
//			left--;
//		}
//	}
//
//	for (j = left+1; j < left+1 + n; j++) // Перезаписываем отсортированные значения в начальный массив
//		InputMass[j - left -1] = NewMass[j];
//
//	delete[] NewMass;
//}
//
//bool RepeatAZ_1(AQ2 a, AQ2 b)  // if(a >= b) // Для примера неустойчивой сотрировки
//{
//	if (a.d == b.d)
//	{
//		if (a.s == b.s)
//		{
//			if (a.f == b.f)
//			{
//				if (a.i == b.i)
//				{
//					if (a.o == b.o)
//					{
//						return true;
//					}
//					else if (a.o > b.o) return true;
//					else return false;
//				}
//				else if (a.i > b.i) return true;
//				else return false;
//			}
//			else if (a.f > b.f) return true;
//			else return false;
//		}
//		else if (a.s > b.s) return true;
//		else return false;
//	}
//	else if (a.d > b.d) return true;
//	else return false;
//}
//
//bool RepeatAZ_2(AQ2 a, AQ2 b)  // if(a < b) // Для примера неустойчивой сотрировки
//{
//	if (a.d == b.d)
//	{
//		if (a.s == b.s)
//		{
//			if (a.f == b.f)
//			{
//				if (a.i == b.i)
//				{
//					if (a.o == b.o)
//					{
//						return false;
//					}
//					else if (a.o < b.o) return true;
//					else return false;
//				}
//				else if (a.i < b.i) return true;
//				else return false;
//			}
//			else if (a.f < b.f) return true;
//			else return false;
//		}
//		else if (a.s < b.s) return true;
//		else return false;
//	}
//	else if (a.d < b.d) return true;
//	else return false;
//}
//
//bool RepeatAZ_3(AQ2 a, AQ2 b)  // if(a > b) // Для примера неустойчивой сотрировки
//{
//	if (a.d == b.d)
//	{
//		if (a.s == b.s)
//		{
//			if (a.f == b.f)
//			{
//				if (a.i == b.i)
//				{
//					if (a.o == b.o)
//					{
//						return false;
//					}
//					else if (a.o > b.o) return true;
//					else return false;
//				}
//				else if (a.i > b.i) return true;
//				else return false;
//			}
//			else if (a.f > b.f) return true;
//			else return false;
//		}
//		else if (a.s > b.s) return true;
//		else return false;
//	}
//	else if (a.d > b.d) return true;
//	else return false;
//}
//
//void Tinsert2(AQ2* InputMass, int n) // Сортировка Двухпутевыми вставками
//{									 // n - размер исходного массива
//	int i, j, left, right, newN;
//
//	AQ2 t;
//
//	left = n - 1;		// Устанавливаем указатели на правую и левую границу в середину нового массива
//	right = n - 1;		// И сдвигаем их по мере добавления элементов
//	newN = 2 * n;
//
//	AQ2* NewMass = new AQ2[newN];
//
//	NewMass[n - 1] = InputMass[0];	// Центральный элемент расширенного массива - начальный исходного массива.
//
//	for (i = 0; i < n; i++)			// Проходим исходный массив слева направо
//	{
//		t = InputMass[i];
//
//		if (RepeatAZ_1(t, InputMass[0])) // if (t >= InputMass[0])
//		{
//			for (j = right; (j >= 0) && RepeatAZ_2(t, NewMass[j]); j--)
//				NewMass[j + 1] = NewMass[j];
//			// Сдвигаем все значения массива вправо (от правой границы), пока наше взятое значение не станет больше итерационного
//
//			NewMass[j + 1] = t;
//			right++;
//		}
//		else
//		{
//			for (j = left; (j <= newN) && RepeatAZ_3(t, NewMass[j]); j++)
//				NewMass[j - 1] = NewMass[j];
//			// Сдвигаем все значения массива влево (от левой границы), пока наше взятое значение не станет меньше итерационного
//
//			NewMass[j - 1] = t;
//			left--;
//		}
//	}
//
//	for (j = left; j < left + n; j++) // Перезаписываем отсортированные значения в начальный массив
//		InputMass[j - left] = NewMass[j];
//
//	delete[] NewMass;
//}
//
//void coutM(AQ* mass, int n) // Выводим данные в консоль
//{
//	for (int i = 0; i < n; i++)
//	{
//		cout << "[" << mass[i].d << ", " << mass[i].s << ", " << mass[i].f << ", " << mass[i].i << ", " << mass[i].o << "]" << endl;
//	}
//}
//
//void qSortI(AQ a[], long size) // Опорный - средний
//{
//	long i, j; // указатели, участвующие в разделении
//	long lb, ub; // границы сортируемого в цикле фрагмента
//
//	long lbstack[MAXSTACK], ubstack[MAXSTACK]; // стек запросов
//	// каждый запрос задается парой значений,
//	// а именно: левой(lbstack) и правой(ubstack)
//	// границами промежутка
//	long stackpos = 1; // текущая позиция стека
//	long ppos; // середина массива
//	AQ pivot; // опорный элемент
//	// int temp;
//
//	lbstack[1] = 0;
//	ubstack[1] = size - 1;
//
//	do {
//		// Взять границы lb и ub текущего массива из стека.
//		lb = lbstack[stackpos];
//		ub = ubstack[stackpos];
//		stackpos--;
//
//		do {
//			// Шаг 1. Разделение по элементу pivot
//			ppos = (lb + ub) >> 1;
//			i = lb; j = ub; pivot = a[ppos];
//			do {
//				while (RepeatAZ_2(a[i], pivot)) i++; // (a[i] < pivot)
//				while (RepeatAZ_2(pivot, a[j])) j--; // (pivot < a[j])
//				if (i <= j)
//				{
//					//swapp(a[i], a[j]);
//					AQ temp; temp = a[i]; a[i] = a[j]; a[j] = temp;
//					i++; j--;
//				}
//			} while (i <= j);
//
//			// Шаги 2, 3. Отправляем большую часть в стек и двигаем lb,ub
//			if (i < ppos) { // правая часть больше
//				if (i < ub) { // если в ней больше 1 элемента - нужно
//					stackpos++; // сортировать, запрос в стек
//					lbstack[stackpos] = i;
//					ubstack[stackpos] = ub;
//				}
//				ub = j; // следующая итерация разделения
//				// будет работать с левой частью
//			}
//			else { // левая часть больше
//				if (j > lb) {
//					stackpos++;
//					lbstack[stackpos] = lb;
//					ubstack[stackpos] = j;
//				}
//				lb = i;
//			}
//		} while (lb < ub); // пока в меньшей части более 1 элемента
//	} while (stackpos != 0); // пока есть запросы в стеке
//}
//
//void qSortI(AQ2 a[], long size) // Опорный - средний // Для примера неустойчивой сотрировки
//{
//	long i, j; // указатели, участвующие в разделении
//	long lb, ub; // границы сортируемого в цикле фрагмента
//
//	long lbstack[MAXSTACK], ubstack[MAXSTACK]; // стек запросов
//	long stackpos = 1; // текущая позиция стека
//	long ppos; // середина массива
//	AQ2 pivot; // опорный элемент
//	// int temp;
//
//	lbstack[1] = 0;
//	ubstack[1] = size - 1;
//
//	do {
//		// Взять границы lb и ub текущего массива из стека.
//		lb = lbstack[stackpos];
//		ub = ubstack[stackpos];
//		stackpos--;
//
//		do {
//			// Шаг 1. Разделение по элементу pivot
//			ppos = (lb + ub) >> 1;
//			i = lb; j = ub; pivot = a[ppos];
//			do {
//				while (RepeatAZ_2(a[i], pivot)) i++; // (a[i] < pivot)
//				while (RepeatAZ_2(pivot, a[j])) j--; // (pivot < a[j])
//				if (i <= j)
//				{
//					//swapp(a[i], a[j]);
//					AQ2 temp; temp = a[i]; a[i] = a[j]; a[j] = temp;
//					i++; j--;
//				}
//			} while (i <= j);
//
//			// Шаги 2, 3. Отправляем большую часть в стек и двигаем lb,ub
//			if (i < ppos) { // правая часть больше
//				if (i < ub) { // если в ней больше 1 элемента - нужно
//					stackpos++; // сортировать, запрос в стек
//					lbstack[stackpos] = i;
//					ubstack[stackpos] = ub;
//				}
//				ub = j; // следующая итерация разделения
//				// будет работать с левой частью
//			}
//			else { // левая часть больше
//				if (j > lb) {
//					stackpos++;
//					lbstack[stackpos] = lb;
//					ubstack[stackpos] = j;
//				}
//				lb = i;
//			}
//		} while (lb < ub); // пока в меньшей части более 1 элемента
//	} while (stackpos != 0); // пока есть запросы в стеке
//}
//
//void Examples_Instability() // Процедура, которая записывает в файл примеры неустойчивости
//{
//	fstream OutSortFile("_OutSortFile.txt", ios::app);
//
//	AQ2* massEI = new AQ2[2];
//
//	OutSortFile << "Введём новую структуру записи, содержащей поле 'индекс'" << endl;
//	OutSortFile << "Заполним массив из 2х записей одинаковыми значениями, с разными индексами" << endl;
//	OutSortFile << "Отсортируем 2мя разными способами и проверим, устойчива ли каждая сортировка или нет:" << endl;
//
//	for (int i = 0; i < 2; i++) // Заполним массив из 2х записей одинаковыми значениями:
//	{
//		// Крестникова Ольга Александровна
//		massEI[i].d = "Учитель";
//		massEI[i].i = "Ольга";
//		massEI[i].s = 10;
//		massEI[i].f = "Крестникова";
//		massEI[i].o = "Александровна";
//	}
//
//	massEI[0].ind = 0;
//	massEI[1].ind = 1;
//
//	AQ2* massDP = new AQ2[2]; // Двухпутевыми
//	AQ2* massQ = new AQ2[2];  // Быстрой
//
//	for (int i = 0; i < 2; i++)
//	{
//		massQ[i] = massEI[i];
//		massDP[i] = massEI[i];
//	}
//
//	OutSortFile << "Выводим данные без изменений: " << endl;
//	OutSortFile << endl;
//
//	for (int i = 0; i < 2; i++)
//	{
//		OutSortFile << "[" << massEI[i].d << ", " << massEI[i].s << ", " << massEI[i].f << ", " << massEI[i].i << ", " << massEI[i].o << "], ind = " << massEI[i].ind << endl;
//	}
//
//	OutSortFile << endl;
//
//	OutSortFile << "Сортируем Двухпутевыми вставками" << endl; // Устойчивая
//	Tinsert2(massDP, 2);
//	OutSortFile << "Выводим данные отсортированные Двухпутевыми вставками: " << endl;
//	OutSortFile << endl;
//	{
//		OutSortFile << "[" << massDP[0].d << ", " << massDP[0].s << ", " << massDP[0].f << ", " << massDP[0].i << ", " << massDP[0].o << "], ind = 0" << endl;
//		OutSortFile << "[" << massDP[1].d << ", " << massDP[1].s << ", " << massDP[1].f << ", " << massDP[1].i << ", " << massDP[1].o << "], ind = 1" << endl;
//	}
//	OutSortFile << endl;
//
//	OutSortFile << "Сортируем Быстрой сортировкой" << endl; // Не устойчивая
//	qSortI(massQ, 2);
//	OutSortFile << "Выводим данные отсортированные Быстрой сортировкой: " << endl;
//	OutSortFile << endl;
//
//	for (int i = 0; i < 2; i++)
//	{
//		OutSortFile << "[" << massQ[i].d << ", " << massQ[i].s << ", " << massQ[i].f << ", " << massQ[i].i << ", " << massQ[i].o << "], ind = " << massQ[i].ind << endl;
//	}
//
//	OutSortFile << endl;
//	OutSortFile << endl;
//	(OutSortFile).close();
//
//	delete[] massDP;
//	delete[] massQ;
//	delete[] massEI;
//}
//
//
//bool PrintToFile(AQ* mass, int n, int SortTime, bool q) // Процедура, которая записыват выходные данные в файл. Вызывается 2 раза
//{
//	fstream OutSortFile("_OutSortFile.txt", ios::app);
//
//	if (q == false)
//	{
//		OutSortFile << "Количество записей: " << n << endl;
//		OutSortFile << endl;
//		OutSortFile << "Сортировка Двухпутевыми вставками: " << endl;
//		OutSortFile << "Время, затраченное на сортировку: " << SortTime << " милисекунд" << endl;
//		OutSortFile << endl;
//		return(false);
//	}
//	else
//	{
//		OutSortFile << "Сортировка Быстрой сортировкой: " << endl;
//		OutSortFile << "Время, затраченное на сортировку: " << SortTime << " милисекунд" << endl;
//		OutSortFile << endl;
//	}
//
//	OutSortFile << "Результат сортировки (отсортированные данные): " << endl;
//	OutSortFile << endl;
//
//	for (int i = 0; i < n; i++)
//	{
//		OutSortFile << "[" << mass[i].d << ", " << mass[i].s << ", " << mass[i].f << ", " << mass[i].i << ", " << mass[i].o << "]" << endl;
//	}
//
//	OutSortFile << endl;
//	OutSortFile << endl;
//
//	Examples_Instability(); 
//
//	(OutSortFile).close();
//	return(true);
//}
//
//
//void main()
//{
//	setlocale(LC_ALL, "rus");
//	srand(time(0));
//
//	AQ* massDP = new AQ[AllCount]; // Двухпутевыми
//	AQ* massQ = new AQ[AllCount];  // Быстрой
//	AQ* massNS = new AQ[AllCount]; // Не отсортированный
//
//	Dann* massA = new Dann[AllCount];
//
//	massA = DataCreator();
//
//	int SortTime = 0;
//
//	if (massA == NULL)
//	{
//		cout << "Данные были получены нерпавильно. Программа завершается с ошибкой." << endl;
//	}
//	else
//	{
//		// string d; // Должность
//		// int s;    // Стаж
//		// string f; // Фамилия
//		// string i; // Имя
//		// string o; // Отчество
//
//		for (int i = 0; i < AllCount; i++) // Заполняем массив значениями
//		{
//			massNS[i].d = massA[i].Proff;
//			massNS[i].o = massA[i].Otth;
//			massNS[i].s = massA[i].Staj;
//			massNS[i].f = massA[i].Famil;
//			massNS[i].i = massA[i].Name;
//		}
//
//		fstream OutSortFile("_OutSortFile.txt", ios::out); // Очищаем выходной файл
//		(OutSortFile).close();
//
//		cout << endl;
//		cout << "Выводим загруженные данные:" << endl;
//
//		for (int i = 0; i < AllCount; i++) // Копируем данные из неотсортированного массива в 2 других, для сортировки
//		{
//			massQ[i] = massNS[i];
//			massDP[i] = massNS[i];
//		}
//
//		coutM(massNS, AllCount);
//		// Измерение времени сортировки Двухпутевыми вставками
//		{
//			__int64 start, end, tps;
//			QueryPerformanceFrequency((LARGE_INTEGER*)&tps);
//			QueryPerformanceCounter((LARGE_INTEGER*)&start);
//
//			Tinsert(massDP, AllCount); // Сортируем Двухпутевыми вставками
//
//			QueryPerformanceCounter((LARGE_INTEGER*)&end);
//			SortTime = ((double)(end - start) / tps) * 1000.;
//		}
//
//		cout << endl;
//		cout << "Выводим данные, отсортированные Двухпутевыми вставками: " << endl;
//
//		coutM(massDP, AllCount);
//		PrintToFile(massDP, AllCount, SortTime, false);
//
//		cout << endl;
//		cout << "Время сортировки Двухпутевыми вставками: " << SortTime << " милисекунд";
//		cout << endl;
//
//		// ---------
//
//		// Измерение времени Быстрой сортировки
//		{
//			__int64 start, end, tps;
//			QueryPerformanceFrequency((LARGE_INTEGER*)&tps);
//			QueryPerformanceCounter((LARGE_INTEGER*)&start);
//
//			qSortI(massQ, AllCount); // Сортируем Быстрой сортировкой 
//
//			QueryPerformanceCounter((LARGE_INTEGER*)&end);
//			SortTime = ((double)(end - start) / tps) * 1000.;
//		}
//
//		cout << endl;
//		cout << "Выводим данные, отсортированные Быстрой сортировкой: " << endl;
//
//		coutM(massQ, AllCount);
//		PrintToFile(massQ, AllCount, SortTime, true); // Печатаем данные в выходной файл
//
//		cout << endl;
//		cout << "Время сортировки Быстрой сортировкой: " << SortTime << " милисекунд";
//		cout << endl;
//
//		delete[] massDP;
//		delete[] massQ;
//		delete[] massNS;
//		delete[] massA;
//	}
//}
//
//
///*
//Сортировать по убыванию, алгоритмы:
//	• Двухпутевые вставки
//	• Быстрая (не рекурсивная реализация (с использованием статического стека), опорный – средний).
//
//В строке файла: ФИО, должность, дата приема на работу, стаж
//
//Сортировать по полям: должность, стаж, ФИО
//*/