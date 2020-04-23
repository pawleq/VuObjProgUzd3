#include "header.h"
#include "Studentas.cpp"

int ErrorFun(int nr)
{
	if (nr == 0)
	{
		cout << "ivedete ne 1 arba 0, bandykite dar karta" << endl;
		return 0;
	}
	if (nr == 1)
	{
		cout << "Ivedete ne skaiciu (1-10), bandykite dar karta" << endl;
		return 0;
	}
	if (nr == 2) {
		cout << "Duomenys ivesti neteisingai" << endl;
		return 0;
	}
	return 0;
}
int CinFail(int e)
{
	int f;
	cin >> f;
	while (cin.fail() or f != 0 && f != 1)
	{
		cin.clear();
		cin.ignore(100, '\n');
		ErrorFun(e);
		cin >> f;
	}
	cin.clear();
	cin.ignore(100, '\n');
	return f;

}

int CinDecimal(int e)
{
	int f;
	cin >> f;
	while (cin.fail() or f > 10 or f < 0)
	{
		cin.clear();
		cin.ignore(100, '\n');
		ErrorFun(e);
		cin >> f;
	}
	cin.clear();
	cin.ignore(100, '\n');
	return f;

}
void Writing(std::ofstream & failas, vector <Studentas> & vargsiukas, unsigned int &Pilgis, unsigned int &Vilgis)
{
	failas << setw(Pilgis + 6) << std::left << setfill(' ') << "Pavarde "<< setw(Vilgis + 6) << std::left << setfill(' ') << "Vardas "<< setw(16) << std::left << setfill(' ') << "Galutinis vid. "<< setw(16) << std::left << setfill(' ') << "Galutinis med. " << endl;
	string eilute(Pilgis + Vilgis + 40, '-');
	failas << eilute << endl;
	for (size_t i = 0; i < vargsiukas.size(); i++) {
		failas << setw(Pilgis + 6) << std::left << setfill(' ') << vargsiukas[i].pavarde()<< setw(Vilgis + 6) << std::left << setfill(' ') << vargsiukas[i].vardas()<< setw(16) << std::left << setfill(' ') << std::setprecision(2) << std::fixed << vargsiukas[i].galutinisVid() << vargsiukas[i].galutinisMed() << endl;
	}
}
void vectorSplit(vector <Studentas> &studentai, vector <Studentas> &vargsiukas, int &b, int& z, unsigned int &Vilgis, unsigned int &Pilgis)

{
	if (b == 1)
	{
		vector<Studentas>::iterator it = std::partition(studentai.begin(), studentai.end(), compare_by_grades);
		std::copy(it, studentai.end(), std::back_inserter(vargsiukas));
		studentai.erase(it, studentai.end());
		studentai.shrink_to_fit();
	}
	else
	{
		vector<Studentas>::iterator it = std::partition(studentai.begin(), studentai.end(), compare_by_mediana);
		std::copy(it, studentai.end(), std::back_inserter(vargsiukas));
		studentai.erase(it, studentai.end());
		studentai.shrink_to_fit();

	}
	if (z == 0) {
		std::sort(studentai.begin(), studentai.end(), compare_by_word);
		std::sort(vargsiukas.begin(), vargsiukas.end(), compare_by_word);
	} else
	{
		std::sort(studentai.begin(), studentai.end(), compare_by_name);
		std::sort(vargsiukas.begin(), vargsiukas.end(), compare_by_name);

	}
}
void SpartosAnalize()
{
	vector<Studentas> studentai;
	vector<Studentas> vargsiukas;
	unsigned int Pilgis = 7;
	unsigned int Vilgis = 6;
	cout << "Ar norite rusiuoti pagal medianas ar vidurkius? 1-vidurkis 0-mediana" << endl;
	int b = CinFail(0);

	cout << "Ar norite rikiuoti pagal varda ar pavarde? 1-vardas 0-pavarde" << endl;
	int z = CinFail(0);
	string pav;
	cout << "Iveskite studentu failo pavadinima" << endl;
	cin >> pav;
	cout << "Pradedamas matuoti laikas" << endl;
    std::chrono::steady_clock::time_point beginRead =
    std::chrono::steady_clock::now();
	ifstream file(pav);
	if (!file)
	{
		cout << "Pavadinimas ivestas neteisingai" << endl;
		exit(EXIT_FAILURE);
	}
	while (!file.eof())
	{
		studentai.emplace_back(file, Vilgis, Pilgis);
	};
	std::chrono::steady_clock::time_point endRead =
    std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point beginSplit =
    std::chrono::steady_clock::now();
	vectorSplit(studentai, vargsiukas, b, z, Vilgis, Pilgis);
	std::ofstream failas1 ("kietekai.txt");
	std::ofstream failas2 ("vargsiukai.txt");
	Writing(failas1, vargsiukas, Pilgis, Vilgis);
	Writing(failas2, studentai, Pilgis, Vilgis);
    std::chrono::steady_clock::time_point endSplit =
    std::chrono::steady_clock::now();
    std::cout << "Skaitymo laikas: "<< (double)std::chrono::duration_cast<std::chrono::milliseconds>(endRead - beginRead).count() / 1000<< "s" << std::endl;
    std::cout << "Dalinimo ir isvedimo laikas: "<< (double)std::chrono::duration_cast<std::chrono::milliseconds>(endSplit - beginSplit).count() / 1000<< "s" << std::endl;
}
