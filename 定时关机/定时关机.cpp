#include<windows.h>
#include <iostream>
using namespace std;
int main()
{
	system("shutdown -a");
	system("cls"); //用来清屏
	int a;
	cout << "     1：30分钟后关机\n" << endl
		<< "     2：60分钟后关机\n" << endl
		<< "     3：90分钟后关机\n" << endl
		<< "     4：120分钟后关机\n" << endl
		<< "     5：自定义倒计时关机\n" << endl
		<< "     6：到设定时间后自动关机\n" << endl
		<< "     7：到晚上12点整自动关机\n" << endl
		<< "     按下除1到7外的任意字符并回车，即可退出" << endl;
	cin >> a;
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	//printf("%4d/%02d/%02d %02d:%02d:%02d.%03d 星期%1d\n", sys.wYear, sys.wMonth, sys.wDay, sys.wHour, sys.wMinute, sys.wSecond, sys.wMilliseconds, sys.wDayOfWeek);
	int dian, fen, dian1, fen1;
	fen1 = sys.wMinute;
	dian1 = sys.wHour;
	switch (a)
	{
	case 1:
		cout << "     电脑将在30分钟后关闭!" << endl;
		Sleep(1000);
		system("shutdown -s -t 1800");
		break;
	case 2:
		cout << "     电脑将在60分钟后关闭!" << endl;
		Sleep(1000);
		system("shutdown -s -t 3600");
		break;
	case 3:
		cout << "     电脑将在90分钟后关闭!" << endl;
		Sleep(1000);
		system("shutdown -s -t 5400");
		break;
	case 4:
		cout << "     电脑将在120分钟后关闭!" << endl;
		Sleep(1000);
		system("shutdown -s -t 7200");
		break;
	case 5:
	{
		system("cls"); //用来清屏
		int b, c;
		int h, m, s;
		cout << "     您想在多少分钟后关机" << endl;
		cin >> b;
		while (1) {
			if (b > 2) {
				c = b - 2;//system("shutdown -s -t 120")程序少运行两分钟
				h = c / 60;
				m = c % 60;
				s = 0;
				while (h || m || s) {
					cout << "\n\n\n           -------------------------------------------------------\n";
					cout << "           |                      距关机还有：                    |\n";
					cout << "           -------------------------------------------------------\n";
					cout << "                              " << h << "小时 " << m + 2 << "分钟 " << s << "秒" << endl;
					cout << "           -------------------------------------------------------\n";
					cout << "           |                   请不要关闭本窗口                   |\n";
					cout << "           -------------------------------------------------------\n";
					Sleep(1000);
					system("cls");
					if (s) --s;
					else if (!s && m) {
						s = 60; --m;
					}
					else if (!s && !m && h) {
						m = 60;
						s = 60;
						--h;
					}
				}
				break;
			}
			cout << "     分钟数必须大于2，请重新输入" << endl;
			cin >> b;
		}
		system("shutdown -s -t 120");
	}
	break;
	case 6:
		system("cls");
		cout << "      现在是" << sys.wHour << "点" << sys.wMinute << "分" << endl;
		cout << "      您想在__点__分关机?" << endl;
		cin >> dian >> fen;
		while ((dian != dian1) || (fen != fen1)) {
			SYSTEMTIME sys;
			GetLocalTime(&sys);
			fen1 = sys.wMinute;
			dian1 = sys.wHour;
			system("cls");
			cout << endl << endl << endl << endl << endl;
			cout << "            现在是" << dian1 << "点" << fen1 << "分" << endl;
			cout << "      您的电脑会在" << dian << "点" << fen << "分提醒您，并于之后的两分钟后自动关机" << endl;
			cout << "      请不要关闭本窗口" << endl;
			Sleep(1000);
		}

		system("shutdown -s -t 120");
		break;
	case 7:
		while ((23 != dian1) || (58 != fen1)) {
			SYSTEMTIME sys;
			GetLocalTime(&sys);
			fen1 = sys.wMinute;
			dian1 = sys.wHour;
			system("cls");
			cout << endl << endl << endl << endl << endl;
			cout << "      现在是" << dian1 << "点" << fen1 << "分" << endl;
			cout << "      您的电脑会在23点58分提醒您，并于之后的两分钟后自动关机" << endl;
			cout << "      请不要关闭本窗口" << endl;
			Sleep(1000);
		}

		system("shutdown -s -t 120");
		break;


		/*	case 8:
				cout << "     已取消定时关机！" << endl;
				Sleep(1000);
				system("shutdown -a");
			//	system("taskkill -f /im kwifi.exe ");
				break;*/
	case 8:
		cout << "     程序将在 1 秒后退出!" << endl;
		Sleep(1000);
		break;
	default:
		cout << "     程序将在 1 秒后退出!" << endl;
		Sleep(1000);
		return 0;
	}
}