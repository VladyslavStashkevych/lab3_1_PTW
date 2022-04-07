#include <iostream> 
#include <iomanip> 
#include <string> 
#include <Windows.h> 

using namespace std;

enum Spec { KN, In, ME, FI, TN };
string specStr[] = {"����'����� �����", "�����������", "���������� � ��������", "Գ���� �� �����������", "������� ��������"};
struct Student {
	string lname;
	int course;
	int physics;
	int math;
	int cs;
	Spec spec;
};

void Create(Student* s, const int N);
void Print(Student* s, const int N);
double AverageGrade(Student s);
double PercentOfAverageGrade(Student* s, const int N);
void LastNamesOfNotThree(Student* s, const int N);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	Student* s;

	cout << "������ �i���i��� �������i�: "; cin >> N;
	s = new Student[N];

	Create(s, N);
	Print(s, N);

	LastNamesOfNotThree(s, N);
	cout << "- �i������ �������i� i� ������i� ����� �i����� �� 4.5: " << PercentOfAverageGrade(s, N) << endl;
	
	system("pause");
	return 0;
}
void Create(Student* s, const int N) {
	int spec;
	for (int i = 0; i < N; i++) {
		cout << "������� #" << i + 1 << ":" << endl;
		cin.get();
		cin.sync();
		cout << "-�������: "; 
		getline(cin, s[i].lname);
		cout << "-����: "; cin >> s[i].course;
		cout << "-������������ (0 - ��, 1 - I�, 2 - ��, 3 - �I, 4 - ��): ";
		cin >> spec;
		s[i].spec = (Spec)spec;
		cout << "-��i��� � ������: "; cin >> s[i].physics;
		cout << "-��i��� � ����������: "; cin >> s[i].math;
		cout << "-O�i��� � i����������: "; cin >> s[i].cs;
		cout << endl;
	}
}
void Print(Student* s, const int N) {
	cout << "----------------------------------------------------------------------------------\n";
	cout << "| � | ������� | ���� |     ������������     | Գ���� | ���������� | ����������� |\n";
	cout << "----------------------------------------------------------------------------------\n";
	for (int i = 0; i < N; i++) {
		cout << "| " << setw(1) << right << i + 1 << " ";
		cout << "| " << setw(9) << left << s[i].lname
			 << "| " << setw(5) << left << s[i].course
			 << "| " << setw(22) << specStr[s[i].spec]
			 << "| " << setw(7) << left << s[i].physics
			 << "| " << setw(11) << left << s[i].math
			 << "| " << setw(12) << left << s[i].cs << "|\n";
	}
	cout << "----------------------------------------------------------------------------------\n\n";
}
double AverageGrade(Student s) {
	return 1. * (s.cs + s.math + s.physics) / 3.;
}
double PercentOfAverageGrade(Student* s, const int N) {
	int counter = 0;
	for (int i = 0; i < N; i++) {
		if (AverageGrade(s[i]) > 4.5)
			counter++;
	}
	return round((1.0 * counter / N) * 10000.0) / 100.0;
}
void LastNamesOfNotThree(Student* s, const int N) {
	cout << "- ������� ��������, ��i ������� ��� ��i���:" << endl;
	for (int i = 0; i < N; i++) {
		if (s[i].math > 3 && s[i].physics > 3 && s[i].cs > 3) {
			cout << s[i].lname << endl;
		}
	}
	cout << endl;
}