#include "Recordatorio.h"



Recordatorio::Recordatorio(System::String^ info)
{
	sig = nullptr;
	ant = nullptr;
	id = System::Convert::ToInt32(info->Substring(0, info->IndexOf(",")));
	info = info->Remove(0, info->IndexOf(",") + 1);
	descripci�n = msclr::interop::marshal_as<std::string>(info->Substring(0, info->IndexOf(",")));
	info = info->Remove(0, info->IndexOf(",") + 1);
	d�a = System::Convert::ToInt32(info->Substring(0, info->IndexOf("/")));
	info = info->Remove(0, info->IndexOf("/") + 1);
	mes = System::Convert::ToInt32(info->Substring(0, info->IndexOf("/")));
	info = info->Remove(0, info->IndexOf("/") + 1);
	a�o = System::Convert::ToInt32(info->Substring(0, info->IndexOf(",")));
	info = info->Remove(0, info->IndexOf(",") + 1);
	horaInicio = System::Convert::ToInt32(info->Substring(0, info->IndexOf(":")));
	info = info->Remove(0, info->IndexOf(":") + 1);
	minutosInicio = System::Convert::ToInt32(info->Substring(0, info->IndexOf(",")));
	info = info->Remove(0, info->IndexOf(",") + 1);
	prioridad = System::Convert::ToInt32(info);
}


Recordatorio::Recordatorio(int ID, System::String^ info, System::DateTime^ fecha, int P)
{
	sig = nullptr;
	ant = nullptr;
	id = ID;
	descripci�n = msclr::interop::marshal_as<std::string>(info);
	a�o = fecha->Year;
	mes = fecha->Month;
	d�a = fecha->Day;
	horaInicio = fecha->Hour;
	minutosInicio = fecha->Minute;
	prioridad = P;
}


Recordatorio::Recordatorio()
{
	sig = nullptr;
	ant = nullptr;
}


Recordatorio::~Recordatorio()
{
}

System::String^ Recordatorio::ToString() const {
	System::String^ texto = "Recordatorio," + System::Convert::ToString(id) + "," + gcnew System::String(descripci�n.c_str()) + ",";
	System::DateTime^ fechaIn = gcnew System::DateTime(a�o, mes, d�a);
	texto += fechaIn->ToString("dd/MM/yyyy") + "," + System::Convert::ToString(horaInicio) + ":" + System::Convert::ToString(minutosInicio) + ",";
	texto += System::Convert::ToString(prioridad) + "\r\n";
	return texto;
}

bool Recordatorio::Mostrar() const {
	if (System::Windows::Forms::MessageBox::Show(ToString() + "�Deseas postponer el recordatorio?", "Recordatorio", System::Windows::Forms::MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes) {
		return true;
	}
	else {
		return false;
	}
}