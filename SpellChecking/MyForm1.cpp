#include "MyForm1.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(array<String^>^ argv) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	SpellChecking::MyForm form;
	Application::Run(% form);
}