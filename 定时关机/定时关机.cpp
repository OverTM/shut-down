#include<windows.h>
#include <iostream>
using namespace std;
int main()
{
	system("shutdown -a");
	system("cls"); //��������
	int a;
	cout << "     1��30���Ӻ�ػ�\n" << endl
		<< "     2��60���Ӻ�ػ�\n" << endl
		<< "     3��90���Ӻ�ػ�\n" << endl
		<< "     4��120���Ӻ�ػ�\n" << endl
		<< "     5���Զ��嵹��ʱ�ػ�\n" << endl
		<< "     6�����趨ʱ����Զ��ػ�\n" << endl
		<< "     7��������12�����Զ��ػ�\n" << endl
		<< "     ���³�1��7��������ַ����س��������˳�" << endl;
	cin >> a;
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	//printf("%4d/%02d/%02d %02d:%02d:%02d.%03d ����%1d\n", sys.wYear, sys.wMonth, sys.wDay, sys.wHour, sys.wMinute, sys.wSecond, sys.wMilliseconds, sys.wDayOfWeek);
	int dian, fen, dian1, fen1;
	fen1 = sys.wMinute;
	dian1 = sys.wHour;
	switch (a)
	{
	case 1:
		cout << "     ���Խ���30���Ӻ�ر�!" << endl;
		Sleep(1000);
		system("shutdown -s -t 1800");
		break;
	case 2:
		cout << "     ���Խ���60���Ӻ�ر�!" << endl;
		Sleep(1000);
		system("shutdown -s -t 3600");
		break;
	case 3:
		cout << "     ���Խ���90���Ӻ�ر�!" << endl;
		Sleep(1000);
		system("shutdown -s -t 5400");
		break;
	case 4:
		cout << "     ���Խ���120���Ӻ�ر�!" << endl;
		Sleep(1000);
		system("shutdown -s -t 7200");
		break;
	case 5:
	{
		system("cls"); //��������
		int b, c;
		int h, m, s;
		cout << "     �����ڶ��ٷ��Ӻ�ػ�" << endl;
		cin >> b;
		while (1) {
			if (b > 2) {
				c = b - 2;//system("shutdown -s -t 120")����������������
				h = c / 60;
				m = c % 60;
				s = 0;
				while (h || m || s) {
					cout << "\n\n\n           -------------------------------------------------------\n";
					cout << "           |                      ��ػ����У�                    |\n";
					cout << "           -------------------------------------------------------\n";
					cout << "                              " << h << "Сʱ " << m + 2 << "���� " << s << "��" << endl;
					cout << "           -------------------------------------------------------\n";
					cout << "           |                   �벻Ҫ�رձ�����                   |\n";
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
			cout << "     �������������2������������" << endl;
			cin >> b;
		}
		system("shutdown -s -t 120");
	}
	break;
	case 6:
		system("cls");
		cout << "      ������" << sys.wHour << "��" << sys.wMinute << "��" << endl;
		cout << "      ������__��__�ֹػ�?" << endl;
		cin >> dian >> fen;
		while ((dian != dian1) || (fen != fen1)) {
			SYSTEMTIME sys;
			GetLocalTime(&sys);
			fen1 = sys.wMinute;
			dian1 = sys.wHour;
			system("cls");
			cout << endl << endl << endl << endl << endl;
			cout << "            ������" << dian1 << "��" << fen1 << "��" << endl;
			cout << "      ���ĵ��Ի���" << dian << "��" << fen << "��������������֮��������Ӻ��Զ��ػ�" << endl;
			cout << "      �벻Ҫ�رձ�����" << endl;
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
			cout << "      ������" << dian1 << "��" << fen1 << "��" << endl;
			cout << "      ���ĵ��Ի���23��58��������������֮��������Ӻ��Զ��ػ�" << endl;
			cout << "      �벻Ҫ�رձ�����" << endl;
			Sleep(1000);
		}

		system("shutdown -s -t 120");
		break;


		/*	case 8:
				cout << "     ��ȡ����ʱ�ػ���" << endl;
				Sleep(1000);
				system("shutdown -a");
			//	system("taskkill -f /im kwifi.exe ");
				break;*/
	case 8:
		cout << "     ������ 1 ����˳�!" << endl;
		Sleep(1000);
		break;
	default:
		cout << "     ������ 1 ����˳�!" << endl;
		Sleep(1000);
		return 0;
	}
}