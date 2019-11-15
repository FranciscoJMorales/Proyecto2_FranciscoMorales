#include "Alarma.h"



Alarma::Alarma(System::String^ info)
{
	sig = nullptr;
	ant = nullptr;
	id = System::Convert::ToInt32(info->Substring(0, info->IndexOf(",")));
	info = info->Remove(0, info->IndexOf(",") + 1);
	descripción = msclr::interop::marshal_as<std::string>(info->Substring(0, info->IndexOf(",")));
	info = info->Remove(0, info->IndexOf(",") + 1);
	día = System::Convert::ToInt32(info->Substring(0, info->IndexOf("/")));
	info = info->Remove(0, info->IndexOf("/") + 1);
	mes = System::Convert::ToInt32(info->Substring(0, info->IndexOf("/")));
	info = info->Remove(0, info->IndexOf("/") + 1);
	año = System::Convert::ToInt32(info->Substring(0, info->IndexOf(",")));
	info = info->Remove(0, info->IndexOf(",") + 1);
	horaInicio = System::Convert::ToInt32(info->Substring(0, info->IndexOf(":")));
	info = info->Remove(0, info->IndexOf(":") + 1);
	minutosInicio = System::Convert::ToInt32(info->Substring(0, info->IndexOf(",")));
	info = info->Remove(0, info->IndexOf(",") + 1);
	prioridad = System::Convert::ToInt32(info);
}


Alarma::Alarma(int ID, System::String^ info, System::DateTime^ fecha, int P)
{
	sig = nullptr;
	ant = nullptr;
	id = ID;
	descripción = msclr::interop::marshal_as<std::string>(info);
	año = fecha->Year;
	mes = fecha->Month;
	día = fecha->Day;
	horaInicio = fecha->Hour;
	minutosInicio = fecha->Minute;
	prioridad = P;
}


Alarma::~Alarma()
{
}

System::String^ Alarma::ToString() const {
	System::String^ texto = "Alarma," + System::Convert::ToString(id) + "," + gcnew System::String(descripción.c_str()) + ",";
	System::DateTime^ fechaIn = gcnew System::DateTime(año, mes, día);
	texto += fechaIn->ToString("dd/MM/yyyy") + "," + System::Convert::ToString(horaInicio) + ":" + System::Convert::ToString(minutosInicio) + ",";
	texto += System::Convert::ToString(prioridad) + "\r\n";
	return texto;
}