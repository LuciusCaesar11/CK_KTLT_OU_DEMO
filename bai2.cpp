#include<iostream>
using namespace std;

class Diem {
public:
		double x;
		double y;
		Diem()
		{
			x = 0;
			y = 0;
		}
		Diem(double posx, double posy) {
			x = posx;
			y = posy;
		}
		void Read(Diem K){
			cout << K.x << endl;
			cout << K.y << endl;
		}
		double Distance(Diem E)
		{
			int dis = sqrt(((x - E.x)*(x - E.x)) + ((y - E.y)*(y - E.y)));
			return dis;
		}
};



int main()
{
	
	Diem A;
	Diem B;
	cout << "Nhap tung do diem A:";
	cin >> A.x;
	cout << "Nhap hoanh do diem A:";
	cin >> A.y;
	cout << "Nhap tung do diem B:";
	cin >> B.x;
	cout << "Nhap hoanh do diem B:";
	cin >> B.y;
	double distance=A.Distance(B);
	double S = 3.14192654*(distance / 2)*(distance / 2);
	cout << "dien tich hinh tron la: "<<S;
	system("pause");
	return 0;
	
}