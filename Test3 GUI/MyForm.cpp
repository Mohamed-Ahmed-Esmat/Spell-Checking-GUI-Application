#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThread]



void main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Test3GUI::MyForm form;
	Application::Run(%form);
}
