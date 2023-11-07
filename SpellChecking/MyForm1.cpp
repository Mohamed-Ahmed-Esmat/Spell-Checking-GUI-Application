#include "MyForm1.h"
#include "TrieHeader.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	SpellChecking::MyForm form;
	Application::Run(% form);
}