#include<iostream>
using namespace std;
#include<fstream>
#include<string>



struct SINHVIEN {
	int MaSV;
	string HoSV;
	string TenSV;
	struct Ngay {
		int d, m, y;
	};
	Ngay Ngaysinh;
	double DQT;
	double DCK;
};

void Nhap1sv(SINHVIEN &sv)
{
	cout << "nhap ma sinh vien: ";
	cin >> sv.MaSV;
	getchar();
	cout << "nhap ho sinh vien: ";
	getline(cin, sv.HoSV);
	cout << "nhap ten sinh vien: ";
	getline(cin, sv.TenSV);
	cout << "nhap lan luot ngay thang nam sinh vien: ";
	cin >> sv.Ngaysinh.d>>sv.Ngaysinh.m>>sv.Ngaysinh.y;
	cout << "nhap diem qua trinh sinh vien: ";
	cin >> sv.DQT;
	cout << "nhap diem cuoi ki sinh vien: ";
	cin >> sv.DCK;
	getchar();
}
void xuat1sv(SINHVIEN sv,double DTK)
{
	cout << sv.MaSV <<"|"<< sv.HoSV <<" "<< sv.TenSV <<"|"<< sv.Ngaysinh.d <<" "<< sv.Ngaysinh.m <<" "<< sv.Ngaysinh.y <<"|"<<DTK<< endl;
}

void Nhapdssv(SINHVIEN *sv, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "thong tin sv thu " << i << ": " << endl;
		Nhap1sv(sv[i]);
	}
}

void ghi(SINHVIEN *sv, int n)
{
	fstream f;
	f.open("D:/Cau3.txt", ios::out);
	for (int i = 0; i < n; i++)
	{
		f<<sv[i].MaSV <<" "<< sv[i].HoSV <<" "<< sv[i].TenSV <<" "<< sv[i].Ngaysinh.d <<" "<< sv[i].Ngaysinh.m <<" "<< sv[i].Ngaysinh.y <<" "<< sv[i].DQT <<" "<< sv[i].DCK<<endl;
	}
}

void timSvFromFile()
{
	bool found = false;
	string line;
	fstream f;
	string Masv;
	cout << "Nhap ma sinh vien can tim: ";
	getline(cin, Masv);
	f.open("D:/Cau3.txt", ios::in);
	while (getline(f, line) && !f.eof())
	{
		int pos = line.find(" ");
		if (Masv == line.substr(0, pos))
		{
			SINHVIEN *sinhvien = new SINHVIEN;
			sinhvien->MaSV = stoi(line.substr(0, pos));
			line.erase(0, pos + 1);

			int pos1 = line.find(" ");
			sinhvien->HoSV = line.substr(0, pos1);
			line.erase(0, pos1 + 1);

			int pos2 = line.find(" ");
			sinhvien->TenSV = line.substr(0, pos2);
			line.erase(0, pos2 + 1);

			int pos3 = line.find(" ");
			sinhvien->Ngaysinh.d = stoi(line.substr(0, pos3));
			line.erase(0, pos3 + 1);

			int pos4 = line.find(" ");
			sinhvien->Ngaysinh.m = stoi(line.substr(0, pos4));
			line.erase(0, pos4 + 1);

			int pos5 = line.find(" ");
			sinhvien->Ngaysinh.y = stoi(line.substr(0, pos5));
			line.erase(0, pos5 + 1);

			int pos6 = line.find(" ");
			sinhvien->DQT = stod(line.substr(0, pos6));
			line.erase(0, pos6 + 1);

			sinhvien->DCK = stod(line);
			double DTK = (sinhvien->DQT) * (0.4) +(sinhvien->DCK) * (0.6) ;
			xuat1sv(*sinhvien, DTK);
			found = true;
			system("pause");
			break;
		}
	}
	f.close();
	if (found == false)
	{
		cout << "khong tim thay";
	}
}

int main()
{
	int n, chon;
	bool in = false;
	do
	{
		cout << "nhap so luong sinh vien: ";
		cin >> n;
		getchar();
		if (n < 1 && n>50)
			cout << "nhap lai di ";
	} while (n < 1 && n>50);
	SINHVIEN *sv = new SINHVIEN[n];
	while (true)
	{
		cout << "1. Nhap dssv"<<endl;
		cout << "2. ghi tt vao file" << endl;
		cout << "3. tim sv" << endl;
		cout << "4. thoat" << endl;
		cout << "nhap lua chon: ";
		cin >> chon;
		getchar();
		if (chon == 1)
		{
			Nhapdssv(sv, n);
			in = true;
		}
		else if (chon == 2)
		{
			if (in)
				ghi(sv, n);
			else
				cout << "vui long nhap dssv";
		}
		else if (chon == 3)
			timSvFromFile();
		else if (chon == 4)
			break;
		else
			cout << "lua chon khong hop le";
	}
	system("pause");
	return 0;
}

