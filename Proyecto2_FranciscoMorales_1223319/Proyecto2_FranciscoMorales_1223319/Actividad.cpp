#include "Actividad.h"



Actividad::Actividad(System::String^ info)
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
	horaFin = System::Convert::ToInt32(info->Substring(0, info->IndexOf(":")));
	info = info->Remove(0, info->IndexOf(":") + 1);
	minutosFin = System::Convert::ToInt32(info->Substring(0, info->IndexOf(",")));
	info = info->Remove(0, info->IndexOf(",") + 1);
	prioridad = System::Convert::ToInt32(info->Substring(0, info->IndexOf(",")));
	info = info->Remove(0, info->IndexOf(",") + 1);
	personas = msclr::interop::marshal_as<std::string>(info->Substring(0, info->IndexOf(",")));
	info = info->Remove(0, info->IndexOf(",") + 1);
	lugar = msclr::interop::marshal_as<std::string>(info->Substring(0, info->IndexOf(",")));
	info = info->Remove(0, info->IndexOf(",") + 1);
	materiales = msclr::interop::marshal_as<std::string>(info);
}

Actividad::Actividad(int ID, System::String^ info, System::DateTime^ fecha, int hF, int minF, int P, System::String^ people, System::String^ place, System::String^ material)
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
	horaFin = hF;
	minutosFin = minF;
	prioridad = P;
	personas = msclr::interop::marshal_as<std::string>(people);
	lugar = msclr::interop::marshal_as<std::string>(place);
	materiales = msclr::interop::marshal_as<std::string>(material);
}


Actividad::~Actividad()
{
}

System::String^ Actividad::ToString() const {
	System::String^ texto = "Actividad," + System::Convert::ToString(id) + "," + gcnew System::String(descripci�n.c_str()) + ",";
	System::DateTime^ fechaIn = gcnew System::DateTime(a�o, mes, d�a);
	texto += fechaIn->ToString("dd/MM/yyyy") + "," + System::Convert::ToString(horaInicio) + ":" + System::Convert::ToString(minutosInicio) + ",";
	texto += System::Convert::ToString(horaFin) + ":" + System::Convert::ToString(minutosFin) + "," + System::Convert::ToString(prioridad) + ",";
	texto += gcnew System::String(personas.c_str()) + "," + gcnew System::String(lugar.c_str()) + "," + gcnew System::String(materiales.c_str()) + "\r\n";
	return texto;
}

bool Actividad::Mostrar() const {
	System::Windows::Forms::MessageBox::Show(ToString(), "Actividad");
	return false;
}