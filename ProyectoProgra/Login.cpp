#include "Login.h"

using namespace System;
using namespace System::Windows::Forms;

int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	ProyectoProgra::Login^ formulario = gcnew ProyectoProgra::Login();
	Application::Run(formulario);

	return 0;
}
