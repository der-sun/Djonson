#include "MyForm.h" //Название файла измените на имя вашей формы
using namespace System;
using namespace System::Windows::Forms;
[STAThread]
int main(array<String^>^ arg) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Djonson::MyForm form; //Example - имя вашего проекта, MainForm - имя формы
	Application::Run(% form);
}