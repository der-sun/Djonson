#include "MyForm.h" //�������� ����� �������� �� ��� ����� �����
using namespace System;
using namespace System::Windows::Forms;
[STAThread]
int main(array<String^>^ arg) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Djonson::MyForm form; //Example - ��� ������ �������, MainForm - ��� �����
	Application::Run(% form);
}